// T.C = O(n)
// S.C = O(n)
// Using queue: Just do a level order traversal and push NULL into the queue when we are entering to next level.
// While encountering NULL in the queue, increament height variable.
// NOTE: Pushing NULL in queue(logic) is same as in level order traversal of tree and print data of each level in different line.
int height(struct Node* node){
    queue<Node*>q;
    q.push(node);
    q.push(NULL);
    int t_height = 0;
    
    while (!q.empty()){
        if (q.front() == NULL){
            t_height++;
            q.pop();
            if (q.empty()) break;
            q.push(NULL);
            continue;
        }
        
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    return t_height;
}
