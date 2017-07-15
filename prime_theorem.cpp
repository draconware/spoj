#include<bits/stdc++.h>
using namespace std;

#define MAX 100000005
#define LL long long

bitset<MAX> b;
vector<LL> v;

void sieve(){
    for(LL i=2;(i*i)<MAX;i++){
        if(b[i] == 0){
            for(LL j=(i*i);j<MAX;j+=i){
                b[j] = 1;
            }
        }
    }
    for(LL i=2,m=0;i<b.size();i++){
        if(b[i] == 0){
            v.push_back(i);
            m++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    sieve();

    while(1){
        LL n;
        double ans=0.0;
        cin>>n;
        if(n == 0){
        	return 0;
        }

        for(LL m=0; m<v.size() ;m++){
            if(n >= v[m]){
                ans+=1.0;
            }else{
                break;
            }
        }
        double c=((double)n/log((double)n));
        ans = ((abs(ans-c))/ans)*100 ;
        printf("%.1lf\n",ans);
    }
}

