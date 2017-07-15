#include<bits/stdc++.h>
using namespace std;

vector< pair<double,double> > v;
int n;

double func(double x){
    double temp,ans=0;

    for(int i=0;i<v.size();i++){
        temp = sqrt((x - v[i].first)*(x - v[i].first) + (v[i].second)*(v[i].second));
        if(temp > ans){
            ans = temp;
        }
    }

    return ans;
}

int main(){

    while(1){
        cin>>n;

        if(n==0){
            return 0;   //termination//
        }

        pair<double,double> temp;
        int l_temp = INT_MAX, h_temp = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>temp.first;
            cin>>temp.second;

            v.push_back(temp);

            if(temp.first > h_temp){
                h_temp = temp.first;
            }
            if(temp.first < l_temp){
                l_temp = temp.first;
            }
        }

        double l = l_temp;
        double h = h_temp;

        for(int i=0;i<200;i++){
            double r1 = l + (h-l)/3;
            double r2 = l + (h-l)*2/3;

            if(func(r1) > func(r2)){
                l = r1;
            }else if(func(r1) < func(r2)){
                h = r2;
            }else{
                l=r1;h=r2;
            }
        }

        printf("%.9lf %.9lf\n",l,func(l));
        v.clear();
    }
}
