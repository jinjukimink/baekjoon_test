#include<iostream>
using namespace std;
int N,L;

int main(){
    cin>>N>>L;
    int m[N][3];
    int d[N];//N=4인데
    int time=0;

    for(int i=0;i<N;i++){//일단 행렬을 채워//0 1 2 3
        for(int j=0;j<3;j++){
            int x;
            cin>>x;
            m[i][j]=x; 
        }
        if(i>=1) d[i]=m[i][0]-m[i-1][0];
    }
    d[0]=m[0][0];

    for(int i=0;i<N;i++){
        cout<<d[i]<<' ';
    }
    cout<<"\n";

    for(int i=0;i<N;i++){
        int distance=d[i];//7,7,1,10
        int r=m[i][1];
        int g=m[i][2];  
        time+=distance;//일단 그 거리까지 가긴 가야 함.
        cout<<"신호등 걸리기 전: "<<time<<' '<<"\n";

        //신호등에 걸렸나 안걸렸나 체크
        if(time<r)
            time+=(r-time);
        else{

            int mod=time%(r+g);
            cout<<mod<<' '<<"\n";

            if(mod<r)//나머지가 r보다 작으면 기다려
                time+=(r-mod);//차 만큼 기다려

        }
        //cout<<time<<' ';
    }
    cout<<"\n";

    cout<<time+(L-m[N-1][0]);
    return 0;
    }



