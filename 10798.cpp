#include<iostream>
#include<cstring>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char mat[5][15]={'\0'};
    int M=0;//행 중에서 가장 긴 거

    for(int i=0;i<5;i++){
        cin>>mat[i];
        if((int)strlen(mat[i])>M) 
            M=(int)strlen(mat[i]);
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<5;j++){
            if(mat[j][i]=='\0') continue;
                cout<<mat[j][i];
        }
    }
    
 return 0;
}