#include<bits/stdc++.h>
using namespace std;

bool rem[20009];

int check(string s,int n){
    int c,r = (s[0]-'0');

    for(int i=1;i<s.length();i++){
        c = r*10 + (s[i]-'0');
        r = c - (c/n)*n;
        //cout<<c<<","<<r<<endl;
    }
    return r;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        memset(rem,0,sizeof(rem));
        int n;
        cin>>n;

        string s;
        queue<string> q;
        q.push("1");

        while(!q.empty()){
            s = q.front();q.pop();
            //cout<<s<<endl;
            int r = check(s,n);
            if(r == 0){break;}
            if(rem[r]){continue;}
            rem[r]=true;
            q.push(s+"0");
            q.push(s+"1");
        }
        //if(check("11101",17)){cout<<"YES"<<endl;}
        cout<<s<<endl;
    }
}
