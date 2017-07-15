#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    long long t,count=0;
    cin>>t;
    string str;
    deque<int> d;

    while(t--){
        cin>>str;
        int n;

        if(str=="reverse"){
            count++;
            continue;
        }
        if(!(count%2)){
            if(str=="tofront"){
                cin>>n;
                d.push_front(n);
            }
            if(str=="push_back"){
                cin>>n;
                d.push_back(n);
            }
            if(str=="front"){
                cout<<d.front()<<endl;
                d.pop_front();
            }
            if(str=="back"){
                cout<<d.back()<<endl;
                d.pop_back();
            }
        }else{
            if(str=="tofront"){
                cin>>n;
                d.push_back(n);
            }
            if(str=="push_back"){
                cin>>n;
                d.push_front(n);
            }
            if(str=="front"){
                cout<<d.back()<<endl;
                d.pop_back();
            }
            if(str=="back"){
                cout<<d.front()<<endl;
                d.pop_front();
            }
        }
    }
    return 0;
}
