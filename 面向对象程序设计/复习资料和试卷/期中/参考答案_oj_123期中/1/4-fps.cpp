
#include<stdio.h>
#include<math.h>
struct m
{
  double x;
  double y;
  double r;
};
int main()
{
  struct m a[101];
  int b;
  scanf("%d",&b);
  for(int i=0;i<b;i++)
    scanf("%lf %lf %lf",&a[i].x,&a[i].y,&a[i].r);
  int c;
  scanf("%d",&c);
  int num=1;
  for(int i=0;i<b;i++)
  {
    if(i!=c)
    {
      double L=sqrt((a[i].x-a[c].x)*(a[i].x-a[c].x)+(a[i].y-a[c].y)*(a[i].y-a[c].y));
      if(L<(a[i].r+a[c].r))
      {
        num=0;
        break;
      }
    }
  }
  if(!num)
    printf("Biu\n");
  else
    printf("Alive\n");
  return 0;
}