// Approach 1: Using vector
// T.C = O(n)
// S.C = O(h+n), where h is height of binary tree and n is the elements stored in extra vector used for ans.
// Logic: Just store each element in vector using inorder traversal.
// After we are done with inorder traversal just return size-k element from vector.
void inorder(Node* root, vector<int>&v){
    if (root){
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}

int kthLargest(Node *root, int K)
{
    vector<int> ans;
    inorder(root, ans);
    int size = ans.size();
    return ans[size-K];
}

//////////////////////////////////////////////////////////////////
// Approach 2: Without using extra vector
// T.C = O(n)
// S.C = O(h), where h is height of binary tree, recursive call stack
// Logic: Using reversed inorder traversal.
// We know that kth max element will be in kth position of reversed inorder traversal.
void inorder(Node* root, int &k, int& ans){
    if (root){
        inorder(root->right, k, ans);
        if (--k==0) ans = root->data;
        inorder(root->left, k, ans);
    }
}

int kthLargest(Node *root, int K)
{
    int ans = 0;
    inorder(root, K, ans);
    return ans;
}
