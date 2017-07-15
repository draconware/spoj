#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL m,n;

int check_full(LL x,LL full){
    if(x-full < 0){
        return 1;
    }
    return 0;
}
int check_empty(LL x){
    if(x == 0){
        return 1;
    }
    return 0;
}
LL gcd(LL a,LL b){
    while(a){
        LL temp=a;
        a=(b-(b/a)*a);
        b=temp;
    }
    return b;
}
LL pour(LL x,LL y,LL z){
    LL count1=0;
    while(1){
        if(check_empty(m)){
            count1++;
            m=x;
        }
        if(x>y){
            m-=y;
            n=y;
            count1++;
            if(m == z){
                return count1;
            }
            n=0;
            count1++;
        }
        if(x<y){

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        m=0;n=0;
        LL a,b,c,count1=0,count2=0;
        cin>>a>>b>>c;

        if(c>a && c>b){
            cout<<"-1"<<endl;
            continue;
        }
        if(a==b && a!=c){
            cout<<"-1"<<endl;
            continue;
        }
        if( c%gcd(a,b) != 0){
            cout<<"-1"<<endl;
            continue;
        }
        if(c==a || c==b){
            cout<<"1"<<endl;
            continue;
        }
        if(c>a && c<b){
            LL ans = pour(b,a,c);
        }else if(c<a && c>b){
            LL ans = pour(a,b,c);
        }else{
            LL ans1 = pour(b,a,c);
            LL ans2 = pour(a,b,c);
            LL ans = min(ans1,ans2);
        }
        cout<<ans<<endl;
    }
    return 0;
}

