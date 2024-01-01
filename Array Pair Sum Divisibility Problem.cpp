// T.C = O(n)
// S.C = O(1)

// Solved using Two pointer approach.
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n=nums.size(), pair=0, i=0, j=1;
        // If n is odd then we can't make pair.
        if (n%2 != 0) return false;
        // Now start iterating over elements and check each element if they(two element at a time) can form a pair as per the condition(sum of every pair is divisible by k).
        while (i<n-1){
            // If j >= n then we know there exist an i element which has no pair in a vector.
            if (j>=n) break;
            // If current ith element = -1 then we know that this element is part of pair already,
            // so we just move our ith forward and also move j to i+1 index.
            // ELSE we check if not ith element then maybe jth element has -1?
            // if yes then we move just j by 1 index.
            if (nums[i] == -1){
                i++;
                j = i+1;
                continue;
            }
            else if (nums[j] == -1){
                j++;
                continue;
            }
            // Now we check for main condition that is, sum of every pair is divisible by k or not.
            // IF yes then we increment pair by 1 and replace ith and jth element to -1(so that we don't count this same element again with any other pair in next iterations).
            // ELSE we just increment j by 1.
            if ((nums[i]+nums[j])%k == 0){
                pair++;
                nums[i] = -1;
                nums[j] = -1;
                j = i+1;
            }
            else{
                j++;
            }
        }
        // NOW finally we check if pair is equals to n/2 or not.
        // It is because we know that if a vector is eligible for having pair then pair must be have of number of elements present in vector.
        if (pair == n/2) return true;
        return false;
    }
};

// Other way by which we can solved this problem are:
//  - Two pointer with sorting. [T.C = O(nlogn) and S.C = O(1)]
//  - Using unordered map. [T.C = O(n) and S.C = O(n)]
