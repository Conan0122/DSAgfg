// T.C = O(n)
// S.C = O(n)
// Using map, not efficient at all as we using extra space.
// Just inserting one LL's addresses in map and then traversing through second LL and checking if their is any address that matches in map.
// IF it matches then we know that node is the intersection node.
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map<Node*,int>m;
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while (temp1){
        m[temp1]++;
        temp1 = temp1->next;
    }
    while (temp2){
        if (m[temp2] > 0) return temp2->data;
        temp2 = temp2->next;
    }
    return -1;
}
//////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// In this solution we are changing next addresses of each node to itself in first LL, so it isn't a  good solution if we want to keep the LL safe.
// So first we are simply modifying first LL's each node next pointer to itself.
// Then we are traversing second LL where we keep on checking if at any point we counter a node whose next is itself then we know first LL has traversed it.
// And that is intersecting node.
int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* prevnode = NULL;
    while (temp1->next){
        prevnode = temp1;
        temp1 = temp1->next;
        prevnode->next = prevnode;
    }
    
    while (temp2->next){
        if (temp2->next == temp2) return temp2->data;
        temp2 = temp2->next;
    }
    return -1;
}
//////////////////////////////////////////////////////////////
// T.C = O(n)
// S.C = O(1)
// This solution is efficient and works good.
// First we get the difference between both LL and then we traverse the longer LL untill we make dif = 0.
// Now both LL are in equal length (for e.g: if LL1 has 3->2->1 and LL2 has 6->5->8->9->2->1 then after previous ops we are in LL1 is at 3 but LL2 is at 9).
// And now when difference between their length is 0 we can traverse both LL and check if at any point they meet.
// If they don't intersect at any point and encounter NULL then we return -1 else we return any LL's data.

// Get the length of LL.
int getLen(Node* head){
    Node* temp = head;
    int len=0;
    while (temp){
        len++;
        temp = temp->next;
    }
    return len;
}

int intersectPoint(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    // Get the difference between the lengths of both LL.
    int dif = max(getLen(temp1), getLen(temp2)) - min(getLen(temp1), getLen(temp2));
    
    Node* longtemp = temp1;
    Node* shorttemp = temp2;
    if (getLen(temp1)>getLen(temp2)){
        longtemp = temp1;
        shorttemp = temp2;
    }else{
        longtemp = temp2;
        shorttemp = temp1;
    }
    
    while (shorttemp!=longtemp){
        if (shorttemp->next==NULL) return -1;
        if (dif==0){
            shorttemp = shorttemp->next;
            longtemp = longtemp->next;
        }
        else{
            longtemp = longtemp->next;
            dif--;
        }
    }
    return shorttemp->data;
}
