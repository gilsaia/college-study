#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int test[12][1030];
int main()
{
    for(int i=0;i<1024;++i)
    {
        int n=i,num=0;
        while(n>0)
        {
            if(n&1)
            {
                test[num][i]=1;
            }
            n>>=1;
            num++;
        }
    }
    int T;
    cin>>T;
    for(int m=0;m<T;++m)
    {
        int N,B,F;
        cin>>N>>B>>F;
        int res[12][1030];
        for(int i=0;i<F;++i)
        {
            for(int j=0;j<N;++j)
            {
                cout<<test[i][j];
            }
            cout<<endl;
            string tmp;
            cin>>tmp;
            for(int j=0;j<N-B;++j)
            {
                res[i][j]=tmp[j]-'0';
            }
        }
        vector<int> ans;
        int pos=0;
        for(int i=0;i<N-B;++i)
        {
            bool isnow=false;
            for(int j=0;j<F;++j)
            {
                if(res[j][i]==test[j][pos])
                {
                    continue;
                }
                isnow=true;
                break;
            }
            if(isnow)
            {
                ans.push_back(pos);
                --i;
            }
            pos++;
        }
        while(pos<N)
        {
            ans.push_back(pos);
            pos++;
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();++i)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;
        int tmp;
        cin>>tmp;
    }
    return 0;
}