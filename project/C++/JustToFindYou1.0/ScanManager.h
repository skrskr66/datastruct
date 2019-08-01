#pragma once
#include "Common.h"
#include "DataManager.h"
//整个程序只有一个扫描模块
class ScanManager
{
public:
	void Scan(const string& path);
	void StartScan()
	{
		while (1)
		{
			Scan("E:");
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	static ScanManager* CreateIntaince()
	{
		static std::thread thd(&ScanManager::StartScan, &scanmgr);
		thd.detach();
		return &scanmgr;
	}
private:
	/*ScanManager()
	{
		DataManager::GetInstance()->Init();
	}*/
	ScanManager() = default;
	static ScanManager scanmgr;
	ScanManager(const ScanManager&);

	//DataManager _datamgr;

	//vector<string> entrys;
};