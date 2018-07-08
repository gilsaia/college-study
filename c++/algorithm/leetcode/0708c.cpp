#include<math.h>
class Solution {
public:
    int primePalindrome(int N) {
        for(int i=N;;i++)
        {
             int wei[10],num=0,M=N;
            while(M>0)
            {
                wei[num]=M%10;
                M/=10;
                num++;
            }
            bool tr=1;
            for(int t=0;t<num/2+1;t++)
            {
                if(wei[t]==wei[num-1-t])
                {
                    continue;
                }
                else
                {
                    tr=0;
                    break;
                }
            }
            if(tr==1)
            {
                bool pan=1;
                for(int t=2;t<=sqrt(i);t++)
                {
                    if(((i/t)*t)==i)
                    {
                        pan=0;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if(pan==1)
                {
                    return i;
                }
            }
        }
    }
};
int main()
{
    Solution a;
    a.primePalindrome(6);
}