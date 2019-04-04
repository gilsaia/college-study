#include<iostream>
#include<complex>
#include<algorithm>
using namespace std;
typedef complex<double> cp;
const double pi=3.1415926;
int n;
int rev[1050];
void fft(cp *a,int inv)
{
    int bit=0;
    while ((1<<bit)<n)bit++;
    for(int i=0;i<n-1;++i)
    {
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        if (i<rev[i])swap(a[i],a[rev[i]]);//不加这条if会交换两次（就是没交换）
    }
    for (int mid=1;mid<n;mid*=2)//mid是准备合并序列的长度的二分之一
    {
    	cp temp(cos(pi/mid),inv*sin(pi/mid));//单位根，pi的系数2已经约掉了
        for (int i=0;i<n;i+=mid*2)//mid*2是准备合并序列的长度，i是合并到了哪一位
		{
            cp omega(1,0);
            for (int j=0;j<mid;j++,omega*=temp)//只扫左半部分，得到右半部分的答案
            {
                cp x=a[i+j],y=omega*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;//这个就是蝴蝶变换什么的
            }
        }
    }
}
double save[1050];
cp tocal[1050];
int main()
{
    int sum,f;
    cin>>sum>>f;
    for(int i=0;i<sum;++i)
    {
        cin>>save[i];
    }
    int num=sum/f;
    n=num;
    for(int i=0;i<num;++i)
    {
        for(int j=0;j<f;++j)
        {
            tocal[j].real(save[i*f+j]);
        }
        fft(tocal,-1);
        for(int j=0;j<f;++j)
        {
            cout<<tocal[j];
        }
    }
    return 0;
}