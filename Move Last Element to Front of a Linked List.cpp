// T.C = O(n)
// S.C = O(1)
class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        if (head->next == NULL) return head;
        
        while (temp->next){
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = NULL;
        temp->next = head;
        head = temp;
        
        
        return head;
    }
};
