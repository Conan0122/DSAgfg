// T.C = O(n)
// S.C = O(n)
// Approach: Using Level order traversal with modification for even levels.
// For even levels use stack to reverse the elements of level in it.
// In even levels, push elements into stack instead of directly into ans vector.
// After level completes we can simply traverse through stack and push it's elements into ans vector which will be in reverse form.
void lotSpiral(Node* root, vector<int>& v, int levelCount){
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()){
        int nodeCount = q.size();
        stack<int> st;
      
        while (nodeCount>0){
            Node* temp = q.front();
            q.pop();
            
            if (levelCount%2!=0) v.push_back(temp->data);
            else st.push(temp->data);
            
            nodeCount--;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        
        while (!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        levelCount++;
    }
}


vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    lotSpiral(root, ans, 0);
    
    return ans;
}
