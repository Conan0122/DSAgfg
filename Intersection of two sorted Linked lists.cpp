// T.C = O(n+m)
// S.C = O(n)
// Using map.
// First store one list's data and their frequencies. Then traverse in second list and check if that data exist in map.
// IF it does exist then we know it's there in first list as well.
class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* temp1 = head1;
        Node* temp2 = head2;
        unordered_map<int,int>m;
        // Insert first linked list's data in map.
        while (temp1) {
            m[temp1->data]++;
            temp1 = temp1->next;
        }
        Node* prev = head2;
        // Traverse in second map and look for data that exist in map as well.
        while (temp2){
            if (m[temp2->data] > 0){
                m[temp2->data]--;
                prev = temp2;
                temp2 = temp2->next;
            }
            else if (temp2==head2){
                temp2 = temp2->next;
                head2 = temp2;
                prev = head2;
            }
            else{
                prev->next = temp2->next;
                temp2 = temp2->next;
            }
        }
        return head2;
    }
};
