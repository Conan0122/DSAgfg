// T.C = O(3n)
// S.C = O(n)
// Reverse both LLs and perform addition of same positioned node from both LL with carry.
// Keep adding resultant sum in new LL.
void ReverseLL(Node* &head){
    Node* curr = head;
    Node* nextn = head->next;
    Node* prev = NULL;
    
    while (curr){
        curr->next = prev;
        prev = curr;
        curr = nextn;
        if (nextn!=NULL) nextn = nextn->next;
    }
    head = prev;
}

class Solution
{
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int carry=0, sum=0;
        Node* temp1 = first;
        Node* temp2 = second;
        ReverseLL(temp1);
        ReverseLL(temp2);
        
        Node* head = NULL;
        while (temp1 || temp2){
            int num1=0, num2=0;
            // Check if any LL is NULL at any point (cuz both LL may not be of same length).
            // If any LL is NULL then we dont have anything to add from that LL so we just add default num value (which is 0).
            if (temp1) num1 = temp1->data;
            if (temp2) num2 = temp2->data;
            sum = num1 + num2 + carry;

            // Add last digit of any sum value in new LL and rest of digits in carry variable.
            int lastDigit = sum%10;
            Node* newNode = new Node(lastDigit);
            newNode->next = head;
            head = newNode;
            carry = sum/10;
            // Move forward only if temp->next isn't NULL or else it might give us seg fault error.
            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }
        // After exiting from loop and we still have carry left then we know that we need to add a new Node again as we have extra digit.
        if (carry>0){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
