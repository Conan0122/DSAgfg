// Using modified level order traversal
// T.C = O(n)
// S.C = O(n)
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (!root) return ans;
    queue<Node*>q;
    q.push(root);
    
    while (!q.empty()){
        int nodeCount = q.size();
        ans.push_back(q.front()->data);
        
        while (nodeCount>0){
            Node* temp = q.front();
            nodeCount--;
            q.pop();
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return ans;
}
