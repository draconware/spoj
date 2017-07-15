#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        double n,low=0;
        cin>>n;
        double high = n;
        for(int i=0;i<80;i++){
            double val,mid = (low+high)/2;

            val = (mid*mid*mid);

            if(val>n){
                high = mid;
            }else{
                low = mid;
            }
        }
        printf("%.4lf\n",floor(low*10000.0)/10000.0);
    }
    return 0;
}
