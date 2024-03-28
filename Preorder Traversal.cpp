// T.C = O(n)
// S.C = O(n)
// Using recursion.
void sol(Node* root, vector<int>&v){
    if (root != NULL){
        v.push_back(root->data);
        sol(root->left, v);
        sol(root->right, v);
    }
}

vector <int> preorder(Node* root)
{
    vector<int>ans;
    sol(root, ans);
    return ans;
}
