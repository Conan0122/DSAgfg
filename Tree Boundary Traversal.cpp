// Approach: Without using recursion. Using stack instead :)
// Logic: First handle left side of tree, then leaf nodes and finally right side of tree.
// T.C = O(n)
// S.C = O(h), h is height of tree.
vector <int> boundary(Node *root)
{
  if (!root->left && !root->right) return {root->data};
  vector<int>ans;
  stack<Node*>s;
  s.push(root);
  
  Node* temp;
  // Left
  if (root->left) temp = root;
  else{
      ans.push_back(root->data);
      temp = nullptr;
  }
  while(temp){
      ans.push_back(temp->data);
      s.pop();
      if (temp->right) s.push(temp->right);
      if (temp->left){
          s.push(temp->left);
          temp = temp->left;
      }
      else temp = temp->right;
  }
  
  // Leaf
  while(!s.empty()){
      Node* frontN = s.top();
      if (!frontN->left && !frontN->right) ans.push_back(frontN->data);
      s.pop();
      if (frontN->right) s.push(frontN->right);
      if (frontN->left) s.push(frontN->left);
  }
  
  // Right
  if (root->right) temp = root->right;
  else temp = nullptr;
  
  bool flag = false;
  while(temp){
      s.push(temp);
      if (temp->right) temp=temp->right;
      else temp = temp->left;
      flag = true;
  }
  if (flag) s.pop();
  while(!s.empty()){
      ans.push_back(s.top()->data);
      s.pop();
  }
  
  return ans;
}
