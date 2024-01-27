// T.C = O(n)
// S.C = O(1)
// My solution: Mark visited node and reverse it back after we got out job done.
// First we multiply each node's data with -ve 1 so that every data is -ve.
// At same time we keep on chekcing if current node's next has -ve data, if it is then we know there exist a loop and current node should be the last node.
// Now as we marked every data as -ve, we have to reverse them back with +ve data so we traverse till we have modified data and again multiply them with -ve again.
class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node* temp = head;
        while (temp->next){
            temp->data = -1 * (temp->data);
            if (temp->next->data < 0 && temp->next){
                temp->data *= -1;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        
        Node* temp2 = head;
        while (temp2!=temp){
            temp2->data = -1 * (temp2->data);
            temp2 = temp2->next;
        }
    }
};
