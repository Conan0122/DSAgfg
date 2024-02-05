// T.C = O(n)
// S.C = O(1)
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node* newdata = new Node(data);
        // If head is NULL then just create a new node and make it CLL and return it.
        if (!head){
            newdata->next = newdata;
            return newdata;
        }
        
        Node* curr = head;
        Node* prev = head;
        // Point prev to last data(which points to head) in CLL.
        while (prev->next!=head){
            prev = prev->next;
        }
        
        do {
            if (curr->data >= data){
                prev->next = newdata;
                newdata->next = curr;
                // In case we have inserted node before head then make it head.
                if (curr==head) head = prev->next;
                break;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }while (curr!=head);
        // IF the given data is greater than every element in CLL then we need to insert it before head(which will be basically at last node in CLL).
        if (curr==head){
            prev->next = newdata;
            newdata->next = curr;
        }
        return head;
    }
};
