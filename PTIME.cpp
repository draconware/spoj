#include<bits/stdc++.h>
using namespace std;
#define max 10001
#define LL long long
LL prime[max];
void pre()
{
 LL i,j;
 prime[0]=1;
 prime[1]=1;
 for(i=2;i*i<max;i++)
 {
  for(j=i*i;j<max;j+=i)
  prime[j]=1;
 }
}
int main()
{
 pre();
 LL n,x,y,i,j,p;
 scanf("%lld",&n);
 //LL ans[n+1];
 x=0;   y=n;
 while(y)
 {
  y>>=1;
  x+=y;
 }
 printf("2^%lld ",x);
 for(i=3;i<=n;i+=2)
 {
  if(prime[i]==0)
  {
    j=i;
    p=n;
    x=0;
    while(p)
    {
     p/=j;
     x+=p;
    }
    printf("* %lld^%lld ",i,x);
          }
 }
 return 0;
}
