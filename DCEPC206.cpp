#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL ans=0;

void merge(LL arr[],int s,int m,int e){
	LL l[m-s+1],r[e-m];
	for(int i=0;i<=m-s;i++){l[i]=arr[i+s];}
	for(int i=0;i<e-m;i++){r[i]=arr[i+m+1];}

	int i=0,j=0,k=s;
	while(i<=m-s && j<e-m){
		if(l[i]<r[j]){ans = ans + l[i]*((LL)(e-m-j));arr[k++]=l[i];i++;}
		else{arr[k++] = r[j];j++;}
	}
	while(i<=m-s){
		arr[k++]=l[i];
		i++;
	}
	while(j<e-m){
		arr[k++]=r[j];
		j++;
	}
}

void merge_sort(LL arr[],int s,int e){
	if(s==e){return;}
	int m = (s+e)/2;
	merge_sort(arr,s,m);
	merge_sort(arr,m+1,e);
	merge(arr,s,m,e);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		LL arr[n];

		for(int i=0;i<n;i++){cin>>arr[i];}
		ans=0;
		merge_sort(arr,0,n-1);
		cout<<ans<<endl;
	}
}