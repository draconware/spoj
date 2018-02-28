#include<bits/stdc++.h>
using namespace std;

#define MAX 10000001

vector<int> v1,v2;
bool mark[MAX];
void pre(){
	for(int i=0;i<MAX;i++){mark[i]=true;}
	for(int i=2;i*i<MAX;i++){
		if(mark[i]){
			for(int j=i*i;j<MAX;j+=i){
				mark[j]=false;
			}
		}
	}
	for(int i=2;i<MAX;i++){
		if(mark[i]){
			v1.push_back(i);
			v2.push_back(2*i);
		}
	}
	//for(int i=0;i<v1.size();i++){cout<<v1[i]<<" ";}cout<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	pre();
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		vector<int>::iterator it = upper_bound(v1.begin(),v1.end(),n);
		vector<int>::iterator it1 = upper_bound(v2.begin(),v2.end(),n);
		int x = it-v1.begin();
		int y = it1-v2.begin();
		//cout<<x<<" "<<y<<" ";
		printf("%d\n",abs(x-y));
	}
}