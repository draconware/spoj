#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF){
        bool mark[8][8];
        memset(mark,0,sizeof(mark));
        int val[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                val[i][j]=INT_MAX;
            }
        }

        multiset< pair<int,pair<int,int> > > q;
        q.insert(make_pair(0,make_pair(a,b)));
        val[a][b]=0;

        while(!q.empty()){
            pair<int,pair<int,int> > p = *q.begin();q.erase(q.begin());
            int x=p.second.first,y=p.second.second,w=p.first;
            //cout<<x<<","<<y<<","<<w<<endl;
            if(x == c && y == d){cout<<val[x][y]<<" "<<endl;break;}
            mark[x][y]=true;
            //cout<<x-1<<","<<y-2<<" "<<x-1<<","<<y+2<<" "<<x+1<<","<<y-2<<" "<<x+1<<","<<y+2<<" ";
            //cout<<x-2<<","<<y-1<<" "<<x-2<<","<<y+1<<" "<<x+2<<","<<y-1<<" "<<x+2<<","<<y+1<<" "<<endl;
            if(x-1>=0 && y-2>=0 && !mark[x-1][y-2]){
                //cout<<"executed1"<<endl;
                if(val[x-1][y-2] > w + (x)*(x-1) + (y)*(y-2)){
                    val[x-1][y-2] = w + (x)*(x-1) + (y)*(y-2);
                    q.insert(make_pair(val[x-1][y-2],make_pair(x-1,y-2)));
                }
            }
            if(x+1<8 && y-2>=0 && !mark[x+1][y-2]){
                //cout<<"executed2"<<endl;
                if(val[x+1][y-2] > w + (x)*(x+1) + (y)*(y-2)){
                    val[x+1][y-2] = w + (x)*(x+1) + (y)*(y-2);
                    q.insert(make_pair(val[x+1][y-2],make_pair(x+1,y-2)));
                }
            }
            if(x-1>=0 && y+2<8 && !mark[x-1][y+2]){
                //cout<<"executed3"<<endl;
                if(val[x-1][y+2] > w + (x)*(x-1) + (y)*(y+2)){
                    val[x-1][y+2] = w + (x)*(x-1) + (y)*(y+2);
                    q.insert(make_pair(val[x-1][y+2],make_pair(x-1,y+2)));
                }
            }
            if(x+1<8 && y+2<8 && !mark[x+1][y+2]){
                //cout<<"executed4"<<endl;
                if(val[x+1][y+2] > w + (x)*(x+1) + (y)*(y+2)){
                    val[x+1][y+2] = w + (x)*(x+1) + (y)*(y+2);
                    q.insert(make_pair(val[x+1][y+2],make_pair(x+1,y+2)));
                }
            }
            if(x-2>=0 && y-1>=0 && !mark[x-2][y-1]){
                //cout<<"executed5"<<endl;
                if(val[x-2][y-1] > w + (x)*(x-2) + (y)*(y-1)){
                    val[x-2][y-1] = w + (x)*(x-2) + (y)*(y-1);
                    q.insert(make_pair(val[x-2][y-1],make_pair(x-2,y-1)));
                }
            }
            if(x-2>=0 && y+1<8 && !mark[x-2][y+1]){
                //cout<<"executed6"<<endl;
                if(val[x-2][y+1] > w + (x)*(x-2) + (y)*(y+1)){
                    val[x-2][y+1] = w + (x)*(x-2) + (y)*(y+1);
                    q.insert(make_pair(val[x-2][y+1],make_pair(x-2,y+1)));
                }
            }
            if(x+2<8 && y-1>=0 && !mark[x+2][y-1]){
                //cout<<"executed7"<<endl;
                if(val[x+2][y-1] > w + (x)*(x+2) + (y)*(y-1)){
                    val[x+2][y-1] = w + (x)*(x+2) + (y)*(y-1);
                    q.insert(make_pair(val[x+2][y-1],make_pair(x+2,y-1)));
                }
            }
            if(x+2<8 && y+1<8 && !mark[x+2][y+1]){
                //cout<<"executed8"<<endl;
                if(val[x+2][y+1] > w + (x)*(x+2) + (y)*(y+1)){
                    val[x+2][y+1] = w + (x)*(x+2) + (y)*(y+1);
                    q.insert(make_pair(val[x+2][y+1],make_pair(x+2,y+1)));
                }
            }
        }
    }
    return 0;
}
