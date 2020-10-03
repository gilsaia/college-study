#include<cstdio>
#include<algorithm>
using namespace std;
int num[2],board[35][35];
int dx[4]={-1,-1,0,1},dy[4]={0,1,1,1};
int main(){
    char tmp[30];
    for(int i=0;i<25;++i){
        scanf("%s",tmp);
        for(int j=0;j<25;++j){
            if(tmp[j]=='o'){
                num[1]++;
                board[i+5][j+5]=-1;
            }else if(tmp[j]=='x'){
                num[0]++;
                board[i+5][j+5]=1;
            }
        }
    }
    int res=0;
    if(num[1]<num[0]){
        for(int i=5;i<30;++i){
            for(int j=5;j<30;++j){
                if(board[i][j]!=0){
                    continue;
                }
                for(int t=0;t<4;++t){
                    int tx=i,ty=j;
                    int linenum=0;
                    while(board[tx+dx[t]][ty+dy[t]]==-1){
                        linenum++;
                        tx+=dx[t],ty+=dy[t];
                    }
                    tx=i,ty=j;
                    while(board[tx-dx[t]][ty-dy[t]]==-1){
                        linenum++;
                        tx-=dx[t],ty-=dy[t];
                    }
                    if(linenum>=4){
                        printf("%d %d\n",i-5,j-5);
                        ++res;
                    }
                }
            }
        }
    }else{
        for(int i=5;i<30;++i){
            for(int j=5;j<30;++j){
                if(board[i][j]!=0){
                    continue;
                }
                for(int t=0;t<4;++t){
                    int tx=i,ty=j;
                    int linenum=0;
                    while(board[tx+dx[t]][ty+dy[t]]==1){
                        linenum++;
                        tx+=dx[t],ty+=dy[t];
                    }
                    tx=i,ty=j;
                    while(board[tx-dx[t]][ty-dy[t]]==1){
                        linenum++;
                        tx-=dx[t],ty-=dy[t];
                    }
                    if(linenum>=4){
                        printf("%d %d\n",i-5,j-5);
                        ++res;
                    }
                }
            }
        }
    }
    if(!res){
        printf("tie\n");
    }
    return 0;
}