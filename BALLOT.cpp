#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n,k;

int distribution(int x){
    int counting=0;
    if(x == 1){
        return 3;
    }

    for(int i=0;i<v.size();i++){
        if(v[i] / x){
            counting+=(v[i] / x);
            if(v[i] % x){
                counting++;
            }
        }else{
            counting++;
        }
    }
    if(counting>k){
        return 1;
    }else if(counting < k){
        return 2;
    }else{
        return 3;
    }
}

int main(){

    while(1){
        cin>>n>>k;
        if(n == -1){
            return 0;
        }

        int p,x,low = 1,high = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>p;
            v.push_back(p);

            if(high<p){
                high = p;
            }
        }

        while(low<=high){
            int mid = (low+high)/2 ;
            int flag = distribution(mid);
            if(flag == 1){
                low = mid+1;
            }else if(flag == 2){
                x = mid;
                high = mid-1;
            }else{
                x = mid;
                high = mid-1;
            }
        }
        cout<<x<<endl;
        v.clear();
    }
}
