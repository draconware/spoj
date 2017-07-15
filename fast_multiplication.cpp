#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL arr1[100000]={0},arr2[100000]={0},brr1[100000]={0},brr2[100000]={0};

void printall(LL length4){
    for(LL i=length4-1;i>=0;i--){
        cout<<brr2[i];
        arr1[i]=0;
        arr2[i]=0;
        brr1[i]=0;
        brr2[i]=0;
    }
}

void fast_multiply(LL length1,LL length2){
    LL temp,j,length3,length4=0,carry=0,c,k=0;
    for(LL i=0;i<length2;i++){
        for(j=0;j<length1;j++){
            temp = ((arr2[i])*(arr1[j]) + (carry));
            brr1[j] = (temp%10);
            carry = (temp/10);
        }length3=j;
        while(carry){
            brr1[length3] = (carry%10);
            carry/=10;
            length3++;
        }
        for(c=0;((c<length3) || ((c+k)<length4));c++){
            temp = ((brr2[c+k])+(brr1[c])+carry);
            brr2[c+k] = (temp%10);
            carry = (temp/10);
        }length4=(c+k);
        while(carry){
            brr2[length4] = (carry%10);
            carry/=10;
            length4++;
        }
        k++;
        for(i=0;i<length3;i++){
            brr1[i]=0;
        }
    }
    printall(length4);
}

int main(){
    LL t;
    cin>>t;

    while(t--){
        LL a,b;
        cin>>a>>b;
        if(a==0 || b==0){
            cout<<"0"<<endl;
            continue;
        }
        LL i,j;
        LL m=a,n=b;
        for(i=0;m>0;i++){
            arr1[i] = m%10;
            m/=10;
        }
        LL length1 = i;
        for(j=0;n>0;j++){
            arr2[j] = n%10;
            n/=10;
        }
        LL length2 = j;

        fast_multiply(length1,length2);
        cout<<endl;
    }
    return 0;
}
