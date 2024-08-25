// Appraoch 1 : Using extra space to store data of left and right subtrees.
// T.C = O(n)
// S.C O(n), vector + recursive call stack.
// Logic: Here we use inorder traversal to keep left subtree in one vector and right subtree in another subtree.
// Then we check if both vectors are of same size or not, if not then return false.
// Now check if left subtree is equal to right subtree on reverse.
void solve(Node* root, vector<int> &v){
    if (root){
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
}

bool isSymmetric(struct Node* root)
{
  if (!root) return true;
  vector<int> v1, v2;
  solve(root->left, v1);
  solve(root->right, v2);
  
  if (v1.size()!=v2.size()) return false;
  
  for (int i=0, j=v2.size()-1; i<v1.size() && j>=0; i++, j--){
      if (v1[i] != v2[j]) return false;
  }
  return true;
}
////////////////////////////////////////////////////////////////////////////////
// Appraoch 2 : Without using extra space and only checking left and subtree at the same time.
// T.C = O(n)
// S.C O(h), height of binary tree.
// Logic: Just pass left and right subtree at the same time and keep on checking left of one subtree with right of another subtree and 
// right subtree of one with left subtree of another.
bool solve(Node* root1, Node* root2){
  if (!root1 && root2 || root1 && !root2) return false;
  if (!root1 || !root2) return true;
  if (root1->data != root2->data) return false;
  
  bool left = solve(root1->left, root2->right);
  bool right = solve(root1->right, root2->left);
  
  return left && right;
}

bool isSymmetric(struct Node* root)
{
  if (!root) return true;
  return solve(root->left, root->right);
}
