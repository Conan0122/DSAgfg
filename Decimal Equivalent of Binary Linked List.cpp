// T.C = O(n)
// S.C = O(1)
class Solution
{
    public:
        long long unsigned int decimalValue(Node *head)
        {
            int ans=0, mod = 1e9+7;
            Node* temp = head;
            
            while (temp){
                ans = ((2*ans)+temp->data)%mod;
                temp = temp->next;
            }
            return ans;
        }
};
