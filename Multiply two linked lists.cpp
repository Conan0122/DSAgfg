// T.C = O(n)
// S.C = O(1)
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    Node* temp1 = l1;
    Node* temp2 = l2;
    long long mod = 1e9+7;
    long long tot1=0, tot2=0;

    // Get first LL's data as one number.
    // Example:- Make 3->2->1 into a single number that is 321.
    while (temp1){
        tot1 = (tot1*10 + temp1->data)%mod;
        temp1 = temp1->next;
    }
    // Get second LL's data as one number.
    // Example:- Make 1->0->0 into a single number that is 100.
    while (temp2){
        tot2 = (tot2*10 + temp2->data)%mod;
        temp2 = temp2->next;
    }
    // Now multiply both the total results.
    return (tot1*tot2)%mod;
}
