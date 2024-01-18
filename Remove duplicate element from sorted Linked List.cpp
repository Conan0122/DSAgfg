// T.C = O(n)
// T.C = O(1)
// Since LL is sortedwe know that duplicate data will be adjacent of current nodeif there is, so just check next of current node.
Node *removeDuplicates(Node *head)
{
    Node* temp = head;
    while (temp->next){
        if (temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
