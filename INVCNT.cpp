#include<bits/stdc++.h>
using namespace std;

vector<int> arr,a;
long long ans=0;

void merged(int s,int m,int e){
    int i=s,j=m+1,k;
    a.clear();
    while(i<=m && j<=e){
        if(arr[i] < arr[j]){a.push_back(arr[i++]);}
        else if(arr[i]==arr[j]){a.push_back(arr[i++]);a.push_back(arr[j++]);}
        else{
            //cout<<i<<","<<arr[i]<<" "<<j<<","<<arr[j]<<endl;
            ans+=(m-i+1);
            a.push_back(arr[j++]);
        }
    }
    while(i<=m){
        a.push_back(arr[i++]);
    }
    while(j<=e){
        a.push_back(arr[j++]);
    }
    k=0;
    for(int c=s;c<=e;c++){
        arr[c]=a[k++];
    }
}

void merge_sort(int s,int e){
    if(s < e){
        int m = (s+e)/2;
        merge_sort(s,m);
        merge_sort(m+1,e);
        merged(s,m,e);
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        arr.clear();
        int n,x;
        cin>>n;

        for(int i=0;i<n;i++){cin>>x;arr.push_back(x);}
        ans=0;
        merge_sort(0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}
