#include<queue>
using std::priority_queue;
priority_queue<int> que;
void push(int x)
{
    que.push(x);
}
int pop()
{
    int tmp=que.top();
    que.pop();
    return tmp;
}