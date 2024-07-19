// T.C = o(n)
// S.C = o(n), recursive stack call.
// LOGIC: We know that BST has all min elements in it's root's left and max elements at root's right, and hence we can use this fact for implementing our actual logic.
// To validate BST we must make sure that for each element's left child it's in valid range which is, child's max should be less than root's element.
// And at right of tree for each element's right child it's in valid range as well which is, child's min should be root's element.
// For example:
//      10
//    5    25
//        9  29
// In above case, to be a valid BST it should follow this:
//        (--,++)
//        /      \
//    (--,10)    (10,++)
//                /    \
//            (10,25)  (10,++)

// Another example(valid):
//       2
//    1     3
//            5
// In above case, to be a valid BST it should follow this:
//        (--,++)
//        /      \
//    (--,2)    (2,++)
//              /    \
//           (2,3)  (2,++)
///  In short in left child max should be root's element and in right child min should be root's element.
bool helper(Node* root, int minRange, int maxRange){
  if (!root) return true;
  
  if (root->data > minRange && root->data < maxRange){
      bool left = helper(root->left, minRange, root->data);
      bool right = helper(root->right, root->data, maxRange);
      return left && right;
  }
  else return false;
}

bool isBST(Node* root) {
  return helper(root, INT_MIN, INT_MAX);
}
