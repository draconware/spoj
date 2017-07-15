#include<bits/stdc++.h>
using namespace std;

#define MAX 1009

char arr[MAX][MAX];
bool mark[MAX][MAX];

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m,sx,sy;
        cin>>m>>n;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j] == '.'){sx=i;sy=j;}
            }
        }
        memset(mark,0,sizeof(mark));
        queue< pair<int,int> > q;
        q.push(make_pair(sx,sy));

        while(!q.empty()){
            pair<int,int> p = q.front();q.pop();
            int x=p.first,y=p.second;
            mark[x][y]=true;
            cout<<x<<","<<y<<"----";
            if(x-1 >=0 && !mark[x-1][y] && arr[x-1][y]=='.'){
                q.push(make_pair(x-1,y));
                sx=x-1;sy=y;
                cout<<x-1<<","<<y<<" ";
            }
            if(x+1 <n && !mark[x+1][y] && arr[x+1][y]=='.'){
                q.push(make_pair(x+1,y));
                sx=x+1;sy=y;
                cout<<x+1<<","<<y<<" ";
            }
            if(y-1>=0 && !mark[x][y-1] && arr[x][y-1]=='.'){
                q.push(make_pair(x,y-1));
                sx=x;sy=y-1;
                cout<<x<<","<<y-1<<" ";
            }
            if(y+1<m && !mark[x][y+1] && arr[x][y+1]=='.'){
                q.push(make_pair(x,y+1));
                sx=x;sy=y+1;
                cout<<x<<","<<y+1<<" ";
            }
            cout<<endl;
        }
        cout<<sx<<","<<sy<<endl;
        memset(mark,0,sizeof(mark));
        queue<pair<pair<int,int> ,int> > q1;
        q1.push(make_pair(make_pair(sx,sy),0));
        int ans=0;

        while(!q1.empty()){
            pair<pair<int,int> ,int> p = q1.front();q1.pop();
            int x=p.first.first,y=p.first.second,w=p.second;

            if(x-1 >=0 && !mark[x-1][y] && arr[x-1][y]=='.'){
                q1.push(make_pair(make_pair(x-1,y),w+1));
                ans = max(ans,w+1);
            }
            if(x+1 <n && !mark[x+1][y] && arr[x+1][y]=='.'){
                q1.push(make_pair(make_pair(x+1,y),w+1));
                ans = max(ans,w+1);
            }
            if(y-1>=0 && !mark[x][y-1] && arr[x][y-1]=='.'){
                q1.push(make_pair(make_pair(x,y-1),w+1));
                ans = max(ans,w+1);
            }
            if(y+1<m && !mark[x][y+1] && arr[x][y+1]=='.'){
                q1.push(make_pair(make_pair(x,y+1),w+1));
                ans = max(ans,w+1);
            }
        }
        cout<<ans<<endl;
    }
}
