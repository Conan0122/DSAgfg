// Approach 1: My custom approach using loop + recursion.
// Logic: Just calculate height of left and right subtree.
// Note: Only start calculating height when both left and right subtree are not empty.
int height(Node* root){
  if (!root) return 0;
  return max(height(root->left),height(root->right))+1;
}

int diameter(Node* root) {
  if (!root) return 0;
  int count=0;    // In case tree never finds the node which has both left and right end then return the calculated count only.(Skewed tree or single node).
  // Check if root's left and right subtree both aren't empty.
  // If any one of next node is empty then move on to the one which isn't not empty.
  // When we encounter node which has both left and right subtree then calculate height.
  while (root){
    if (root->left && root->right){
        return height(root->left)+height(root->right)+1;
    }
    if (root->left) root=root->left;
    else root = root->right;
    count++;
  }
  return count;
}
