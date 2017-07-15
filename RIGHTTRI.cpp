#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
    int n;
    cin>>n;

    vector<pair<int,int> > v;
    pair<int,int> temp;

    LL no_of_triangles = 0;

    double m,m_,m1;

    for(int i=0;i<n;i++){
        cin>>temp.first>>temp.second;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<"("<<v[i].first<<","<<v[i].second<<")"<<endl;
    }
    int k;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[j].second == v[i].second){
                    k=j+1;

                    while(k<n){
                        if(v[k].first==v[i].first){
                            cout<<"( "<<v[i].first<<","<<v[i].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                            no_of_triangles++;
                        }
                        if(v[k].first==v[j].first){
                            no_of_triangles++;
                            cout<<"( "<<v[j].first<<","<<v[j].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                        }
                        k++;
                    }
                    continue;
            }
            if(v[j].first == v[i].first){
                    k=j+1;

                    while(k<n){
                        if(v[k].second==v[i].second){
                            cout<<"( "<<v[i].first<<","<<v[i].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                            no_of_triangles++;
                        }
                        if(v[k].second==v[j].second){
                            cout<<"( "<<v[j].first<<","<<v[j].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                            no_of_triangles++;
                        }
                        k++;
                    }
                    continue;
            }
            m=((double)(v[j].second - v[i].second)/(double)(v[j].first - v[i].first));
            m_=(-1.0)/m;

            k=j+1;
            while(k<n){
                m1=((double)(v[k].second - v[i].second)/(double)(v[k].first - v[i].first));
                if(m1 == m_){
                    no_of_triangles++;
                    cout<<"( "<<v[i].first<<","<<v[i].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                }
                m1=((double)(v[k].second - v[j].second)/(double)(v[k].first - v[j].first));
                if(m1 == m_){
                    no_of_triangles++;
                    cout<<"( "<<v[j].first<<","<<v[j].second<<") and ( "<<v[k].first<<","<<v[k].second<<")"<<endl;
                }
                k++;
            }
        }
    }
    cout<<no_of_triangles<<endl;
    return 0;
}
