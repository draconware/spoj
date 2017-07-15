#include<bits/stdc++.h>
using namespace std;

void construct(int arr[],int s,int e,int *st,int idx){
    if(s == e){
        st[idx] = arr[s];
    }else{
        int m = (s+e)/2;
        construct(arr,s,m,st,2*idx +1);
        construct(arr,m+1,e,st,2*idx +2);

        st[idx] = st[2*idx + 1] + st[2*idx + 2];
    }
}

int interval_sum(int s,int e,int *st,int l,int r,int idx){
    if(s>=l && e<=r){
        cout<<"index is --> "<<idx<<" value is--> "<<st[idx]<<endl;
        return st[idx];
    }

    if((l>e)||(s>r)){
        return 0;
    }

    int m = (s+e)/2;

    int x = interval_sum(0,m,st,l,r,2*idx + 1)+interval_sum(m+1,e,st,l,r,2*idx + 2);
    return x;
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int *st;

    int height = (int)(ceil(log2(n)));
    int max_size = 2*((int)pow(2,height))-1;

    //cout<<max_size<<endl;
    st = (int*)malloc(max_size);
    construct(arr,0,n-1,st,0);
    int l,r;
    cin>>l>>r;

    cout<<interval_sum(0,n-1,st,l,r,0)<<endl;
    return 0;
}
