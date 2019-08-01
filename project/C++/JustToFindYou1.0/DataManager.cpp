#pragma once
#include "Common.h"
#include "DataManager.h"
#define DB_NAME "doc.db"
#define TABLE_NAME "table_doc"

DataManager DataManager::datamgr;

void SqlManager::Open(const string& path)
{
	int ret = sqlite3_open(path.c_str(), &_db);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_open\n");
	}
	else
	{
		TRACE_LOG("sqlite3_open success\n");
	}
}

void SqlManager::Close()
{
	int ret = sqlite3_close(_db);
	_db = nullptr;
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_close\n");
	}
	else
	{
		TRACE_LOG("sqlite3_close success\n");
	}
}

void SqlManager::ExcutedSql(const string &sql)
{
	char *errmsg;
	int ret = sqlite3_exec(_db, sql.c_str(), nullptr, nullptr, &errmsg);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_exec(%s)\n",sql.c_str());
	}
	else
	{
		TRACE_LOG("sqlite3_exec success(%s)\n", sql.c_str());
	}

}

void SqlManager::GetTable(const string &sql, int& row, int& col, char**& pResult)
{
	char *errmsg;
	int ret = sqlite3_get_table(_db, sql.c_str(), &pResult, &row, &col, &errmsg);
	if (ret != SQLITE_OK)
	{
		ERROE_LOG("sqlite3_get_table(%s)\n", sql.c_str());
		sqlite3_free(errmsg);
	}
	else
	{
		TRACE_LOG("sqlite3_get_table success(%s)\n", sql.c_str());
	}
}

int DataManager::OpenThing()
{	

	string sql("begin");
	//std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.ExcutedSql(sql);
	//lock.unlock();
	return 1;
}

void DataManager::CloseThing()
{
	string sql("commit");
	//std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.ExcutedSql(sql);
	//lock.unlock();
}

void DataManager::CallBack()
{
	string sql("rollback");
	//std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.ExcutedSql(sql);
	//lock.unlock();
}

void DataManager::Init()
{
	std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.Open(DB_NAME);
	lock.unlock();
	char sql[1024];
	sprintf(sql, "create table if not exists %s (id INTEGER PRIMARY KEY, path text, doc_name text,doc_name_pinyin text, doc_name_initials text);", TABLE_NAME);
	//std::unique_lock<std::mutex> lock_(_mtx);
	_dbmgr.ExcutedSql(sql);
}

void DataManager::GetData(const string& path, std::set<string>& Data)
{
	char sql[1024];
	sprintf(sql, "select doc_name from %s where path = '%s';", TABLE_NAME, path.c_str());
	int row, col;
	char** pResult;

	std::unique_lock<std::mutex> lock(_mtx);//unique_lock可以主动加锁
	AutoGetTable agtu(_dbmgr, sql, row, col, pResult);
	 lock.unlock();

	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Data.insert(pResult[i*col + j]);
		}
	}
}

void DataManager::InsertData(const string& path,const string& Data)
{
	char sql[1024];
	string pinyin = ChineseConvertPinYinAllSpell(Data);
	string pinyin_init = ChineseConvertPinYinInitials(Data);
	sprintf(sql, "insert into %s (path,doc_name,doc_name_pinyin,doc_name_initials) values('%s','%s','%s','%s');", TABLE_NAME, path.c_str(), Data.c_str(), pinyin.c_str(), pinyin_init.c_str());
	std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.ExcutedSql(sql);
	//lock.unlock();
}

void DataManager::DeleteData(const string& path, const string& Data)
{
	char sql[1024];
	sprintf(sql, "delete from %s where path = '%s' and doc_name = '%s';", TABLE_NAME, path.c_str(), Data.c_str());
	std::unique_lock<std::mutex> lock(_mtx);
	_dbmgr.ExcutedSql(sql);
	//没有删除干净，上面只删除目录中的子文档
	 lock.unlock();
	string path_ = path;
	path_ += "\\";
	path_ += Data;
	sprintf(sql, "delete from %s where path like '%s';", TABLE_NAME, path_.c_str());
	 lock.lock();
	_dbmgr.ExcutedSql(sql);
}

