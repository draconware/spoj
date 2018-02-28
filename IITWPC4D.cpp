#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t,y=0;
	cin>>t;

	while(t--){
		y++;
		int n;
		cin>>n;

		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		set<int> s;
		for(int i=1;i<=n;i++){s.insert(i);}

		bool flag=true;
		int h[n];
		for(int i=n-1;i>=0;i--){
			int x1 = a[i];
			if(s.size() <= x1){flag=false;break;}
			set<int>::reverse_iterator it = s.rbegin();
			int x2 = *it;
			if(x2-x1 <= 0){flag=false;break;}
			set<int>::iterator it1 = upper_bound(s.begin(),s.end(),x2-x1);
			it1--;
			h[i] = *it1;
			s.erase(it1);
		}
		cout<<"Test : "<<y<<endl;
		if(flag){
			for(int i=0;i<n;i++){cout<<h[i]<<" ";}cout<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
}