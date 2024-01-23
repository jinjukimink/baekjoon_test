#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//a안에 부등호가 담겨있음
int n;
char a[20];
bool check[10];//앞에서 선택을 했으면 트루

vector<string>ans;

bool ok(char x, char y,char op){
    if(op =='<'){
        if(x>y) return false;
    }
        
    if(op =='>'){
        if(x<y) return false;
    }
    return true;
}

void go(int index, string num){
    if(index == n+1){
        ans.push_back(num);
        return;
    }

    for(int i=0;i<=9;i++){
        if(check[i]) continue;//앞에서 이미 사용한 숫자이면 건너띄기
        if(index ==0 || ok(num[index-1],i+'0',a[index-1])){
            check[i]=true;

            go(index+1, num+to_string(i));
            
            ==
            if조건//
            for(int j=0;j<=9;j++){
                if(check[j]) continue;
                if(index+1==0|| ok(num[index+1-1],j+'0',a[index+1-1])){
                    check[j]=true;
                    go(index+1+1,num+'i'+'j');







 


                    check[j]=false;
                }
            }
            








            check[i]=false;
        }
    }

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    go(0,"");

    auto p=minmax_element(ans.begin(),ans.end());

    cout<<*p.second<<'\n';
    cout<<*p.first<<'\n';

    return 0;

}