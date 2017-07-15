#include<bits/stdc++.h>
using namespace std;

int n,m,s1,s2,e1,e2;
char arr[30][30];

bool bfs(){
    queue< pair<int,int> > q;
    q.push(make_pair(s1,s2));
    arr[s1][s2]='#';

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first,y = p.second;

        if(x==e1 && y==e2){
            return true;
        }
        if(x+1<n && y>=0){
            if(arr[x+1][y] == '.'){
                arr[x+1][y] = '#';
                q.push(make_pair(x+1,y));
            }
        }
        if(x-1>=0 && y>=0){
            if(arr[x-1][y] == '.'){
                arr[x-1][y] = '#';
                q.push(make_pair(x-1,y));
            }
        }
        if(x>=0 && y+1<m){
            if(arr[x][y+1] == '.'){
                arr[x][y+1] = '#';
                q.push(make_pair(x,y+1));
            }
        }
        if(x>=0 && y-1>=0){
            if(arr[x][y-1] == '.'){
                arr[x][y-1] = '#';
                q.push(make_pair(x,y-1));
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n>>m;

        int check=0,k=0;
        int x[1000],y[1000];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(arr[i][j] == '.'){
                        check++;
                        x[k++]=i;y[k++]=j;
                    }
                }
            }
        }
        cout<<check<<endl;
        if(check == 2){
            s1=x[0];s2=y[0];
            e1=x[1];e2=y[1];
            if(bfs()){
                cout<<"valid"<<endl;
            }else{
                cout<<"invalid"<<endl;
            }
        }else{
            cout<<"invalid"<<endl;
        }
    }
}
