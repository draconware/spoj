#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        LL m,k;
        cin>>m>>k;

        LL p,t=0,arr[m];
        vector<LL> sum(m);
        vector<LL>::iterator it;

        for(LL i=0;i<m;i++){
            cin>>arr[i];
            sum[i]=t+arr[i];
            t=sum[i];
        }

        LL target=(sum[m-1])/k;
        LL c=0,fix=target;

        while(k>1){
            if(target<sum[c]){
                cout<<arr[c]<<" / ";
                c++;
                k--;
                target+=fix;
            }else{
                break;
            }
        }
        while(k>1){
            it=upper_bound(sum.begin(),sum.end(),target);
            LL j=(it-sum.begin());

            for(LL i=c;i<j;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"/";

            c=j;
            k--;
            target+=(fix);
        }
        for(LL i=c;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
