#include<bits/stdc++.h>
using namespace std;

int triangle(int low,int high,int target,int arr[],int n){
    int temp = high,x = high+1;

    while(low <= high){
        int mid = (low+high)/2;

        if(target < arr[mid]){
            x = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return (temp-x+1);
}
int main(){
    ios_base::sync_with_stdio(false);

    while(1){
        int n;
        cin>>n;

        if(n==0){
            break;
        }
        int arr[n];
        vector<pair<int,int> > v;
        pair<int,int> temp;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        for(int i=0;i<n-2;i++){
            temp.first=i;
            for(int j=i+1;j<n-1;j++){
                temp.second=j;
                v.push_back(temp);
            }
        }

        long long count=0;
        //cout<<"size of array is ---> "<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            int m = arr[ v[i].first ] + arr[ v[i].second ];
            //cout<<"target value is --> "<<m<<" low is --> "<<v[i].second + 1<<" high is --> "<<n-1<<endl;
            count+=triangle(v[i].second + 1,n-1,m,arr,n);
            //cout<<"count is ---> "<<count<<endl;
        }
        cout<<count<<endl;
        v.clear();
    }
    return 0;
}
