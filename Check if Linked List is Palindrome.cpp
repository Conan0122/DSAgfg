// T.C = O(n)
// S.C = O(1)
// Traversing LL twice and not a better approach than the one which only reverses half of LL and then compare first half with second half.
class Solution{
  public:
    bool isPalindrome(Node *head)
    {
        int num = 0;
        Node* temp = head;
        
        while (temp){
            int digit = (temp->data) % 10;
            num = (num*10) + digit;
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            int last = (num)%10;
            if (temp->data != last) return 0;
            num /=10;
            temp = temp->next;
        }
        return 1;
    }
};
