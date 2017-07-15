#include<bits/stdc++.h>
using namespace std;

int level[15][15];
bool mark[15][15];
int s1,s2,e1,e2;

void bfs(){
    queue< pair<int,int> > q;
    q.push(make_pair(s1,s2));
	//cout<<"executed"<<endl;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
	//	cout<<"executed"<<endl;
        int x = p.first,y = p.second;
       //cout<<x<<","<<y<<","<<level[x][y]<<endl;
        mark[x][y]=true;
        if(x+2 <= 8 && y+1 <= 8){
        	if(!mark[x+2][y+1]){
            	level[x+2][y+1]=level[x][y]+1;
            	q.push(make_pair(x+2,y+1));
        	}
        }
        if(x+2 <= 8 && y-1 > 0){
        	if(!mark[x+2][y-1]){
    	        level[x+2][y-1]=level[x][y]+1;
	            q.push(make_pair(x+2,y-1));
        	}
        }
        if(x-2 >0 && y+1 <= 8){
            if(!mark[x-2][y+1]){
            	level[x-2][y+1]=level[x][y]+1;
            	q.push(make_pair(x-2,y+1));
            }
        }
        if(x-2 >0 && y-1 > 0){
            if(!mark[x-2][y-1]){
	            level[x-2][y-1]=level[x][y]+1;
    	        q.push(make_pair(x-2,y-1));
            }
        }
        if(y+2 <= 8 && x+1 <= 8){
            if(!mark[y+2][x+1]){
        	  level[x+1][y+2]=level[x][y]+1;
              q.push(make_pair(x+1,y+2));
            }
        }
        if(y+2 <= 8 && x-1 >0){
            if(!mark[x-1][y+2]){
    	      level[x-1][y+2]=level[x][y]+1;
        	    q.push(make_pair(x-1,y+2));
            }
        }
        if(y-2 >0 && x+1 <= 8){
            if(!mark[x+1][y-2]){
            level[x+1][y-2]=level[x][y]+1;
            q.push(make_pair(x+1,y-2));
            }
        }
        if(y-2 >0 && x-1 > 0){
            if(!mark[x-1][y-2]){
            level[x-1][y-2]=level[x][y]+1;
            q.push(make_pair(x-1,y-2));
            }
        }
    }
}

int main(){
    int t;
    cin>>t;

    char c[10];
    while(t--){
        cin>>c;
        s1 = c[0] - 'a';s1++;
        s2 = c[1] - '0';
        cin>>c;
        e1 = c[0] - 'a';e1++;
        e2 = c[1] - '0';
		//cout<<s1<<" "<<s2<<" "<<e1<<" "<<e2<<endl;
		//cout<<level[e1][e2]<<endl;
		for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                level[i][j]=0;
                mark[i][j]=false;
            }
        }
        //cout<<"executed"<<endl;
        bfs();
        //cout<<e1<<","<<e2<<endl;
        cout<<level[e1][e2]<<endl;
    }
    return 0;
}
