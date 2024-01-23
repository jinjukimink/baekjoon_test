#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int n =20;
    int m;
    scanf("%d",&m);
    int s=0;
    int x;
    char b[111];

    while(m--){
        scanf("%s",b);
        if(!strcmp(b,"add")){
            scanf("%d",&x);
            x-=1;
            s=(s|(1<<x));
        }
        else if(!strcmp(b,"remove")){
            scanf("%d",&x);
            x-=1;
            s=(s & ~(1<<x));
        }
        else if(!strcmp(b,"check")){
            scanf("%d",&x);x-=1;
            int res=(s&(1<<x));
            if(res){
                puts("1");
            }else puts("0");
        }else if(!strcmp(b,"all")){
            s=(1<<n)-1;
        }else if(!strcmp(b,"empty")){
            s=0;
        }

      
    }

}