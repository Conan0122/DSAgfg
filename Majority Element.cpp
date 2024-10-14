// Approach: Using Boyer Moore Voting Algorithm
// T.C = O(n)
// S.C = O(1)
// Logic: Assume first element as the majority element and then keep checking next element,
// if next element is same as assumed maj ele then increase the count by 1,
// Keep going untill we reach the end. By the time we reach the end we will have candidate for maj ele(not exactly majority till now).
// Now traverse the array again and check if the candidate element has occured more than n/2 times or not.
int candidateEle(vector<int>& arr){
  int count=0, n=arr.size();
  int choosenEle = arr[0];

  for (int i=1; i<n; i++){
    if (choosenEle == arr[i]){
      count++;
    }
    else if (choosenEle!=arr[i] && count == 0){
      choosenEle = arr[i];
    }
    else count--;
  }
  return choosenEle;
}

int majorityElement(vector<int>& arr) {
  int candidate = candidateEle(arr);
  int count = 0;
  
  for (int i=0; i<arr.size(); i++){
    if (arr[i]==candidate) count++;
  }
  return (count>arr.size()/2)?candidate:-1; 
}
