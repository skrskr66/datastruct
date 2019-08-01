#pragma once
#include "Common.h"

class SqlManager
{
public:
	SqlManager()
		:_db(nullptr)
	{}
	~SqlManager()
	{
		Close();
	}
	void Open(const string &path);//�����ݿ�
	void ExcutedSql(const string &sql);//ִ��sql���
	void GetTable(const string &sql, int& row, int& col, char**& pResult);//�õ���������
	void Close();//�ر����ݿ�
private:
	sqlite3 *_db;
};

//RAII
class AutoGetTable
{
public:
	AutoGetTable(SqlManager& db_obj,const string& sql, int& row, int& col, char**& pResult)
	{
		db_obj.GetTable(sql, row, col, pResult);
		pp_obj = pResult;//ָ���æ�ͷţ�����ַͬʱ���ͷţ���ͨ������
	}
	~AutoGetTable()
	{
		//cout << "�������" << endl;
		sqlite3_free_table(pp_obj);
	}

	AutoGetTable(const AutoGetTable&) = delete;
	AutoGetTable& operator=(const AutoGetTable&) = delete;
private:
	//SqlManager db_obj;
	char** pp_obj;
};

/*���ݹ���ģ��
�����ݽ��й���
*/
class DataManager
{
public:

	static DataManager* GetInstance()
	{
		
		// datamgr.Init();

		return &datamgr;
	}
	void Init();//�������ӣ������ݿ�
	void GetData(const string& path, std::set<string>& Data);//Ѱ��ĳ��Ŀ¼�µ������ļ�
	void InsertData(const string& path, const string& Data);
	void DeleteData(const string& path, const string& Data);
	int OpenThing();
	void CloseThing();
	void CallBack();
	void Search(const string& key, vector<std::pair<string, string>>&doc_paths);
	void SetHighLight(const string& str, const string& key, string& prefix, string& highlight, string& suffix);
private:

	DataManager()
	{}
	static DataManager datamgr;
	SqlManager _dbmgr;
	std::mutex _mtx;
};
