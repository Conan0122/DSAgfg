// T.C = O(n)
// S.C = O(1)
// Using iterative approach
void Reverse(node* &head, bool changehead){
    node* curr = head;
    node* nxt = head->next;
    node* prev = NULL;
    
    while (curr){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt) nxt = nxt->next;
    }
    if (changehead) head = prev;
}

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    {
        // Keep track of prev group's tail node, current group's head and tail node.
        node* prevtail = head;
        node* currhead = head;
        node* currtail = head;
        node* mainhead = head;
        // To iterate over LL for k group we need current and next node pointer.
        node* curr = head;
        node* nxt = head->next;
        int target = k;
        bool first = true;
        // Now keep on going until current node is NULL.
        while (curr){
            // IF target is >1 then we know we haven't made a group of k nodes.
            // So we keep on moving forward.
            if (target>1){
                target--;
                curr = nxt;
                if(nxt) nxt = nxt->next;
            }
            // ELSE we do our reverse job:
            // first we need to make sure current node points to NULL so that we can reverse the LL of k nodes.
            // Now reverse the LL and we have to pass currhead which points on every curr group's first node.
            // Now if we are reversing a group for the first time then we need our main head(which we will return as head at last) to be assigned to curr resultant tail after reversal ops.
            // Move curr pointer to next node in LL to make other groups.
            // IF our mainhead != currtail (which will be the case when we have already reverse one group and now we're into another group) then point prevtail's next to currtail.
            // This above step will make sure prev group is connected to curr group.
            else{
                curr->next = NULL;
                currtail = curr;
                Reverse(currhead, false);
                if (first){
                    mainhead = currtail;
                    prevtail->next = NULL;
                    first = false;
                }
                curr = nxt;
                if (nxt) nxt = nxt->next;
                if (mainhead!=currtail) prevtail->next = currtail;
                prevtail = currhead;
                currhead = curr;
                target = k;
            }
        }
        // We will be left with target < k if we left out node in LL which aren't of k nodes.
        // And as per the problem we have to consider any left out nodes (<k nodes) to be a separate group.
        // Now reverse the remaining group with a little change.
        // For this we need head of reversed LL which was not in the case when we find a group of k nodes(where we just have to reverse and leave every pointer as it is).
        // But in this case we need new head of LL so that we can point prevtail to new head.
        if (target!=k){
            currtail = currhead;
            Reverse(currhead, true);
            prevtail->next = currhead;
        }
        return mainhead;
    }
};
