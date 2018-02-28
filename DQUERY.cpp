#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int> > queries;
int block_size;
int ans;
int cnt[1000009];

int compa(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
	int a = x.first.first/block_size;
	int b = y.first.first/block_size;

	if(a!=b){
		return a<b;
	}else{
		return x.first.second < y.first.second;
	}
}

void add(int x){
	cnt[x]++;
	if(cnt[x] == 1){ans++;}
}

void remove(int x){
	cnt[x]--;
	if(cnt[x] == 0){ans--;}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	memset(cnt,0,sizeof(cnt));
	int n;
	scanf("%d", &n);

	block_size = (int)sqrt((double)n);

	int arr[n];
	for(int i=0;i<n;i++){scanf("%d", &arr[i]);}

	int q;
	scanf("%d", &q);

	for(int i=0;i<q;i++){
		int a,b;scanf("%d", &a);scanf("%d", &b);a--;b--;
		queries.push_back(make_pair(make_pair(a,b),i));
	}

	sort(queries.begin(),queries.end(),compa);

	int mo_left=0,mo_right=-1;ans=0;
	int res[q];

	for(int i=0;i<(int)queries.size();i++){
		int left = queries[i].first.first;
		int right = queries[i].first.second;
		//cout<<left<<" "<<right<<endl;

		while(mo_right < right){
			mo_right++;
			add(arr[mo_right]);
		}

		while(mo_right > right){
			remove(arr[mo_right]);
			mo_right--;
		}

		while(mo_left < left){
			remove(arr[mo_left]);
			mo_left++;
		}

		while(mo_left > left){
			mo_left--;
			add(arr[mo_left]);
		}
		res[queries[i].second] = ans;
		//for(int j=1;j<=5;j++){cout<<cnt[j]<<" ";}cout<<endl;
		//cout<<mo_left<<" "<<mo_right<<endl;
	}
	for(int i=0;i<q;i++){
		printf("%d\n",res[i]);
	}
}