// T.C = O(3n), as we reversing twice which takes o(n) each time and then we do our adding 1 operation which again takes O(n).
// S.C = O(1)
void ReverseLL(Node* &head){
    Node* prev = NULL;
    Node* currn = head;
    Node* nextn = head->next;
    
    while (currn){
        currn->next = prev;
        prev = currn;
        currn = nextn;
        if (nextn) nextn = nextn->next;
    }
    head = prev;
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry=1;
        ReverseLL(head);
        Node* temp = head;
        
        while (temp){
            if (carry==0) break;
            if (carry>0){
                temp->data = (temp->data) + 1;
                
                if ((temp->data) > 9){
                    temp->data = 0;
                }
                else{
                    carry--;
                }
            }
            if (temp->next==NULL && carry==1){
                Node* newNode = new Node(1);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        ReverseLL(head);
        return head;
    }
};
