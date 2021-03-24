#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100020];
int lettercount[30];
int letterind[30];
int left(int k){
    int re=0;
    for(int i=0;i<26;++i){
        re+=((k-(lettercount[i]%k))%k);
    }
    return re;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        if(n%k){
            printf("-1\n");
            continue;
        }
        int s_len=strlen(s);
        while(s_len<n){
            s[s_len]='a';
        }
        s[s_len]='\0';
        memset(lettercount,0,sizeof(lettercount));
        for(int i=0;i<s_len;++i){
            lettercount[s[i]-'a']++;
        }
        int rewrite=0;
        while(left(k)==(rewrite%k)){
            ++rewrite;
            lettercount[s[s_len-rewrite]-'a']--;
        } 
        
    }
}