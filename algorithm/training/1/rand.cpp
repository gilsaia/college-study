#include<iostream>
using namespace std;
int main()
{
    char r,s,r2,s2,r3;
    cin>>r>>s>>r2>>s2>>r3;
    srand(r*s*r2*s2*r2);
    int t=rand()%12;
    switch(t)
    {case 0:cout<<"No Pair"<<endl;break;
     case 1:cout<<"One Pair"<<endl;break;
     case 2:cout<<"Two Pair"<<endl;break;
     case 3:cout<<"Three of a Kind"<<endl;break;
     case 4:cout<<"Straight"<<endl;break;
     case 5:cout<<"Flush"<<endl;break;
     case 6:cout<<"Full House"<<endl;break;
     case 8:cout<<"Four of a Kind"<<endl;break;
     case 9:cout<<"Straight Flush"<<endl;break;
     case 10:cout<<"Five of a Kind"<<endl;break;
     default: cout<<"Royal Straight Flush"<<endl;break;
    }
    return 0;
    
}