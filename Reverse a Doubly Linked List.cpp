// T.C = O(n)
// S.C = O(1)
// Using pointer and swap.
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node* left = head;
        Node* right = head;
        
        while (right->next){
            right = right->next;
        }
        
        while (right!=left && right->next!=left){
            swap(right->data, left->data);
            right = right->prev;
            left = left->next;
        }
        return head;
    }
};
/////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// Using single traversal and playing with next and prev node pointers.
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node* prevnode = NULL;
        Node* currnode = head;
        Node* nextnode = currnode->next;
        
        while (currnode){
            currnode->next = prevnode;
            currnode->prev = nextnode;
            prevnode = currnode;
            currnode = nextnode;
            if (nextnode){
                nextnode = nextnode->next;
            }
        }
        head = prevnode;
        return head;
    }
};
