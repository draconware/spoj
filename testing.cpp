#include <bits/stdc++.h>
using namespace std;



int main(){


	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		vector<string> tic(3);
		for(int i=0;i<3;i++)
			cin>>tic[i];
		// cout<<"t is "<<t<<endl;
		// for(int i=0;i<tic.size();i++)
		// 	for(int j=0;j<tic[i].size();j++)
		// 		cout<<""
		int xCount = 0,oCount = 0,X=0,O=0;

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(tic[i][j] == 'X')
					X++;
				else if(tic[i][j] == 'O')
					O++;
				if(i == 0 && j == 0){
					if(tic[0][0] == tic[0][1] && tic[0][0] == tic[0][2]){
						if(tic[0][0] == 'X')
							xCount++;
						else if(tic[0][0] == 'O')
							oCount++;
					}
					if(tic[0][0] == tic[1][0] && tic[0][0] == tic[2][0]){
						if(tic[0][0] == 'X')
							xCount++;
						else if(tic[0][0] == 'O')
							oCount++;
					}
					if(tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2]){
						if(tic[0][0] == 'X')
							xCount++;
						else if(tic[0][0] == 'O')
							oCount++;
					}
				}else if(i == 0 && j==1){
					if(tic[0][1] == tic[1][1] && tic[2][1] == tic[0][1]){
						if(tic[0][1] == 'X')
							xCount++;
						else if(tic[0][1] == 'O')
							oCount++;
					}
				} else if(i == 0 && j==2){
					if(tic[0][2] == tic[1][2] && tic[0][2] == tic[2][2]){
						if(tic[0][2] == 'X')
							xCount++;
						else if(tic[0][2] == 'O')
							oCount++;
					}
					if(tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0]){
						if(tic[0][2] == 'X')
							xCount++;
						else if(tic[0][2] == 'O')
							oCount++;
					}
				} else if( i == 1 && j == 0){
					if(tic[1][0] == tic[1][1] && tic[1][0] == tic[1][2]){
						if(tic[1][0] == 'X')
							xCount++;
						else if(tic[1][0] == 'O')
							oCount++;
				} 
			}else if( i == 2 && j == 0){
					if(tic[2][0] == tic[2][1] && tic[2][0] == tic[2][2]){
						if(tic[2][0] == 'X')
							xCount++;
						else if(tic[2][0] == 'O')
							oCount++;
				} 
			}
		}
	}
		string ans;	
		if(xCount && !oCount){
			if(X == O +1)
				ans = "yes";
			else 
				ans = "no";
		}else if(oCount && !xCount){
			if(X == O)
				ans = "yes";
			else
				ans  = "no";
		}else if(xCount == 0 && oCount == 0 && (X == O || X == O+1)){
			ans = "yes";
		}else{
			ans = "no";	
		}
		cout<<ans<<endl;
	
	}
	return 0;
}