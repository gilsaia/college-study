#include<cstdio>
#include<algorithm>
using namespace std;
// 消消乐思路 对于每个元素 其能否被消去完全取决于它前面的元素个数 因此对于每个元素判断它能够达到的坐标范围即可 若在范围内则可消去元素+1 复杂度O(n)
int main(){
    int n;
    scanf("%d",&n);
    int item;
    int cap=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&item);
        if(item<=i&&item>=(i-cap)){
            ++cap;
        }
    }
    printf("%d\n",cap);
    return 0;
}