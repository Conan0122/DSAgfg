// T.C = O(n)
// S.C = O(n)
// This is same as height of binary tree, but in this we cant use level order traversal whereas for searching height of binary tree we can use level order as well as recursive.
// Approach: Recursive- Just get the max height of left subtree and right subtree, ans then add 1 to it.
int solve(Node* root){
    if (root) return max(solve(root->left), solve(root->right))+1;
    return 0;
}

int maxDepth(Node *root) {
    return solve(root);
}
