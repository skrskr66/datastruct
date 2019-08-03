#pragma once
#include <iostream>
#include <vector>

class bite
{
public:
	bite(size_t n)
		:_bit((n >> 3)+1)
	{}
	void Set(size_t n)
	{
		size_t bit_index = n >> 3;
		size_t num = n % 8;

		_bit[bit_index] |= (1 << num);
	}
	void Reset(size_t n)
	{
		size_t bit_index = n >> 3;
		size_t num = n % 8;

		_bit[bit_index] &= ~(1 << num);//如果此时是1，那么相与之后，重置为0
	}
	bool Test(size_t n)
	{
		size_t bit_index = n >> 3;
		size_t num = n % 8;

		return _bit[bit_index] & (1 << num);
	}
private:
	std::vector<char> _bit;
	size_t _bitcount;
};

