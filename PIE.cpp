#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846264338327950
vector<double> v;

bool distribution(double m,int k){
    if(m == 0){return true;}

    for(int i=0;i<v.size();i++){
        k-=(int)(v[i]/m);
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
        int n,f;
        double p,x,low=0,high = 0;
        cin>>n>>f;
        f++;

        for(int i=0;i<n;i++){
            cin>>p;
            v.push_back((PI*p*p));

            if( (PI*p*p) > high){
                high = (PI*p*p);
            }
        }

        while(high - low >= 1e-6){
            double mid = (low+high)/2 ;

            if(distribution(mid,f)){
                x = mid;
                low = mid;
            }else{
                high = mid;
            }
        }

        printf("%.4lf\n",low);
        v.clear();
    }
    return 0;
}
