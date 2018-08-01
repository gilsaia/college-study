//写题的时候voj上提交不了一看poj炸了所以并不知道是不是过了···
//因为数论是真的还没学···基本又是找的题解看的思路···因为这个把循环小数化为分数是真的不知道怎么搞···
//题解的思路大概是这样，因为不确定循环位数所以假定不循环的部分为noloo,循环的部分为loo,然后化为的分数分子为loo-noloo,分母为loo位数个9后配够相应的0即可
//然后就求个最大公约数化简就完了···顺便对比一下哪个大··
#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    string temp;
    while(cin>>temp)
    {
        if(temp.size()==1&&temp[0]=='0')
        {
            break;
        }
        int save[12],point=0,ansup,ansdown=1e9;
        for(int i=2;i<temp.size();i++)
        {
            if(temp[i]=='.')
            {
                break;
            }
            save[point]=temp[i]-'0';
            point++;
        }
        for(int i=0;i<point;i++)
        {
            int noloo=0,loo=0;
            for(int j=0;j<point;j++)
            {
                loo*=10;
                if(j<i)
                {
                    noloo*=10;
                    noloo+=save[j];
                }
                loo+=save[j];
            }
            int up=loo-noloo;
            int down=0;
            for(int j=0;j<(point-i);j++)
            {
                down*=10;
                down+=9;
            }
            for(int j=0;j<i;j++)
            {
                down*=10;
            }
            int temp=gcd(up,down);
            up/=temp;
            down/=temp;
            if(down<ansdown)
            {
                ansup=up;
                ansdown=down;
            }
        }
        cout<<ansup<<"/"<<ansdown<<endl;
    }
    return 0;
}