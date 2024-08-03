// T.C = O(n)
// S.C = O(h), h is the height of bin tree, recursive call.
// Using recursion.
// Just add left subtree and right subtree and check if root is equal to that sum or not,
// if we encounter any node which has child with different sum then switch the flag to false and since it is passed as reference
// it is saved permanently.
int modify(Node* root, bool &flag){
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    int total=0;
    
    if (flag){
        total = root->data;
        root->data = modify(root->left, flag) + modify(root->right, flag);
        
        if (root->data!=total) flag = false;
    }
    return total+root->data;
}

string isSumTree(Node* root) {
    bool flag = true;
    modify(root, flag);
    return flag? "true":"false";
}
