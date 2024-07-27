// T.C = O(n)
// S.C = O(h), where h is the height of tree, recursive call stack.
// Logic: Just swap the left and right links.
// Swap left link to right link and right link to left.
// Then call left and right recursively.
void solve(Node* node){
    if (node){
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        solve(node->left);
        solve(node->right);
    }
}

void mirror(Node* node) {
    solve(node);
}
