//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
  public:
    class Sum
    {
      public :Sum()
              {
                _sum += _i;
                _i++;

              }

    };
    int Sum_Solution(int n) {
      _i = 1;
      _sum = 0;
      Sum array[n];
      return _sum;

    }
    static size_t _sum;
    static size_t _i;

};
size_t Solution::_sum = 0;
size_t Solution::_i = 0;
