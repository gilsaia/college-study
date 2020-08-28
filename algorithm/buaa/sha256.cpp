#include<cstdio>
using namespace std;
unsigned int delta0(unsigned int x){
    return ((x>>7)|(x<<25))^((x>>18)|(x<<14))^(x>>3);
}
unsigned int delta1(unsigned int x){
    return ((x>>17)|(x<<15))^((x>>19)|(x<<13))^(x>>10);
}
unsigned int ch(unsigned int x,unsigned int y,unsigned int z){
    return (x&y)^((~x)&z);
}
unsigned int maj(unsigned int x,unsigned int y,unsigned int z){
    return (x&y)^(x&z)^(y&z);
}
unsigned int sigma0(unsigned int x){
    return ((x>>2)|(x<<30))^((x>>13)|(x<<19))^((x>>22)|(x<<10));
}
unsigned int sigma1(unsigned int x){
    return ((x>>6)|(x<<26))^((x>>11)|(x<<21))^((x>>25)|(x<<7));
}
unsigned int K[64]={
   0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
unsigned int h[8]={
    0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,
    0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19
};
unsigned int input[64];
unsigned int A,B,C,D,E,F,G,H,M1,M2,L;
int main(){
    input[0]=0x31800000;
    input[15]=0x8;
    for(int i=16;i<64;++i){
        input[i]=delta1(input[i-2])+input[i-7]+delta0(input[i-15])+input[i-16];
    }
    for(int i=0;i<64;++i){
        printf("%d: %.8x\n",i,input[i]);
    }
    A=h[0],B=h[1],C=h[2],D=h[3],E=h[4],F=h[5],G=h[6],H=h[7];

    // //original
    // unsigned int tmp,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6;
    // for(int i=0;i<64;++i){
    //     printf("%d: %x %x %x %x %x %x %x %x\n",i,A,B,C,D,E,F,G,H);
    //     tmp=ch(E,F,G),tmp_2=maj(A,B,C),tmp_3=sigma0(A),tmp_4=sigma1(E);
    //     tmp_5=H+tmp_4+tmp+input[i]+K[i],tmp_6=tmp_3+tmp_2;
    //     H=G,G=F,F=E,E=D+tmp_5,D=C,C=B,B=A,A=tmp_5+tmp_6;
    // }
    
    //1
    M2=input[0]+K[0]+H;
    M1=M2+D;
    printf("1:M1:%x M2:%8x\n",M1,M2);
    //2
    unsigned int tmp=sigma1(E),tmp_2=ch(E,F,G),tmp_3,tmp_4,tmp_M1,tmp_M2,tmp_L;
    tmp_M1=M1;tmp_M2=M2;
    M2=input[1]+K[1]+G;
    M1=M2+C;
    L=tmp_M2+tmp+tmp_2;
    H=G,G=F,F=E,E=tmp_M1+tmp+tmp_2;
    printf("2:L:%x M1:%x M2:%x %x %x %x %x %x %x %x %x\n",L,M1,M2,A,B,C,D,E,F,G,H);
    //3-64
    for(int i=2;i<64;++i){
        tmp=sigma1(E),tmp_2=ch(E,F,G),tmp_3=sigma0(A),tmp_4=maj(A,B,C);
        tmp_L=L,tmp_M1=M1,tmp_M2=M2;
        L=tmp_M2+tmp+tmp_2;
        M2=input[i]+K[i]+G;
        M1=M2+B;
        H=G,G=F,F=E,E=tmp_M1+tmp+tmp_2,D=C,C=B,B=A,A=tmp_L+tmp_3+tmp_4;
        printf("%d:L:%x M1:%x M2:%x %x %x %x %x %x %x %x %x\n",i,L,M1,M2,A,B,C,D,E,F,G,H);
    }
    //65
    tmp=sigma1(E),tmp_2=ch(E,F,G),tmp_3=sigma0(A),tmp_4=maj(A,B,C);
    tmp_L=L;
    L=M2+tmp+tmp_2;
    H=G,G=F,F=E,E=M1+tmp+tmp_2,D=C,C=B,B=A,A=tmp_L+tmp_3+tmp_4;
    //66
    tmp_3=sigma0(A),tmp_4=maj(A,B,C);
    D=C,C=B,B=A,A=L+tmp_3+tmp_4;

    A+=h[0],B+=h[1],C+=h[2],D+=h[3],E+=h[4],F+=h[5],G+=h[6],H+=h[7];
    printf("%x%x%x%x%x%x%x%x\n",A,B,C,D,E,F,G,H);
    return 0;
}