// T.C = O(n)
// S.C = O(1)
// Just a experimental approach(bad one as we are manipulating LL's data), replace each prev node's data to 0(given data will always be >= 1).
// The moment curr reaches loop point it will detect curr node's data as 0 which means that prev pointer has traversed through that node already SO it has a loop.
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        Node* curr = head;
        Node* prev = head;
        
        while (curr->next!=NULL){
            if (curr->data == 0) return true;
            
            curr = curr->next;
            prev->data = 0;
            prev = curr;
        }
        return false;
    }
};

// T.C = O(n)
// S.C = O(1)
// Two pointer approach:- fast and slow pointer.
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        Node* curr = head;
        Node* prev = head;
        
        while (curr->next!=NULL){
            if (curr->data == 0) return true;
            
            curr = curr->next;
            prev->data = 0;
            prev = curr;
        }
        return false;
    }
};
