#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        LL ans = 1;
        int count = 0,j=0;
        for(int i=0;j <= s.length();){
            if(s[i] == s[j]){
                count++;
                j++;
            }else{
                ans *= (LL)pow(2,count-1);
                //cout<<ans<<endl;
                count=0;
                i=j;
            }
        }
        cout<<ans<<endl;
    }
}
