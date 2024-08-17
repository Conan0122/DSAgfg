// Approach 1: Using prefix sum technique
// T.C = O(n)
// S.C = O(1)
// Logic: Just find the prefix sum of an array and then look for element which is half of n-1 element.
bool canSplit(vector<int>& arr) {
  int sum =0, n = arr.size();
  
  for (int i=1; i<n; i++){
    arr[i] += arr[i-1];
  }
  if (arr[n-1]%2!=0) return false;
  
  for (int i=0; i<n; i++){
    if (arr[i]==arr[n-1]/2) return true;
  }
  return false;
}
//////////////////////////////////////////////////////////////////////////
// Approach 1: Two pointer
// T.C = O(n)
// S.C = O(1)
// Logic: Just keep on finding the sum both the end and when both pointer crosses each other check if they are equal or not.
// Increment pointer based on the sum they hold till that index.
bool canSplit(vector<int>& arr) {
  int left = 0, right = arr.size()-1;
  int lsum=0, rsum=0;
  
  while (left<=right){
    if (lsum>rsum) rsum += arr[right--];
    else lsum += arr[left++];
  }
  return lsum==rsum;
}
