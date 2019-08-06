#pragma once
#include <iostream>
#include <vector>
//冒泡排序(交换排序)
void BubbleSort(std::vector<int>& arr)
{
	for (size_t i = 0;i < arr.size();++i)
	{
		for (size_t j = 0;j < arr.size() - 1 - i;++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j],arr[j + 1]);
			}
		}
	}
}


//快速排序(交换排序)
int QuickSortPartition(std::vector<int>& arr,int left,int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[begin];//基准值，begin为基准与之比较
	//(begin,end)的区间是没有被比较过的数据
	while (begin < end)
	{
		//基准值如果在左边，需要从右边开始
		while (begin < end && arr[end] >= pivot)
		{
			end--;
		}
		//arr[end]比基准值小了
		//将双方值互换，基准此时也更换到另一边
		arr[begin] = arr[end];

		while (begin < end && arr[begin] <= pivot)
		{
			begin++;
		}

		arr[end] = arr[begin];
	}
	arr[begin] = pivot;

	return begin;
}
void QuickSort(std::vector<int>& arr,int left,int right)
{
	if (left > right)//区间长度小于1，已经有序
		return;
	if (left == right)//区间长度等于1，已经有序
		return;
	//1、找基准值，选最左边，基准值的下标为low
	//2、遍历整个区间，把小的放左，大的放右。返回基准值的下标
	int pivotindex = QuickSortPartition(arr, left, right);
	//3、区间被分成了三部分
	//[left,pivotindex - 1]小于基准
	//[pivotindex,pivotindex]已经有序
	//[pivotindex + 1,right]大于基准
	QuickSort(arr, left, pivotindex - 1);
	QuickSort(arr, pivotindex + 1, right);
}


//直接插入排序(插入排序)
//说明：从后往前遍历去依次比较，当比前者小时则交换位置
void StraightInsertionSort(std::vector<int>& arr)
{
	int cur = 0;
	int index_pre = 0;
	for (size_t index = 1;index < arr.size();++index)
	{
		cur = arr[index];//先将当前位置的值取出。

		index_pre = index -  1;//从第二个开始，依次与前面进行比较

		while (index_pre >= 0 && arr[index_pre] > cur)
		{
			arr[index_pre + 1] = arr[index_pre];//当前面大于后值，那么交换

			index_pre -= 1;
		}

		arr[index_pre + 1] = cur;
	}
}


//希尔排序(直接排序)
void ShellSort(std::vector<int>& arr)
{
	int gap = arr.size() / 2;//设定希尔排序范围
	while (gap > 0)
	{
		for (size_t i = gap;i < arr.size();++i)
		{
			int index = i;//将当前的位置保存
			int cur = arr[i];
			while (index - gap >= 0 && cur < arr[index - gap])
			{
				//与标记范围内前面的数比较
				//比如此时gap=2，那么这个数总会与自己前两位的数进行比较
				//当gap=1时，那么比较就会每次都与自己的前一个比较依次
				arr[index] = arr[index - gap];
				index -= gap;
				arr[index] = cur;
			}
		}
		gap /= 2;
	}
}


//直接选择排序(选择排序)
void SelectionSort(std::vector<int>& arr)
{
	for (size_t i = 0;i < arr.size();++i)
	{
		int min_index = i;
		for (size_t j = i + 1;j < arr.size();++j)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		int tmp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = tmp;
	}
}


//二叉堆排序(选择排序)
void Heapify(std::vector<int>& tree, int n, int rootIdx)//先将数组进行建堆
{
	//n:节点个数
	//rootIdx:选择某个节点作为根节点--代表第几个节点
	int leftIdx = 2 * rootIdx + 1;//左子树计算
	int rightIdx = 2 * rootIdx + 2;//右子树计算
	int max = rootIdx;

	if (leftIdx < n && tree[leftIdx] > tree[max])
	{
		max = leftIdx;
	}
	if (rightIdx < n && tree[rightIdx] > tree[max])
	{
		max = rightIdx;
	}
	if (max != n)
	{
		std::swap(tree[max], tree[rootIdx]);
		Heapify(tree, n, max);
	}
}
void BuildHeap(std::vector<int>& tree,int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent;i >= 0;--i)
	{
		Heapify(tree, n, i);
	}
}
void HeapSort(std::vector<int>& tree,int n)
{
	BuildHeap(tree, n);
	for (int i = n - 1;i >= 0;--i)
	{
		std::swap(tree[i], tree[0]);
		Heapify(tree, i, 0);
	}
}

//归并排序
void MergeSort(std::vector<int>& arr,int left,int mid, int right, std::vector<int>& extra)
{
	int i = left;
	int j = mid;
	int k = left;

	while (i < mid && j < right)
	{
		if (arr[i] <= arr[j])
		{
			extra[k++] = arr[i++];
		}
		else
		{
			extra[k++] = arr[j++];
		}
	}

	while (i < mid)
	{
		extra[k++] = arr[i++];
	}
	while (j < right)
	{
		extra[k++] = arr[j++];
	}

	//把extra的数据在移回来
	for (int x = left;x < right;x++)
	{
		arr[x] = extra[x];
	}
}
void Merge(std::vector<int>& arr, int size)
{
	std::vector<int> extra;
	extra.resize(size);
	//i个有序数组和另一个i个有序的数组进行合并
	for (int i = 1;i < size;i = 2 * i)
	{
		//一层里需要多少次归并
		//j 表示的是要合并的两个有序数组的左边数组的左边界
		//i 是有序数组的长度
		for (int j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			if (mid >= size) {
				// mid 越界，说明没有右边一个有序数组，不需要归并
				continue;
			}
			int right = mid + i;
			if (right > size) {
				right = size;
			}
			MergeSort(arr, left, mid, right, extra);
		}
	}
}
