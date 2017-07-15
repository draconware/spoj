#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define SQRE(y) y*y
#define CUBE(w) w*w*w
#define L(m,n) sqrt(SQRE(m) + SQRE(n))

double height,radius;

int value(double x){
    double t=CUBE(x) + (3*SQRE(x)*L(height,radius))/radius - (6*L(height,radius)*SQRE(height))/radius;
    if(t > 0.0)
        return 1;
    if(t < 0.0)
        return -1;
    if(t == 0.0)
        return 0;
}

double binary(double low,double high){
    while(low<=high){
        double mid = low + (high-low)/2 ;
        if(value(mid) == 0 )
            return mid;
        if(value(mid) > 0){
            high=mid-0.0000001;
        }else{
            low=mid+0.0000001;
        }
    }
    if(value(low)==0)
        return height;
    return low;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    while(n--){
        cin>>radius>>height;
        double h = binary((height/sqrt(2)),height);

       	printf("%.6f\n",h);
    }
    return 0;
}