void DataManager::Search(const string& key, vector<std::pair<string, string>>& doc_paths)
{
	char sql[1024] = { '\0' };
	string pinyin = ChineseConvertPinYinAllSpell(key);
	string initials = ChineseConvertPinYinInitials(key);
	sprintf(sql, "select doc_name, path from %s where doc_name_pinyin like '%%%s%%' or doc_name_initials like '%%%s%%';", TABLE_NAME, pinyin.c_str(), initials.c_str());
	int row, col;
	
	char** ppret;
	std::unique_lock<std::mutex> lock(_mtx);
	AutoGetTable agtu(_dbmgr, sql, row, col, ppret);
	lock.unlock();
	int index = col;
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; j += col){
			doc_paths.push_back(std::make_pair(ppret[index], ppret[index + 1]));
			index += col;
		}
	}
	
}

void DataManager::SetHighLight(const string& str, const string& key, string& prefix, string& highlight, string& suffix)
{
	//1.key时原串的子串
	{
		size_t ht_start = str.find(key);
		if (ht_start != string::npos)
		{
			prefix = str.substr(0, ht_start);
			highlight = key;
			suffix = str.substr(ht_start + key.size(), string::npos);
			return;
		}
	}
	//2.key是拼音，高亮对应的汉字
	{
		string key_allspell = ChineseConvertPinYinAllSpell(key);
		string str_allspell = ChineseConvertPinYinAllSpell(str);

		size_t ht_index = 0, ht_start = 0, ht_len = 0;
		size_t allspell_index = 0;
		size_t allspell_start = str_allspell.find(key_allspell);
		size_t allspell_end = allspell_start + key_allspell.size();

		if (allspell_index != string::npos)
		{
			while (allspell_index < allspell_end)
			{
				if (allspell_index == allspell_start)
				{
					ht_start = ht_index;
				}
				if (str[ht_index] >= 0 && str[ht_index] <= 127)
				{
					++ht_index;
					++allspell_index;
				}
				else
				{
					char chinese[3] = { '\0' };
					chinese[0] = str[ht_index];
					chinese[1] = str[ht_index + 1];
					string allspell_str = ChineseConvertPinYinAllSpell(chinese);

					//gbk是两个字符
					ht_index += 2;
					allspell_index += allspell_str.size();
				}
			}
			ht_len = ht_index - ht_start;

			prefix = str.substr(0, ht_start);
			highlight = str.substr(ht_start, ht_len);
			suffix = str.substr(ht_start + ht_len, string::npos);
		}
	}
	//2.key是拼音首字母，高亮对应的汉字
	{
		string Initials_str = ChineseConvertPinYinInitials(str);
		string Initials_key = ChineseConvertPinYinInitials(key);
		size_t Initials_start = Initials_str.find(Initials_key);
		if (Initials_start != string::npos)
		{
			size_t Initials_end = Initials_start + Initials_key.size();
			size_t Initials_index = 0, ht_index = 0;
			size_t ht_start = 0, ht_len = 0;
			while (Initials_index < Initials_end)
			{
				if (Initials_index == Initials_start)
				{
					ht_start = ht_index;
				}
				if (str[ht_index] >= 0 && str[ht_index] <= 127)
				{
					++ht_index;
					++Initials_index;
				}
				else
				{
					//gbk是两个字符
					ht_index += 2;
					++Initials_index;
				}
			}
			ht_len = ht_index - ht_start;
			prefix = str.substr(0, ht_start);
			highlight = str.substr(ht_start, ht_len);
			suffix = str.substr(ht_start + ht_len, string::npos);
			return;
		}
	}
	ERROE_LOG("No HighLight str:%s,key:%s", str.c_str(), key.c_str());
	prefix = str;
}