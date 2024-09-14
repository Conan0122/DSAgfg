// Approach: Using extra vector to store -ve and +ve numbers.
// T.C = O(n)
// S.C = O(n)
void rearrange(vector<int> &arr) {
  vector<int> pos, neg;
  int n = arr.size(), pPtr=0, nPtr=0;
  bool flag = true;
  
  for (int i=0; i<n; i++){
    if (arr[i]>=0) pos.push_back(arr[i]);
    else neg.push_back(arr[i]);
  }
  
  if (pos.size() != 0 && neg.size() != 0){
    for (int i=0; i<n; i++){
      if (pPtr<pos.size() && flag){
        arr[i] = pos[pPtr++];
      }
      else if (nPtr<neg.size() && !flag){
        arr[i] = neg[nPtr++];
      }
      
      if (pPtr>=pos.size()) flag = false;
      else if (nPtr>=neg.size()) flag = true;
      else flag = !flag;
    }
  }
}
