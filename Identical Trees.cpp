// T.C = O(n)
// S.C = O(n), recursive call stack
// Approach: Using recursion check each element one by one.
// Compare both element at the same time.
bool isIdentical(Node *r1, Node *r2)
{
    if (!r1 && !r2) return true;
    if (r1 && !r2) return false;
    if (!r1 && r2) return false;

    // If both left of both trees and right of both trees are equal then return true else false.
    if (r1->data != r2->data) return false;
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}
