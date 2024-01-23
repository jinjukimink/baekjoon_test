#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int M,N;

struct Tomato{
    int x,y, days;
};//구조체 선언

int howManyDaysToRipen(vector<vector<int>> & tomatoes){
    int rows=tomatoes.size();//행
    int cols=tomatoes[0].size();//열
    int minimum_days=0;

    vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};

    auto isValid=[&](int x,int y){
        return x>=0 && x<rows && y>=0 && y<cols;
    };//이거 추가하니깐 segment fault 안남//!!!

    queue<Tomato>q;
    for(int i=0;i < rows ; i++){
        for(int j=0 ; j<cols ; j++){
            if(tomatoes[i][j] == 1){
                q.push({i,j,0});
            }
        }
    }//익은 토마토 큐에 푸시


    while(!q.empty()){
        Tomato current=q.front();
        q.pop();

        for(const auto & dir :directions){//direction 배열 순회할거임//인접한 거 체크
            int nx=current.x+dir.first;
            int ny=current.y+dir.second;

            if(isValid(nx,ny) && tomatoes[nx][ny]==0){
                tomatoes[nx][ny]=1;
                q.push({nx,ny,current.days+1});
                minimum_days=current.days+1;
            }        
        }
    }


    for(const auto & row :tomatoes){//tomatoes 벡터 순회하면서~
        if(find(row.begin(),row.end(),0) != row.end()){
            return -1;
        }
    }//다 돌았는데도 0이 남아있으면 -1반환

    return minimum_days;
}


int main(){

    cin>>M>>N;
    vector<vector<int>>tomatos(N,vector<int>(M));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tomatos[i][j];
        }
    }//일단 박스 입력 받고

    int result=howManyDaysToRipen(tomatos);

    cout<<result<<endl;
    //토마토...익은 토마토가 n개이면 동시에 탐색을 해야하는데 어캄쇼;

return 0;

}