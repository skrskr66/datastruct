#include <iostream>

using  namespace std;
void Main()
{
  int x=3,y=3;
  switch(x%2)
  {
    case 1:
      switch(y)
      {
        case 0:cout<<"first";
        case 1:cout<<"second";break;
        default:cout<<"hello";
      }
      break;
    case 2:cout<<"third";
  }
}

int main()
{
  Main();
  return 0;
}
