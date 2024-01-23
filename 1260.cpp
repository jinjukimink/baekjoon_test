#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
//#include<cstring>


using namespace std;
queue<int>q;
int n;
int m;
vector<int> a[1001];
bool check[1001];

void dfs(int x){//x를 탐색하는 거임(using 인접 리스트)
    check[x]=true;
    cout<<x<<' ';
    for(int i=0;i<n;i++){
        int y=a[x][i];
        if(check[y]==false) {
            dfs(y);
        }
    }
}

void bfs(int f){//넓이 우선 탐색
    check[f]=true;
    q.push(f);
    //cout<<f<<' ';
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<' ';
        for(int i=0;i<a[x].size();i++){
            int next=a[x][i];
            if(check[next]==false){//i를 방문하지 않았으면
                check[next]=true;
                q.push(next);
            }
        }
    } 
}

int main(){
    int f;
    cin>>n>>m>>f;
    for(int i=0;i<m;i++){//간선의 개수 만큼 루프
        int to,from;
        cin>>from>>to;
        a[from].push_back(to);
        a[to].push_back(from);
    }

    for(int i=0;i<n;i++){
        sort(a[i].begin(),a[i].end());
    }

    dfs(f);
    cout<<'\n';

    bfs(f);
    cout<<'\n';


    return 0;
    
}