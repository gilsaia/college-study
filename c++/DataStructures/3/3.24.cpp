template <typename Object>
class two_stack
{
    public:
    two_stack(int n):size{n},stack1num{0},stack2num{n-1}
    {
        save=new Object[n];
    }
    void push1(Object &x)
    {
        if(stack1num==stack2num)
        {
            throw "fuck!";
        }
        save[stack1num]=x;
        stack1num++;
    }
    void push2(Object &x)
    {
        if(stack1num==stack2num)
        {
            throw "fuck!";
        }
        save[stack2num]=x;
        stack2num--;
    }
    void pop1()
    {
        return save[stack1num--];
    }
    void pop2()
    {
        return save[stack2num++];
    }
    Object top1()
    {
        return save[stack1num];
    }
    Object top2()
    {
        return save[stack2num];
    }
    private:
    Object *save;
    int size,stack1num,stack2num;
}