#include<stdio.h>

struct Point
{
   int x;
   char* y;
} p1;  


int main()
{
    p1.x = 30;
    p1.y = "hello";
    printf(" x = %d  %s\n",p1.x,p1.y);

 /*  struct Point p;  

    p.x = 20;
    printf(" %d \n",p.x);*/
   
}