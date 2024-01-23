#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool check[2000][2000];//인접 행렬
vector<int> g[2000];//인접 리스트
vector <pair<int,int>> edges;//간선인 친구관계

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int from, to;
        cin>> from>>to;
        edges.push_back({from,to});
        edges.push_back({to,from});
        check[from][to]=check[to][from]=true;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    m*=2;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int a=edges[i].first;
            int b=edges[i].second;

            int c=edges[j].first;
            int d=edges[j].second;
            if(a==b||a==c||a==d||b==c||b==d||c==d) continue;
            
            if(!check[b][c]) continue;//b->c 친구 관계여야 통과
            
            for(int e : g[d]){
                if(a==e||b==e||c==e||d==e) {continue;}
                cout<<1<<'\n';
                return 0;
            }
        }
    }
//멀끔히 통과하면 친구 관계가 없다는 뜻
    cout<< 0 <<'\n';
    return 0; 
}
