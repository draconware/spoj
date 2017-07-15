#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        cin>>n;

        if(n){
            int p,flag=1;
            deque<int> t;
            stack<int> s;

            for(int i=0;i<n;i++){
                cin>>p;
                t.push_back(p);
            }
            int i=1;
            while(i<=n){
                if(!s.empty()){
                    //cout<<"executed1"<<endl;
                    if(s.top() < i){
                        //cout<<"executed2"<<endl;
                        cout<<"no"<<endl;
                        flag=0;
                        break;
                    }else if(s.top() == i){
                        //cout<<"executed3"<<endl;
                        //cout<<"displayed --> "<<s.top()<<endl;
                        s.pop();
                        i++;
                        continue;
                    }
                }
                if(t.front() == i){
                    //cout<<"executed4"<<endl;
                    //cout<<"displayed --> "<<i<<endl;
                    i++;
                    t.pop_front();
                }else if(t.front() > i){
                    //cout<<"executed5"<<endl;
                    if(!s.empty()){
                      //  cout<<"executed6"<<endl;
                        if(s.top() < t.front()){
                         //   cout<<"executed7"<<endl;
                            cout<<"no"<<endl;
                            flag=0;
                            break;
                        }
                    }
                    //cout<<"executed8"<<endl;
                    s.push(t.front());
                    //cout<<"pushed --> "<<t.front()<<endl;
                    t.pop_front();
                }
            }

            if(flag){
                cout<<"yes"<<endl;
            }
        }else{
            return 0;
        }
    }
}
