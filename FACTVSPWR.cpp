#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PI 3.141592653589793238
#define E 2.71828
#define MAX 1000000000000000000

//vector<double> v;
double sum(double n){
    double c=log(n);
    return ((n*c)-n+(0.5*((log(2.0*PI))+c)));
}

void power(double a,double b){
    LL left=(LL)b , right=(LL)(3.0*b);
    double value=log(b);

    while(left < right){
        LL mid = (left+right)/2;
        if(sum((double)mid) > (double)mid*value){
            right=mid;
        }else if(sum((double)mid) < (double)mid*value){
            left=mid+1;
        }
    }
    if(sum((double)left) > (double)left*value){
        cout<<left<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--){
        double n,temp=0.0;
        cin>>n;

        power(log(n),n);
        //v.clear();
    }
    return 0;
}
