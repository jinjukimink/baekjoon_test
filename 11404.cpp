#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int INF=100001;

//vector<vector<int>>v;
//vector<vector<int>>d;

int n,m;
//int degree[101]{0};


int main(){
    cin>>n>>m;
    vector<vector<int>>d(n+1,vector<int>(n+1,INF));

    while(m--){
        int from, to,income;
        cin>>from>>to>>income;
        d[from][to]=min(d[from][to],income);
    }//v배열 완성


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) {
                d[i][j]=0;
            }

            for(int k=1;k<=n;k++){
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);//직선코스랑 우
                cout<<"d["<<i<<']'<<'['<<j<<"]="<<d[i][j]<<'\n';
            } 
                   
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;

}

