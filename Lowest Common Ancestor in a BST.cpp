// T.C = O(h)
// S.C = O(h)
// Approach: Using recursion
// Logic: If min of n1 or n2 is one left side and max of n1 and n2 is on right side then we know that current root is the LCA.
// Else if min of n1 or n2 is one right side then we know LCA is on right side of righ subtree, so we solve on right subtree.
// Else we know LCA is on left subtree so we solve for left side.
Node* solve(Node* root, int n1, int n2){
    if (!root) return NULL;
    if (n1<root->data && n2 > root->data || root->data == n1 || root->data == n2) return root;
    else if (n1 > root->data) return solve(root->right, n1, n2);
    else return solve(root->left, n1, n2);
}

Node* LCA(Node *root, int n1, int n2)
{
    return solve(root, min(n1,n2), max(n1,n2));
}
