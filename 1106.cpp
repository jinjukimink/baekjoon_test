#include<iostream>
using namespace std;

int C,N;

int cost[21];
int person[21];
int dp[100001]={0,};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>C>>N;
    for(int i=1;i<=N;i++){
        cin>>cost[i]>>person[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=cost[i];j<=100001;j++){
            dp[j]=max(dp[j],dp[j-cost[i]]+person[i]);//cost[i]를 선택했다면 이전에 계산한 값에 현재 용량의 가치를 더한다.
        }//모든 가능한 용량에 대해서 최대 가치를 계
    }
    
    for(int i=1;i<=100001;i++){
        if(dp[i]>=C){
            cout<<i<<endl;
            break;
        }
    }
    return 0;

}