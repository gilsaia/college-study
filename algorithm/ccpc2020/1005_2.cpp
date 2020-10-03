#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=10000;
int prime[MAXN+1];
void getPrime(){
  memset(prime,0,sizeof(prime));
  for(int i=2;i<=MAXN;i++){
    if(!prime[i])prime[++prime[0]]=i;
    for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
      prime[prime[j]*i]=1;
      if(i%prime[j]==0)
      break;
    }
  }
}
int fatCnt;
int getFactors(long long x){
  fatCnt=0;
  long long tmp=x;
  for(int i=1;prime[i]<=tmp/prime[i];i++){
    if(tmp%prime[i]==0){
      while(tmp%prime[i]==0){
        tmp/=prime[i];
        fatCnt++;
      }
    }
  }
  if(tmp!=1){
    fatCnt++;
    }
    return fatCnt;
}
int main(){
  int T;
  getPrime();
  scanf("%d",&T);
  int p[17];
  bool win=false;
  
  while(T--){
    int sz=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&p[i]);
      if((p[i]!=2)&&(p[i]%2==0)){
        sz++;
      }
    }
    if(sz!=0){
      sz%2==0?printf("L\n"):printf("W\n");
      continue;
    }
    int k=0;
    for(int i=0;i<n;i++){
      k+=getFactors(p[i]);
    }
    k%2==0?printf("L\n"):printf("W\n");
  }
}
