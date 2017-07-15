#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int t;
    cin>>t;
    vector<int> v[20];
    v[1].push_back(2);v[1].push_back(3);v[1].push_back(5);
    v[2].push_back(1);v[2].push_back(4);v[2].push_back(6);
    v[3].push_back(1);v[3].push_back(1);v[4].push_back(7);
    v[4].push_back(2);v[4].push_back(3);v[4].push_back(8);
    v[5].push_back(1);v[5].push_back(6);v[5].push_back(7);
    v[6].push_back(2);v[6].push_back(5);v[6].push_back(8);
    v[7].push_back(3);v[7].push_back(3);v[5].push_back(8);
    v[8].push_back(4);v[8].push_back(6);v[8].push_back(7);
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        set<int> s1,s2;
        for(int i=0;i<8;i++){
            if(s[i] == '1'){
                if(s[i+8] == '0'){
                    ans++;
                }else{
                    s1.insert(i);
                }
            }else{
                if(s[i+8]=='0'){
                    s2.insert(i);
                }
            }
        }

    }
}
