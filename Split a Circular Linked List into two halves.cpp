// T.C = O(n)
// S.C = O(1)
// First get the half of initial CLL. Now just iterate over CLL until we get to half of initial CLL.
// Now point current node's next pointer to initial CLL head, and assign it to first half of CLL.
// And now start iterating from next half node and assign it second head, now until we reach current node's pointing to first half head,
// we keep on iterating our second half CLL.
// The moment we get first half head we assign current node's next pointer to secondhead(which we assigned to second half first node).
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head->next == head){
        *head1_ref = head;
        *head2_ref = head;
        return;
    }
    int len=1, half=0;
  
    // Get length of CLL
    Node* temp = head;
    while (temp->next != head){
        temp = temp->next;
        len++;
    }
    
    // Get half of CLL
    if (len%2==0){
        half = len/2;
    }
    else{
        half = (len/2)+1;
    }
    
    // First half of CLL
    Node* firsthead = head;
    Node* firsttemp = head;
    Node* secondhead = NULL;
    int count=1;
    
    while (firsttemp->next!=firsthead){
        if (count<half){
            firsttemp = firsttemp->next;
            count++;
        }
        else{
            secondhead = firsttemp->next;
            firsttemp->next = firsthead;
        }
    }
    *head1_ref = firsthead;
    
    // Second half of CLL
    Node* secondtemp = secondhead;
    
    while (secondtemp->next!=secondhead){
        if (secondtemp->next == head){
            secondtemp->next = secondhead;
        }
        else{
            secondtemp = secondtemp->next;
        }
    }
    *head2_ref = secondhead;
}
