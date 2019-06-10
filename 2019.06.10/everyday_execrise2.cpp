#include <iostream>
#include <string>
using namespace std;

int main()
{
  int array[11] = {0};
  for(int i = 0;i < 10;i++)
  {
    cin >> array[i];
    if(array[i] == 0)
    {
      break;

    }

  }
  for(int i = 0;i < 10;i++)
  {
    array[i] /= 2;
    cout<<array[i]<<endl;
    if(array[i + 1] == 0)
    {
      break;

    }

  }
  return 0;

}
