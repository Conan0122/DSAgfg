// T.C = O(2n)
// S.C = O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zeroCount=0, oneCount=0, twoCount=0;
        Node* temp = head;
        // Traverse the LL and count 0s, 1s and 2s.
        while (temp){
            if (temp->data == 0){
                zeroCount++;
            }
            else if (temp->data == 1){
                oneCount++;
            }
            else{
                twoCount++;
            }
            temp = temp->next;
        }
        // Now keep replacing the data in LL for the counts we received from traversing above, in a sorted order.
        temp = head;
        while (temp){
            if (zeroCount>0){
                temp->data = 0;
                zeroCount--;
            }
            else if (oneCount>0){
                temp->data = 1;
                oneCount--;
            }
            else{
                temp->data = 2;
                twoCount--;
            }
            temp = temp->next;
        }
        return head;
    }
};
