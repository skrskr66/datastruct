#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define SQR(A) A*A

struct st_task
{
  uint16_t id;
  uint32_t value;
  uint64_t timestamp;
};

void fool()
{
  st_task task = {};
  uint64_t a= 0x00010001;
  memcpy(&task,&a,sizeof(uint64_t));
  printf("%11u,%11u,%11u",task.id,task.value,task.timestamp);
}

int main()
{
  fool();
  //int x =6,y=3,z=2;
  //x/=SQR(y+z)/SQR(y+z);
  //printf("%d",x);
  return 0;
}
