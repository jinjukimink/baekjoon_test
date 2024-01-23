#include<iostream>
using namespace std;


int main(){
    
    int n,s;
    cin>>n>>s;
    int a[21];


    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    int ans=0;
    for(int i=1;i<(1<<n);i++){//공집합 제외//모든 부분 수열을 만든 것
        int sum=0;
        for(int k=0;k<n;k++){
            if(i &(1<<k)){//만약에 집합 i에 k가 포함되어 있다면
                sum+=a[k];
            }
        }
        if(sum==s){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;

}