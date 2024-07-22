// Approach 1: Using queue and two loops for travesing in levels.
// T.C = O(n)
// S.C = O(n)
// Logic: First push address of root in queue.
// Now iterate in queue until it is empty.
// Keep count of elements in each level using queue's size.
// Now in another loop traverse in current level and push them in temp vector to later push it into 2D vector(2D vector because of gfg printing condition).
// Keep on decrementing level element's count in each inner loop iteration.
// Check current node's left and right and push it in queue and pop in queue from front(since it's already used for level).
vector<vector<int>> levelOrder(Node* node)
{
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(node);
    
    while (!q.empty()){
        int levelCount = q.size();
        Node* curr;
        vector<int>temp;
      
        while(levelCount>0){
            curr = q.front();
            temp.push_back(curr->data);
            levelCount--;
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            q.pop();
        }
        // Push temp vector in 2D vector i.e ans.
        ans.push_back({temp});
    }
    return ans;
}
