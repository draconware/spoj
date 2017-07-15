#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        string avg;
        cin>>avg;

        int i=avg.find('.');
        if(i<0){
            cout<<"1"<<endl;
        }else{
            int num=0;
            for(int j=i+1;j<avg.size();j++){
                num=num*10+(avg[j]-'0');
            }
            int power=avg.size() - i - 1;
            int count_2=0,count_5=0;

            int k=num,ans=1;
            while(!(k%2)){
                count_2++;
                k/=2;
            }
            while(count_2<power){
                ans*=2;
                count_2++;
            }

            k=num;
            while(!(k%5)){
                count_5++;
                k/=5;
            }
            while(count_5<power){
                ans*=5;
                count_5++;
            }

            cout<<ans<<endl;
        }
    }
    return 0;
}
