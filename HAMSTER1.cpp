#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PIE 3.14159265

int main(){
    ios_base::sync_with_stdio(false);

    LL t;
    cin>>t;

    while(t--){
        double theta,maxi,v,k1,k2;
        cin>>v>>k1>>k2;
        if(k2==0){
            theta=PIE/4.0;
            maxi=k1*v*v*sin(2.0*theta)/10.0;
        }else if(k1==0){
            theta=PIE/2.0;
            maxi=k2*v*v*sin(theta)*sin(theta)/20.0;
        }else{
            theta=(PIE-atan(4.0*k1/k2))/2.0;
            maxi=(k1*v*v*sin(2.0*theta)/10.0)+(k2*v*v*sin(theta)*sin(theta)/20.0);
        }
        printf("%.3lf %.3lf\n",theta,maxi);
    }
    return 0;
}

