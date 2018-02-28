#include<bits/stdc++.h>
using namespace std;
		
char arr[3][3];

bool check(char temp[3][3],char c){
	for(int i=0;i<3;i++){
		int x=0,y=0;
		for(int j=0;j<3;j++){
			if(temp[i][j]==c){x++;}
			if(temp[j][i]==c){y++;}
		}
		if(x==3 || y==3){return true;}
	}
	if(temp[0][0]==c && temp[1][1]==c && temp[2][2]==c){return true;}
	if(temp[0][2]==c && temp[1][1]==c && temp[2][0]==c){return true;}
	return false;
}

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	while(1){
		string s;
		cin>>s;
		if(s=="end"){return 0;}
		for(int i=0,k=0;i<3;i++){
			for(int j=0;j<3;j++){
				arr[i][j]=s[k++];
			}
		}
		int countx=0,counto=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(arr[i][j]=='X'){countx++;}
				if(arr[i][j]=='O'){counto++;}
			}
		}
		if(counto > countx){cout<<"invalid"<<endl;continue;}
		bool mark[3][3];
		memset(mark,0,sizeof(mark));
		int solx=0,solo=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				char temp[3][3];
				memset(temp,'.',sizeof(temp));
				char c = arr[i][j];
				if(c == '.' || mark[i][j]){continue;}
				queue< pair<int,int> > q;
				q.push(make_pair(i,j));
				while(!q.empty()){
					pair<int,int> p = q.front();q.pop();
					int x = p.first,y = p.second;
					temp[x][y]=c;
					mark[x][y]=true;
					if(x-1>=0 && !mark[x-1][y] && arr[x-1][y]==c){
						q.push(make_pair(x-1,y));
					}
					if(x+1<3 && !mark[x+1][y] && arr[x+1][y]==c){
						q.push(make_pair(x+1,y));
					}
					if(y-1>=0 && !mark[x][y-1] && arr[x][y-1]==c){
						q.push(make_pair(x,y-1));
					}
					if(y+1<3 && !mark[x][y+1] && arr[x][y+1]==c){
						q.push(make_pair(x,y+1));
					}
					if(x-1>=0 && y-1>=0 && !mark[x-1][y-1] && arr[x-1][y-1]==c){
						q.push(make_pair(x-1,y-1));
					}
					if(x-1>=0 && y+1<3 && !mark[x-1][y+1] && arr[x-1][y+1]==c){
						q.push(make_pair(x-1,y+1));
					}
					if(x+1<3 && y-1>=0 && !mark[x+1][y-1] && arr[x+1][y-1]==c){
						q.push(make_pair(x+1,y-1));
					}
					if(x+1<3 && y+1<3 && !mark[x+1][y+1] && arr[x+1][y+1]==c){
						q.push(make_pair(x+1,y+1));
					}
				}
				
				if(c=='X'){
					if(check(temp,c)){
						//cout<<"executed1 "<<i<<","<<j<<endl;
						solx++;
					}
				}else{
					//cout<<"executed2"<<endl;
					if(check(temp,c)){
						solo++;
					}
				}
			}
		}
		if(solo>0 && solx>0){
			cout<<"invalid"<<endl;
		}else if(solo>0){
			if(counto == countx){
				cout<<"valid"<<endl;
			}else{
				cout<<"invalid"<<endl;
			}
		}else if(solx>0){
			if(counto+1==countx){
				cout<<"valid"<<endl;
			}else{
				cout<<"invalid"<<endl;
			}
		}else{
			if(countx-count0 == 1){
				cout<<"valid"<<endl;
			}else{
				cout<<"invalid"<<endl;
			}
		}
	}
	return 0;
}
