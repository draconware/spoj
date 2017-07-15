#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin>>m;

    int temp=0,sum[m];
    for(int i=0;i<m;i++){
        cin>>sum[i];
        temp+=sum[i];
        sum[i]=temp;
    }

    int a,q;
    cin>>q;
    vector<int> v;temp=0;
    while(q--){
        cin>>a;
        int l,r,x;

        if(a == 1){
            cin>>l>>r;
            int sum1=0,sum2=0;
            if(v.empty()){
                if(l>=2){
                    l-=2;sum1=sum[l];
                }r--;
                sum2=sum[r];
                cout<<(sum2-sum1)<<endl;
            }else{
                int n=v.size();l-=2;r--;
                if((n-1>=l)&&(l>=0)){
                    sum1 = v[n-1];
                    if(n-1 != l)
                        sum1-=v[n-1-l-1];
                }else if(l>=0){
                    sum1=v[n-1]+sum[l-n];
                }
                if(n-1>=r){
                    sum2=v[n-1];
                    if(n-1 != r){
                        sum2-=v[n-1-r-1];
                    }
                }else{
                    sum2=v[n-1]+sum[r-n];
                }
                cout<<(sum2-sum1)<<endl;
            }
        }else{
            cin>>x;
            temp+=x;
            v.push_back(temp);
        }
    }
    return 0;
}
