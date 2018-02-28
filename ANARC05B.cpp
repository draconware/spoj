#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		int m,n1,n2,temp=0;
		cin>>n1;
		if(n1==0){return 0;}
		vector<int> arr1,arr2,sum1,sum2,idx1,idx2;
		for(int i=0;i<n1;i++){
			cin>>m;
			arr1.push_back(m);temp+=arr1[i];
			sum1.push_back(temp);
		}
		cin>>n2;temp=0;
		for(int i=0;i<n2;i++){
			cin>>m;
			arr2.push_back(m);temp+=arr2[i];
			sum2.push_back(temp);
		}
		vector<int>::iterator it;
		for(int i=0;i<arr1.size();i++){
			if(binary_search(arr2.begin(),arr2.end(),arr1[i])){
				idx1.push_back(i);
				idx2.push_back((lower_bound(arr2.begin(),arr2.end(),arr1[i]) - arr2.begin()));
			}
		}
		int size = idx1.size();
		//cout<<"size--- "<<size<<endl;
		if(size == 0){
			cout<<max(sum1[n1-1],sum2[n2-1])<<endl;
		}else{
			int ans=max(sum1[idx1[0]],sum2[idx2[0]]),c=1;
			if(c<size){
				int x1,x2,y1,y2;
				while(c < size){
					x1=idx1[c-1],x2=idx1[c],y1=idx2[c-1],y2=idx2[c];
					ans+=max(sum1[x2]-sum1[x1],sum2[y2]-sum2[y1]);
					c++;
				}
			}
			ans+=max(sum1[n1-1]-sum1[idx1[c-1]] , sum2[n2-1]-sum2[idx2[c-1]]);
			cout<<ans<<endl;
		}
		arr1.clear();arr2.clear();sum1.clear();sum2.clear();idx1.clear();idx2.clear();
	}
	return 0;
}