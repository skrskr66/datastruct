#pragma once
#include <iostream>
#include <vector>
//ð������(��������)
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


//��������(��������)
int QuickSortPartition(std::vector<int>& arr,int left,int right)
{
	int begin = left;
	int end = right;
	int pivot = arr[begin];//��׼ֵ��beginΪ��׼��֮�Ƚ�
	//(begin,end)��������û�б��ȽϹ�������
	while (begin < end)
	{
		//��׼ֵ�������ߣ���Ҫ���ұ߿�ʼ
		while (begin < end && arr[end] >= pivot)
		{
			end--;
		}
		//arr[end]�Ȼ�׼ֵС��
		//��˫��ֵ��������׼��ʱҲ��������һ��
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
	if (left > right)//���䳤��С��1���Ѿ�����
		return;
	if (left == right)//���䳤�ȵ���1���Ѿ�����
		return;
	//1���һ�׼ֵ��ѡ����ߣ���׼ֵ���±�Ϊlow
	//2�������������䣬��С�ķ��󣬴�ķ��ҡ����ػ�׼ֵ���±�
	int pivotindex = QuickSortPartition(arr, left, right);
	//3�����䱻�ֳ���������
	//[left,pivotindex - 1]С�ڻ�׼
	//[pivotindex,pivotindex]�Ѿ�����
	//[pivotindex + 1,right]���ڻ�׼
	QuickSort(arr, left, pivotindex - 1);
	QuickSort(arr, pivotindex + 1, right);
}


//ֱ�Ӳ�������(��������)
//˵�����Ӻ���ǰ����ȥ���αȽϣ�����ǰ��Сʱ�򽻻�λ��
void StraightInsertionSort(std::vector<int>& arr)
{
	int cur = 0;
	int index_pre = 0;
	for (size_t index = 1;index < arr.size();++index)
	{
		cur = arr[index];//�Ƚ���ǰλ�õ�ֵȡ����

		index_pre = index -  1;//�ӵڶ�����ʼ��������ǰ����бȽ�

		while (index_pre >= 0 && arr[index_pre] > cur)
		{
			arr[index_pre + 1] = arr[index_pre];//��ǰ����ں�ֵ����ô����

			index_pre -= 1;
		}

		arr[index_pre + 1] = cur;
	}
}


//ϣ������(ֱ������)
void ShellSort(std::vector<int>& arr)
{
	int gap = arr.size() / 2;//�趨ϣ������Χ
	while (gap > 0)
	{
		for (size_t i = gap;i < arr.size();++i)
		{
			int index = i;//����ǰ��λ�ñ���
			int cur = arr[i];
			while (index - gap >= 0 && cur < arr[index - gap])
			{
				//���Ƿ�Χ��ǰ������Ƚ�
				//�����ʱgap=2����ô������ܻ����Լ�ǰ��λ�������бȽ�
				//��gap=1ʱ����ô�ȽϾͻ�ÿ�ζ����Լ���ǰһ���Ƚ�����
				arr[index] = arr[index - gap];
				index -= gap;
				arr[index] = cur;
			}
		}
		gap /= 2;
	}
}


//ֱ��ѡ������(ѡ������)
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


//���������(ѡ������)
void Heapify(std::vector<int>& tree, int n, int rootIdx)//�Ƚ�������н���
{
	//n:�ڵ����
	//rootIdx:ѡ��ĳ���ڵ���Ϊ���ڵ�--����ڼ����ڵ�
	int leftIdx = 2 * rootIdx + 1;//����������
	int rightIdx = 2 * rootIdx + 2;//����������
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

//�鲢����
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

	//��extra���������ƻ���
	for (int x = left;x < right;x++)
	{
		arr[x] = extra[x];
	}
}
void Merge(std::vector<int>& arr, int size)
{
	std::vector<int> extra;
	extra.resize(size);
	//i�������������һ��i�������������кϲ�
	for (int i = 1;i < size;i = 2 * i)
	{
		//һ������Ҫ���ٴι鲢
		//j ��ʾ����Ҫ�ϲ��������������������������߽�
		//i ����������ĳ���
		for (int j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			if (mid >= size) {
				// mid Խ�磬˵��û���ұ�һ���������飬����Ҫ�鲢
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
