#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define MAX2 10000
#define NINF -1000000
void magic(vector<int> &result){
  int prime[MAX2];
  int i,j,k=0;
  for(i=0;i<MAX2;i++)
      prime[i]=0;
  for(i=2;i<MAX2;i++){
      if(prime[i]==0){
          for(j=i*2;j<MAX2;j+=i){
              prime[j]+=1;
              if(prime[j]>=3){
              prime[j] = NINF;
                  result.push_back(j);
              }
          }
      }
  }
  sort(result.begin(),result.end());

  //for(int i=0;i<result.size();i++)
  //	printf("%d\n",result[i]);
}

int main(){
   int t;

   vector<int> result;
   magic(result);
   scanf("%d", &t);
   while(t--){
     int n;
     scanf("%d", &n);
     printf("%d\n",result[n-1]);
   }
   return 0;
}
