#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  int a, b, c, d;
  while (cin >> a >> b >> c >> d)
  {
    if ((a<-31 || a>31) || (b<-31 || b>31) || (c<-31 || c>31) || (d<-31 || d>31))
    {
      cout << "No" << endl;
      break;

    }
    if (a <= 0 && b <= 0 && c <= 0 && d <= 0)
    {
      cout << "No" << endl;
      break;

    }

    if (((a)+(c)) % 2 != 0)
    {
      cout << "No" << endl;
      break;

    }
    int A = ((a)+(c)) / 2;    
    if (((b)+(d))% 2 != 0)
    {
      cout << "No" << endl;
      break;

    }
    int B = ((b)+(d)) / 2;
    int C = (b - B) * (-1);
    if (A < 0 || B < 0 || C < 0)
    {
      cout << "No" << endl;
      break;

    }
    cout << A << " " << B << " " << C << endl;

  }
  return 0;

}
