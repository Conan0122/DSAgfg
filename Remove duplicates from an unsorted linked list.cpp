// T.C = O(n)
// S.C = O(n)
// Using map. Store each node's data in map/set and then traverse the linked list and check if we counter any data which is in map then remove it from map.
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        if (head->next == NULL) return head;
        
        Node* temp = head;
        Node* prev = NULL;
        unordered_map<int,int>m;
        
        while (temp){
            m[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        while (temp){
            if (m[temp->data]>0){
                prev = temp;
                m[temp->data] = 0;
                temp = temp->next;
            }
            else{
                temp = temp->next;
                prev->next = prev->next->next;
            }
        }
        return head;
    }
};
