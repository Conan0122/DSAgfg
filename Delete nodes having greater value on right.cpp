// T.C = O(n*n)
// S.C = O(1)
// In worst case time complexity of this solution is n*n because curr pointer has to go back to head everytime we find any data greater than curr.
class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node* curr = head;
        
        while (curr->next!=NULL){
            if (curr->data < curr->next->data){
                curr->data = curr->next->data;
                curr->next = curr->next->next;
                curr = head;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

// T.C = O(n)
// S.C = O(1)
// Using reverse we can improve T.C.
// First reverse LL and keep checking if curr data is greater than next node's data,
// IF yes then simply jump curr's next pointer to the next node's next.
// ELSE move curr pointer to next node.
class Solution
{
    void reverse(Node* &head){
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt=head->next;
        
        while (nxt){
            curr->next = prev;
            head = curr;
            prev = head;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        head = curr;
    }
    
    public:
    Node *compute(Node *head)
    {
        reverse(head);
        Node* curr=head;
        while (curr->next){
            if (curr->data > curr->next->data){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        reverse(head);
        return head;
    }
};
