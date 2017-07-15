#include<bits/stdc++.h>
using namespace std;

#define LL long long
int check(pair<int,int> &temp){
    if((temp.first>0)&&(temp.second>0)){
        return 1;
    }else if((temp.first<0)&&(temp.second>0)){
        return 2;
    }else if((temp.first<0)&&(temp.second<0)){
        return 3;
    }else{
        return 4;
    }
}

int main(){
    LL count=0;
    int n,k;
    cin>>n>>k;

    pair<int,int> queen,temp;

    cin>>queen.first>>queen.second;
    vector<pair<int,int> > obstacles,diagnols;
    vector<int> row,col;

    for(int i=0;i<k;i++){
        cin>>temp.first>>temp.second;
        obstacles.push_back(temp);
    }

    for(int i=0;i<k;i++){
        if(obstacles[i].first  == queen.first){
            row.push_back( (obstacles[i].second - queen.second) );
        }
    }
    for(int i=0;i<k;i++){
        if(obstacles[i].second  == queen.second){
            col.push_back( (obstacles[i].first - queen.first) );
        }
    }
    for(int i=0;i<k;i++){
        if((obstacles[i].first  == queen.first)||(obstacles[i].second  == queen.second)){
            continue;
        }
        if(abs(obstacles[i].first - queen.first) == abs(obstacles[i].second - queen.second)){
            temp.first = obstacles[i].first - queen.first;
            temp.second = obstacles[i].second - queen.second;
            diagnols.push_back(temp);
        }
    }
    int flag1=1,flag2=1,ans2,p=INT_MAX,ans1,q=INT_MIN;
    for(int i=0;i<row.size();i++){
        if(row[i]<0){
            if(q<row[i]){
                q=row[i];
                ans1=row[i]+1;
            }
            flag1=0;
        }else{
            if(p>row[i]){
                p=row[i];
                ans2=row[i]-1;
            }
            flag2=0;
        }
    }
    if(flag2){
        ans2 = n-queen.second;
    }
    if(flag1){
        ans1 = 1-queen.second;
    }
    count+=(abs(ans1)+ans2);
    //cout<<"left rows --> "<<abs(ans1)<<" right rows --> "<<ans2<<" for rows ---> "<<count<<endl;

    flag1=1,flag2=1,ans1,ans2,p=INT_MAX,q=INT_MIN;
    for(int i=0;i<col.size();i++){
        if(col[i]<0){
            if(q<col[i]){
                q=col[i];
                ans1=col[i]+1;
            }
            flag1=0;
        }else{
            if(p>col[i]){
                p=col[i];
                ans2=col[i]-1;
            }
            flag2=0;
        }
    }
    if(flag2){
        ans2 = n-queen.first;
    }
    if(flag1){
        ans1 = 1-queen.first;
    }
    count+=(abs(ans1)+ans2);
    //cout<<"left col --> "<<abs(ans1)<<" right col --> "<<ans2<<" for col ---> "<<count<<endl;
    flag1=1,flag2=1,ans1=INT_MAX,ans2=INT_MAX;
    int flag3=1,flag4=1,ans3=INT_MAX,ans4=INT_MAX;

    for(int i=0;i<diagnols.size();i++){
        int t=check(diagnols[i]);
        if(t==1){
            if(abs(diagnols[i].first)<ans1){
                ans1 = abs(diagnols[i].first) - 1;
            }
            flag1=0;
        }else if(t==2){
            if(abs(diagnols[i].first)<ans2){
                ans2 = abs(diagnols[i].first) - 1;
            }
            flag2=0;
        }else if(t==3){
            if(abs(diagnols[i].first)<ans3){
                ans3 = abs(diagnols[i].first) - 1;
            }
            flag3=0;
        }else{
            if(abs(diagnols[i].first)<ans4){
                ans4 = abs(diagnols[i].first) - 1;
            }
            flag4=0;
        }
    }
    if(flag1){
        ans1=n-max(queen.first,queen.second);
    }
    if(flag2){
        ans2=min( n-queen.second , queen.first -1 );
    }
    if(flag3){
        ans3=min(queen.second,queen.first) - 1;
    }
    if(flag4){
        ans4=min(n - queen.first , queen.second - 1);
    }
    //cout<<"1st quad --> "<<ans1<<" 2nd quad ---> "<<ans2<<" 3rd quad --> "<<ans3<<" 4th quad ---> "<<ans4<<endl;
    count+=(ans1+ans2+ans3+ans4);
    //cout<<"total is ---> "<<count<<endl;

    cout<<count<<endl;
    return 0;
}
