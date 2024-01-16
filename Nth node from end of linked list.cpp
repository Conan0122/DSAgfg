// T.C = O(n)
// S.C = O(1)
// Without single traversal
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node* temp=head;
        int count=1;
        
        while (temp->next != NULL){
            temp = temp->next;
            count++;
        }
        
        if (n>count) return -1;
        int targetNode = count-n;
        Node* nthNode = head;
        while (targetNode>0){
            nthNode = nthNode->next;
            targetNode--;
        }
        return nthNode->data;
    }
};

// T.C = O(n)
// S.C = O(1)
// Single traversal
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node* curr=head;
        Node* prev=head;
        // Start moving prev pointer whenever n gets less than 0.
        // It means that no matter where curr pointer is prev will be at nth node only.
        while (curr!=NULL){
            if (n>0){
                curr=curr->next;
                n--;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        if (n>0) return -1;
        return prev->data;
    }
};
