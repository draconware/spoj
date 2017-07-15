#include<bits/stdc++.h>
using namespace std;

#define LOOP(x) for(int i=0;i<x;i++)

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int prev[n],curr[n];
        LOOP(n){
            cin>>prev[i];
        }
        LOOP(n){
            cin>>curr[i];
        }

        vector<int> v;
        LOOP(n){
            v.push_back(prev[i] - curr[i]);
        }

        sort(v.begin(),v.end());

        int target = v[ ((n/2) + (n%2) - 1) ];

        int m,ans;
        cin>>m;

        vector<int> grace(m);
        LOOP(m){
            cin>>grace[i];
        }

        sort(grace.begin(),grace.end());

        vector<int>::iterator it = lower_bound(grace.begin(),grace.end(),target);

        if((*it) == target){
            ans = target;
        }else if(it != grace.end()){

            if(it != grace.begin()){
                ans = *(--it);
            }else{
                ans = *(it);

            }
        }else{
            ans = *(--it);
        }

        cout<<ans<<endl;

        v.clear();grace.clear();
    }
    return 0;
}
