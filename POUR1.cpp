#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
    while(x!=0){
        int temp=x;
        x=(y%x);
        y=temp;
        //cout<<x<<","<<y<<endl;
    }
    return y;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        if(c>a && c>b){cout<<"-1"<<endl;}
        else if(c%(gcd(a,b)) == 0){
            int x=0,y=0,z=c,l=2;
            int ans1=0,ans2=0,fans;
            while(1){
                //cout<<x<<","<<y<<endl;
                if(x==c || y==c){break;}

                if(x==0){
                    x=a;ans1++;
                }else if(y==b){
                    y=0;ans1++;
                }else{
                    if(x<=(b-y)){
                        y+=x;x=0;ans1++;
                    }else{
                        x-=(b-y);y=b;ans1++;
                    }
                }
            }
            //cout<<"ans--- "<<ans1<<endl;
            x=0,y=0;
            while(1){
                //cout<<x<<","<<y<<endl;
                if(x==c || y==c){break;}

                if(x==0){
                    x=b;ans2++;
                }else if(y==a){
                    y=0;ans2++;
                }else{
                    if(x<=(a-y)){
                        y+=x;x=0;ans2++;
                    }else{
                        x-=(a-y);y=a;ans2++;
                    }
                }
            }

            //cout<<ans1<<","<<ans2<<endl;
            cout<<min(ans1,ans2)<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
