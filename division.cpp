#include<bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
#define SET 1000000007
#define INV 333333336


ULL power(ULL x){
 ULL y=2,result=1;

 while(x>0){

      if(x&1){
           result=(result*y)%SET ;
           cout<<result<<" ";
      }
      x=x>>1;
      cout<<x<<" ";
      y=(y*y)%SET;
      cout<<y<<" ";
 }

 return result;
}

int main(){
 ios_base::sync_with_stdio(false);
 ULL n;
 while(scanf("%llu", &n) != EOF){
  cout<<n<<endl;
  ULL ans;
  if(n==1){
   printf("1\n");
   continue;
  }
  if(n & 1){
   ans = ((power(n) + 2 )*INV)%SET;
  }
  else{
   ans = ((power(n) + 1 )*INV)%SET;
  }
  printf("%llu\n",ans);
 }
 return 0;
}
