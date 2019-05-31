#include <iostream>
using namespace std;
int main()
{
  int m,n,count=0,number=0,number1=0;
  while(cin>>n)
  {
    m = n;
    if(n>0){
      for(int i = 0;i < 32;i++)
      {
        if(((n>>i) & 1) == 1)
        {
          count++;
          if(((m >> (i+1)) & 1) == 0)
          {
            if(count > number){
              number = count;
              count = 0;

            }
            else
            {
              count = 0;

            }

          }

        }

      }

    }
    else
    {
      for(int i = 0;i < 32;i++)
      {
        if(((n>>i) & 1) == 1)
        {
          count++;
          if(((m >> (i+1)) & 1) == 0)
          {
            if(count > number){
              number = count;
              count = 0;

            }
            else
            {
              count = 0;

            }

          }
          else
          {
            number1 = count;

          }

        }

      }

    }
    if(n>0){
      cout<<number<<endl;

    }
    else
    {
      cout<<number1<<endl;

    }

  }

}
