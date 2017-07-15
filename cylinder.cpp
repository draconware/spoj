#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define LL long long
#define PIE 3.1415926535897931159979635

double maximum(double v1,double v2){
    if(v1>=v2){
        return v1;
    }
    return v2;
}

double minimum(double x,double y){
    if(y<=x){
        return y;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    while(1){
        double w,h;
        cin>>w>>h;

        if(w==0 && h==0){
            return 0;
        }else{
            double r1 = w/(2.0*PIE);
            double h1 = h - 2.0*r1;
            double v1 = PIE*r1*r1*h1;
            double x = w/2.0;
            double y = h/(2.0*(PIE+1.0));
            double r2 = minimum(x,y);
            double h2 = w;
            double v2 = PIE*r2*r2*h2;
            double ans = maximum(v1,v2);
            printf("%.3f\n",ans);
         }
    }
}
