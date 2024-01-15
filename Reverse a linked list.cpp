// T.C = O(n)
// S.C = O(1)
// Using two pointer
class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node* temp = NULL;
        Node* forward = head->next;
        Node* prev = head;
        head->next = temp;
        
        while (forward != NULL){
            prev = forward;
            forward = forward->next;
            prev->next = head;
            head = prev;
        }   
    return head;
    }
};
