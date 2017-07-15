#include<bits/stdc++.h>
using namespace std;

int f[21]={0};
int t[21]={0};

void pre(){
    f[1]=1;t[1]=1;
    f[2]=1;

    for(int i=3;i<=20;i++){
        f[i] = f[i-1] + f[i-2];
    }
    for(int i=2;i<=20;i++){
        t[i]+=(t[i-1]+f[i]);
    }
}

int main(){
    pre();

    int r;
    while(1){
        cin>>r;
        if(r == 0){
            return 0;
        }

        int k,p;
        cin>>k>>p;

        int c=t[r-2],d=t[r-1],x=1;
        while((p-(c+1)*x)%d){
            x++;
        }

        int y = (p-(c+1)*x)/d;
        int ans = f[r-2]*x + f[r-1]*y;

        ans*=k;

        cout<<x<<" "<<y<<" "<<ans<<endl;
    }
}
