#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define SET 100000001

vector<LL> v(SET,0);
vector<LL> v1(SET,0);

void sieve_modified(){
    for(LL i=2;(i*i < SET);i++ ){
        v1[i]=v1[i-1];
        if(v[i] == 0){
            v1[i]++;
            for(LL j=i*i;j<=SET;j+=i){
                v[j]--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    LL n,ans;
    sieve_modified();
    while(1){
        ans=0;
        cin>>n;
        if(n==0){
            break;
        }
        LL a=(LL)sqrt((double)SET);
        if(n < a){
            ans=v1[n];
        }else{
            ans=v1[a];
            for(LL i=a;i<=n;i++){
                if(v[i] == 0){
                    ans++;
                }
            }
        }
        double temp = ((double)ans - ((double)n/log((double)n)));
        temp=((temp>0.0)? temp : (-temp));
        double ans1 = (temp/(double)ans);
        printf("%.1lf\n",ans1);
    }
    return 0;
}
