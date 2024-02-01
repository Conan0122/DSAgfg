// T.C = O(1)
// S.C = O(1)
class twoStacks
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    twoStacks(int n=100)
    {
        arr = new int[n];
        this->size = n;
        top1 = -1;
        top2 = n;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        arr[top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        top2--;
        arr[top2] = x;
    }

    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1!=-1){
            int t = arr[top1];
            top1--;
            return t;
        }
        return -1;
    }

    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2!=size){
            int t = arr[top2];
            top2++;
            return t;
        }
        return -1;
    }
};
