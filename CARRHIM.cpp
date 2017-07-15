#include<bits/stdc++.h>
using namespace std;

int main(){
    char c[10];
    int w,b,r,sumw=0,sumb=0,first,flag=1,r1=0,r2=0,flagwb=0;

    while(scanf("%s",c) != EOF){

        if(c[0] != '#'){
            cin>>w>>b>>r;
            sumw += w;
            if(sumw == 9){flagwb=1;}
            sumb += b;

            if((c[0] == 'A')||(c[0] == 'C')){
                if(flag){
                    first=1;
                }
                if(r!=0){
                    r1=5;
                }
            }else{
                if(flag){
                    first=2;
                }
                if(r!=0){
                    r2=5;
                }
            }
            flag = 0;
        }else{
            if(((sumw == 9)||(sumb == 9))&&((r1!=0)||(r2!=0))){
            	//cout<<"first is --> "<<first<<"and r1 and r2 are --> "<<r1<<" "<<r2<<endl;
                if(first == 1){
                	//cout<<"sumw and flagwb --> "<<sumw<<" "<<flagwb<<endl;
                    if((sumw == 9)&& flagwb){
                        cout<<"Team-1 win and the point is "<<(9-sumb+r1)<<"."<<endl;
                    }else{
                        cout<<"Team-2 win and the point is "<<(9-sumw+r2)<<"."<<endl;
                    }
                }else{
                	//cout<<"sumw and flagwb --> "<<sumb<<" "<<flagwb<<endl;
                    if((sumw == 9)&& flagwb){
                        cout<<"Team-2 win and the point is "<<(9-sumb+r2)<<"."<<endl;
                    }else{
                        cout<<"Team-1 win and the point is "<<(9-sumw+r1)<<"."<<endl;
                    }
                }
            }else{
                cout<<"Incomplete game."<<endl;
            }
            sumw=0;
            sumb=0;
            flag=1;
            r1=0;r2=0;
            flagwb=0;
        }
    }
    return 0;
}
