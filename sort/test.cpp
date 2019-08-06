#pragma once
#include "bite.h"
#include "SevenSort.h"
void TestBite()
{
	bite Bit1(1024 * 1024 * 1024);

	Bit1.Set(10000);
	Bit1.Set(9527);
	Bit1.Set(3);
	Bit1.Set(2);
	Bit1.Set(1);

	Bit1.Reset(2);

	std::cout << Bit1.Test(10000) << std::endl;
	std::cout << Bit1.Test(9527) << std::endl;
	std::cout << Bit1.Test(3) << std::endl;
	std::cout << Bit1.Test(2) << std::endl;
	std::cout << Bit1.Test(1) << std::endl;
}

void TestBubbleSort()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	BubbleSort(arr);

	for (auto& e : arr)
	{
		std::cout << e <<" ";
	}
	std::cout << std::endl;
}

void TestStraightInsertionSort()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	StraightInsertionSort(arr);
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void TestSelectionSort()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	SelectionSort(arr);
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void TestShellSort()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	ShellSort(arr);
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void TestQuickSort()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	QuickSort(arr,0,arr.size() - 1);
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void TestHeapSort()
{
	std::vector<int> arr{ 10,5,4,1,2,3 };
	HeapSort(arr, arr.size());
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void TestMerge()
{
	std::vector<int> arr{ 3,5,1,-7,4,9,-6,8,10,4 };
	Merge(arr, arr.size());
	for (auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//TestMerge();
	//TestHeapSort();
	//TestQuickSort();
	//TestShellSort();
	//TestSelectionSort();
	TestStraightInsertionSort();
	//TestBubbleSort();
	//TestBite();
	return 0;
}
