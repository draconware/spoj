#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t,n,k,ans=0;
    cin>>n>>k;

    vector<LL> num;
    for(LL i=0;i<n;i++){
        cin>>t;
        num.push_back(t);
    }
    sort(num.begin(),num.end());

    vector<LL>::iterator it,lower1,upper1,lower2,upper2;
    for(it=num.begin();it!=num.end();it++){
        upper1 = upper_bound(num.begin(),num.end(),(*it));
        lower1 = lower_bound(num.begin(),num.end(),(*it));

        LL first = (upper1-lower1);

        upper2 = upper_bound(num.begin(),num.end(),(*it) + k);
        lower2 = lower_bound(num.begin(),num.end(),(*it) + k);

        LL second = (upper2-lower2);

        ans += min(first,second);
    }
    cout<<ans<<endl;

    return 0;
}
