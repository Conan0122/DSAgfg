// T.C = O(n)
// S.C = O(n)
// Just add left subtree and right subtree at every node.
// Base condition: If we ever reach at null node then we know we can return 0 and it's parent node will be having 0 added to it.
// In this way if a node has no child then it becomes 0 whereas if a node has only child then it gets sum up to other child's data.
// Recursion: Here we just store current node's data (since we gonna rewrite it in next step so we need to store it somwwhere before that so we can use it later.
// Now change current node's data to sum of left and right subtree.
// Return sum of current node's data and the element it had before this modification.

int solve(Node* node){
    if (!node->left && !node->right){
        int temp = node->data;
        node->data=0;
        return temp;
    }
    int leftele=0, rightele=0;
    
    if (node->left) leftele = solve(node->left);
    if (node->right) rightele = solve(node->right);
    
    
    int ele = node->data;
    node->data = leftele+rightele;
    return node->data+ele;
}

void toSumTree(Node *node)
{
    solve(node);
}

/////////////////////////////////////////////////////////
// Same approach with same T.C and S.C but a little bit clean and simple.
int solve(Node* node){
    if (!node) return 0;
  
    int ele = node->data;
    node->data = solve(node->left) + solve(node->right);
    return node->data+ele;
}

void toSumTree(Node *node)
{
    solve(node);
}
