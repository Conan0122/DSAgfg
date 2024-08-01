// T.C = O(n)
// S.C = O(n)
// Using queue
bool check(Node *root)
    {
        queue<Node*> q;
        set<int>s;
        q.push(root);
        int level=0;
        
        while(!q.empty()){
            int nodeCount = q.size();
            while(nodeCount>0){
                Node* temp = q.front();
                q.pop();
                
                nodeCount--;
                if (temp->left==NULL && temp->right==NULL) s.insert(level);
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            level++;
        }
        return s.size()==1;
    }
