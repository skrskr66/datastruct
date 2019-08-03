#pragma once
#include <iostream>
#include <vector>
//ц╟ещеепР
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
//©ЛкыеепР

//ж╠╫с╡ЕхКеепР
void StraightInsertionSort(std::vector<int>& arr)
{

}
//оё╤ШеепР

//╤Ч╡Ф╤я

//╧И╡╒еепР
