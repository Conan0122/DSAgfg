// T.C = O(n)
// S.C = O(1)

void deleteNode(struct Node **head, int key)
{
    Node* temp = (*head)->next;
    Node* prev = *head;
    
    while (temp!=(*head)){
        if (temp->data == key){
            prev->next = prev->next->next;
            return;
        }
        else{
            prev = temp;
        }
        temp = temp->next;
    }
    prev->next = temp->next;
    *head = temp->next;
}

void reverse(struct Node** head_ref)
{
    Node* curr = *head_ref;
    Node* nextnode = curr->next;
    Node* prev = NULL;
    
    do{
        curr->next = prev;
        prev = curr;
        curr = nextnode;
        if (nextnode->next==NULL){
            nextnode->next = prev;
        }else{
            nextnode = nextnode->next;
        }
    }while (curr!=(*head_ref));
    
    *head_ref = prev;
}
