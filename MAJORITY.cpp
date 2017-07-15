#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MAX 1000001

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        LL n,p;
        scanf("%lld", &n);

        vector<LL> v(MAX,0);
        int flag=0;
        LL value;

        for(LL i=0;i<n;i++){
            scanf("%lld", &p);
            v[p]++;
            if(v[p] > (n/2)){
                flag=1;
                value=p;
            }
        }
        if(flag){
            printf("YES %lld\n",value);
        }else{
            printf("NO\n");
        }
        v.clear();
    }
    return 0;
}
