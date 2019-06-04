#include <iostream>

using namespace std;

int main()
{
  int year, month, day;
  int days = 0;
  while (cin >> year >> month >> day)
  {
    int monthArray1[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
    int monthArray2[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
      for (int i = month - 1; i >0; i--)
      {
        days += monthArray2[i];

      }
      days += day;

    }
    else
    {
      for (int i = month - 1; i>0; i--)
      {
        days += monthArray1[i];

      }
      days += day;

    }
    cout << days << endl;
    days = 0;

  }
  return 0;

}
