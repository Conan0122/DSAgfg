// T.C = O(n)
// S.C = O(h), (h is the height of tree), recursive call stack.
// Logic: Keep on checking if current node is balanced or not.
// We can verify this using abs(left-right) > 1, if it is then we know it can't be balanced binary tree.
// NOTE: Keep checking height of left and right sub tree for each level.
int height(Node* root){
    // Base condition: if root is NULL then we know it's empty.
    if (!root) return 0;

    // Get the height of left and right sub tree for each node.
    int left = height(root->left);
    int right = height(root->right);
    // Now, check if left/ right sub tree resulted in -1 or not, if it did then we know either left or right sub tree isn't balanced.
    // And hence we can return -1 since we know it can't be balanced binary tree.
    if (left==-1 || right == -1 || abs(left-right) > 1) return -1;
    // If everything is valid then return the height of tree for current node.
    return max(left,right)+1;
}

bool isBalanced(Node *root)
{
    // If the result is in -1 then it is not a balanced binary tree.
    return height(root)==-1? false:true;
}
