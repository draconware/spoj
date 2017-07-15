#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL arr[101];
vector<LL> v1,v2;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                v1.push_back(arr[i]*arr[j]+arr[k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[k]==0){
                    continue;
                }
                v2.push_back(arr[k]*(arr[i]+arr[j]));
            }
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    LL res=0,low,high;
    for(LL i=0;i<v1.size();i++){
        low = lower_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
        high = upper_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();

        res+=(high-low);
    }
    cout<<res<<endl;
}
