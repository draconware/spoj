#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x,y,total=0,best=0;
        cin>>n;

        vector<int> a,b;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(int i=0,j=0;i<n && j<n;){
            if(a[i]<b[j]){
                total++;i++;
            }else{
                total--;j++;
            }
            best = max(best,total);
        }
        cout<<best<<endl;
    }
    return 0;
}
