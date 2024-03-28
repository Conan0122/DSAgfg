// T.C = O(n)
// S.C = O(n)
// Using queue to store all nodes at each level.
// First store pointer to node in queue, then traverse all the elements present in queue. POP the front element from queue(since it is a current node and we already stored it's address in node pointer variable.
// Now for each element OR (pointer to node element) in queue, check if their left and right node exist or not.
// IF exists then store them in queue.
// After pushing them into queue push the current node's data into answer vector.
vector<int> levelOrder(Node* root)
{
    queue<Node*>q;
    vector<int> ans;
    q.push(root);
    
    // Traverse in queue
    while (!q.empty()){
        int size = q.size();
        
        // Store left and right's address of current node in queue.
        for (int i=0; i<size; i++){
            Node* nd = q.front();
            q.pop();
            
            // IF current node doesn't have NULL child then push them in queue.
            if (nd->left != NULL) q.push(nd->left);
            if (nd->right != NULL) q.push(nd->right);
            // Push the current node's data in ans vector.
            ans.push_back(nd->data);
        }
    }
    return ans;
}
