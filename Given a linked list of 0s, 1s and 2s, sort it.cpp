// T.C = O(2n)
// S.C = O(1)
// Counting and replacing data.
class Solution
{
    public:
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
///////////////////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// Single traversal of LL and joining links of nodes.
class Solution
{
    public:
    Node* segregate(Node *head) {
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* temp = head;
        // Creating list for 0s, 1s and 2s.
        while (temp){
            if (temp->data == 0){
                zeroTail->next = temp;
                zeroTail = zeroTail->next;
                
            }
            else if (temp->data == 1){
                oneTail->next = temp;
                oneTail = oneTail->next;
            }
            else{
                twoTail->next = temp;
                twoTail = twoTail->next;
            }
            temp = temp->next;
        }
        
        temp = head;
        // Merge
        if (oneHead->next!=NULL){
            zeroTail->next = oneHead->next;
            oneTail->next = twoHead->next;
        }
        else {
            zeroTail->next = twoHead->next;
        }
        twoTail->next = NULL;
        head = zeroHead->next;
    }
};
