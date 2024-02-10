// T.C = O(1) for push and O(n) for pop
// S.C = O(1) for push and pop.
int QueueStack :: pop()
{
    if (q1.empty()){
        return -1;
    }
    // Push all the element from q1 to q2 until there is only one ele left in q1 which is back of q1.
    while (q1.size()!=1){
        int f = q1.front();
        q1.pop();
        q2.push(f);
    }
    // Now pop leftover ele from q1 and store it in result variable.
    int f1;
    if (!q1.empty()){
        f1 = q1.front();
        q1.pop();
    }
    // Now push all the elements from q2 back in q1 and pop them all from q2 so that we can perfrom pop operation again in q1.
    while (!q2.empty()){
        int f = q2.front();
        q1.push(f);
        q2.pop();
    }
    return f1;
}
