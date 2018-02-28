#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}
	
	queue<int> q;
	int curr=0,best=0; 
	for(int i=0;i<n;i++){
		while(curr+arr[i] > k && !q.empty()){
			curr -= q.front();
			q.pop();
		}
		if(curr+arr[i] <= k){q.push(arr[i]);curr+=arr[i];}
		best = max(best,curr);
	}
	cout<<best<<endl;
}