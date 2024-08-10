// T.C = O(n)
// S.C = O(1)
// First separate first k nodes from rest of the LL.
// Now when we have two LLs, merge first k nodes' LL at the end of rest of the LL.
Node* rotate(Node* head, int k) {
  // If head is single node or if k is 0 then simply return head of LL.
  if (!head->next || k==0) return head;
  Node* temp = head;
  Node* prev = head;
  // Separate first k node from rest of the LL.
  int count=k;
  while(count--){
      if (temp->next==NULL)return head;
      prev = temp;
      temp = temp->next;
  }
  // As we keep on maintaining prev pointer, we just assign it's next to NULL as it will be the last node of new LL after rotation.
  prev->next = NULL;
  // Now since we want new head for the result we can simple reuse prev pointer or we can even create new pointer named probably as: newHead.
  prev = temp;

  // Go to last node of rest of remaining LL.
  while(temp&&temp->next) temp = temp->next;
  // Now connect the first k nodes LL with rest of the node's last node.
  temp->next = head;
  // Return prev pointer as it is pointing to new head.
  return prev;
}
