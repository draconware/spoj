#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int arr[100009];
long long int dp[100009];

int main(){
	int t,n;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++){cin>>arr[i];}
		memset(dp,0,sizeof(dp));
		for(int i=n-1;i>=0;i--){
			dp[i] = max(arr[i]+dp[i+2],max(arr[i]+arr[i+1]+dp[i+4],arr[i]+arr[i+1]+arr[i+2]+dp[i+6]));
		}
		printf("%lld\n",dp[0]);
	}
	return 0;
}