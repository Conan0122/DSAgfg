// Approach 1: Using DFS with queue (Prefered solution)
// T.C = O(2n)
// S.C = O(n)
// Logic: It's just normal level order traversal with little modification.
// Here instead of pushing left first to queue, we will push right of node to queue.
// Atlast we just need to reverse whole array.
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()){
        int ndSize=q.size();
        
        while (ndSize>0){
            Node* temp = q.front();
            q.pop();
            ndSize--;
            ans.push_back(temp->data);
            
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
///////////////////////////////////////////////////////////////////////////////////////
// Approach 2: Using DFS with queue and stacks (Not Prefered solution)
// T.C = O(n)
// S.C = O(2n)
// Logic: At first it's like basic level order but then it's modifies as per the requirements.
// in first loop instead of pushing the ans in vector we push it to stack.
// Then in using another loop we simple push stack elements to ans vector.
// Atlast we reverse ans vector to generate correct result.
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*>q;
    q.push(root);
    stack<int>st;
    
    while (!q.empty()){
        int nodeCount = q.size();
        // Push elements to current level's element in stack.
        while(nodeCount>0){
            Node* temp = q.front();
            q.pop();
            nodeCount--;
            st.push(temp->data);
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        // Now push stack elements to ans vector.
        // This will give us reverse level order but in reverse order.
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    // So now reverse whole vector back.
    reverse(ans.begin(), ans.end());    
    return ans;
}
