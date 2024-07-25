// Same as left view of binary tree
// T.C = O(n)
// S.C = O(n)
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if (!root) return ans;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()){
        int nodeCount = q.size();
        
        while (nodeCount>0){
            Node* temp = q.front();
            q.pop();
            if (nodeCount==1) ans.push_back(temp->data);
            nodeCount--;
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return ans;
}
