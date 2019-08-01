#pragma once
#include "ScanManager.h"
#include "Common.h"
#include "DataManager.h"

ScanManager ScanManager::scanmgr;

void ScanManager::Scan(const string& path)
{
	vector<string> localdir;
	vector<string> localfile;
	DirectorList(path, localdir, localfile);

	std::set<string> localset;
	localset.insert(localdir.begin(), localdir.end());
	localset.insert(localfile.begin(), localfile.end());

	std::set<string> dbset;
	DataManager::GetInstance()->GetData(path, dbset);

	vector<string> loacl_in;
	vector<string> loacl_de;

	auto localmod = localset.begin();
	auto dbmod = dbset.begin();

	while (localmod != localset.end() && dbmod != dbset.end())
	{
		if (*localmod < *dbmod) // �����У�����û��->��������
		{
			//��������
			//DataManager::GetInstance()->InsertData(path, *localmod);
			loacl_in.push_back(*localmod);
			++localmod;
		}
		else if (*localmod > *dbmod)// ����û�У�������->ɾ������
		{
			//ɾ������
			//DataManager::GetInstance()->DeleteData(path, *dbmod);
			loacl_de.push_back(*dbmod);
			++dbmod;
		}
		else
		{
			++localmod;
			++dbmod;
		}
	}

	while (localmod != localset.end())
	{
		//��������

		//DataManager::GetInstance()->InsertData(path, *localmod);
		loacl_in.push_back(*localmod);
		++localmod;
	}

	while (dbmod != dbset.end())
	{
		//ɾ������
		//DataManager::GetInstance()->DeleteData(path, *dbmod);
		loacl_de.push_back(*dbmod);
		++dbmod;
	}

	int ret = DataManager::GetInstance()->OpenThing();
	for (auto it : loacl_in)
	{
		DataManager::GetInstance()->InsertData(path, it);
	}
	if (ret == 1)
	{
		DataManager::GetInstance()->CloseThing();
	}
	else
	{
		DataManager::GetInstance()->CallBack();
	}

	int ret1 = DataManager::GetInstance()->OpenThing();
	for (auto it : loacl_de)
	{
		DataManager::GetInstance()->DeleteData(path, it);
	}
	if (ret == 1)
	{
		DataManager::GetInstance()->CloseThing();
	}
	else
	{
		DataManager::GetInstance()->CallBack();
	}
	
	
	//�ݹ�ɨ����Ŀ¼
	for (const auto subdirs : localdir)
	{
		string subpath = path;
		subpath += '\\';
		subpath += subdirs;
		 Scan(subpath);
	}
}
