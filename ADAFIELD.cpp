#include<bits/stdc++.h>
using namespace std;

#define LL long long

multiset<LL> x,y,px,py;
multiset<LL>::iterator it1,it2;

int main(){
    ios_base::sync_with_stdio(false);

    LL t,n,m,q;
    scanf("%lld",&t);

    while(t--){
        scanf("%lld %lld %lld", &n, &m, &q);
        x.clear();y.clear();px.clear();py.clear();

        x.insert(0);x.insert(n);px.insert(n);
        y.insert(0);y.insert(m);py.insert(m);

        LL a,b,c,d;
        while(q--){
            scanf("%lld %lld", &a, &b);

            if(a == 0){
                if(x.find(b) != x.end()){
                    printf("%lld\n",(*px.rbegin()) * (*py.rbegin()));
                    continue;
                }
                it1 = x.lower_bound(b);
                it1--;

                it2 = x.upper_bound(b);
                px.erase(px.find(*it2 - *it1));

                px.insert(*it2 - b);
                px.insert(b - *it1);
                x.insert(b);
            }else{
                if(y.find(b) != y.end()){
                    //cout<<(*py.rbegin()) * (*px.rbegin())<<endl;
                    printf("%lld\n",(*px.rbegin()) * (*py.rbegin()));
                    continue;
                }
                it1 = y.lower_bound(b);
                it1--;

                it2 = y.upper_bound(b);
                py.erase(py.find(*it2 - *it1));

                py.insert(*it2 - b);
                py.insert(b - *it1);
                y.insert(b);
            }
            //cout<<(*py.rbegin()) * (*px.rbegin())<<endl;
            printf("%lld\n",(*px.rbegin()) * (*py.rbegin()));
        }
    }
    return 0;
}
