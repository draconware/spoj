#include<bits/stdc++.h>
using namespace std;

vector<int> v;

bool distribution(int m,int k){
    int c;
    if(m == 0){return true;}
    for(int i=0;i < v.size();i++){
        c = v[i];
        k-=(c/m);

        if(k<1){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k,p,high = INT_MIN;
        cin>>n>>k;

        for(int i=0;i<n;i++){
            cin>>p;
            v.push_back(p);

            if(p > high){
                high = p;
            }
        }
        //cout<<"low is --> "<<low<<" high is ---> "<<high<<endl;
        int low = 0,x;
        while(low <= high){
            int mid = (low+high)/2;

            if(distribution(mid,k)){
                //cout<<"at low ---> "<<low<<" and high --> "<<high<<" x is ---> "<<x<<endl;
                x = mid;
                low = mid+1;
            }else{
                //cout<<"execute"<<endl;
                high = mid-1;
            }
        }
        cout<<x<<endl;
        v.clear();
    }
    return 0;
}
