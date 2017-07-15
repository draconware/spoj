#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    LL f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    if(s == g){
        cout<<"0"<<endl;
        return 0;
    }else if((s<g)&&(u==0)){
        cout<<"use the stairs"<<endl;
        return 0;
    }else if((s>g)&&(d==0)){
        cout<<"use the stairs"<<endl;
        return 0;
    }
    bool mark[f+9];
    LL level[f+9];
    for(LL i=0;i<f+9;i++){mark[i]=false;level[i]=0;}
    queue<LL> q;
    q.push(s);
    //mark[s]=true;
    while(!q.empty()){
        LL p = q.front();
        q.pop();
        if(mark[p]){
            continue;
        }
        mark[p]=true;
        if(p+u <= f){
            if(!mark[p+u]){
                level[p+u]=level[p]+1;
                q.push(p+u);
            }
        }
        if(p-d>=1){
            if(!mark[p-d]){
                level[p-d]=level[p]+1;
                q.push(p-d);
            }
        }
    }
    if(!mark[g]){
        cout<<"use the stairs"<<endl;
    }else{
        cout<<level[g]<<endl;
    }
    return 0;
}
