#include<bits/stdc++.h>
using namespace std;

#define MAX 10005

bool mark[MAX];
vector<int> v;

void pre(){
    for(int i=0;i<MAX;i++){
        mark[i]=true;
    }
    for(int i=4;i<MAX;i+=2){
        mark[i]=false;
    }
    for(int i=3;(i*i)<MAX;i+=2){
        if(mark[i] == true){
            for(int j=(i*i);j<MAX;j+=i){
                mark[j]=false;
            }
        }
    }
    for(int i=1000;i<MAX;i++){
    	if(mark[i] == true){
    		v.push_back(i);
    	}
    }
}

int bfs(int a,int b){
    queue< pair<int,int> > q;
    pair<int,int> p;
    set<int> s;

    q.push(make_pair(a,0));
    s.insert(a);

    while(!q.empty()){
        p = q.front();
        if(p.first == b){
            //cout<<"executed1"<<endl;
            s.clear();
            return p.second;
        }
        q.pop();

        int temp = p.first,temp1,temp2,temp3,m=10;
        for(int i=1;i<5;i++){
            temp1=temp/10;
            temp2=temp%10;
            temp3=(p.first)%(m/10);
            //cout<<"temp1 --- "<<temp1<<" temp2 --- "<<temp2<<" temp3 --- "<<temp3<<endl;

            for(int j=0;j<10;j++){
            	if(j == temp2){continue;}
            	if((i == 4)&&(j == 0)){continue;}
                int x = temp1*(m)+j*(m/10)+temp3;
                if((mark[x] == true)){
                   // cout<<"temp1 --- "<<temp1<<" j --- "<<j<<" temp3 --- "<<temp3<<endl;
                    //cout<<"p1 --- "<< temp1*(m) <<" p2 --- "<< j*(m/10) <<" p3 --- "<<temp3<<endl;
                    //cout<<"value is --- "<<x<<" for i--- "<<i<<" and j--- "<<j<<endl;
                    if(s.find(x) == s.end()){
                        s.insert(x);
                        q.push(make_pair(x,p.second + 1));
                        //cout<<x<<","<<p.second + 1<<endl;
                        if(x == b){
                        	s.clear();
                            return (p.second + 1);
                        }
                    }
                }
            }
            temp/=10;
            m*=10;
        }
    }
    s.clear();
    return -1;
}

int main(){
    pre();

    int t,a,b;
    cin>>t;

    while(t--){
        cin>>a>>b;

        int ans = bfs(a,b);
        if(ans == -1){
            cout<<"Impossible"<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
