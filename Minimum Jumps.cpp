// Approach: My approach using just loop.
// T.C = O(n)
// S.C = O(1)
// Logic: simple yet tricky logic: Just traverse from first index and maintain two variables,
// one for farthest index we can react from current position and
// another for checking current move if it is already in last possible reach or we can still further go beyong this.(hard to explain with just words 
// [GO through 3rd IF statement for better understanding.]).
int minJumps(vector<int>& arr) {
  int countMove = 0, farthestInd = INT_MIN, n = arr.size();
  int jump=0;
  
  for (int i=0; i<n;i++){
    // Update farthest possible reach index
    if (farthestInd < arr[i]+i) farthestInd = arr[i]+i;
    // If farthest we can reach is end of the array then return with jump + 1(+1 because last jump till end is also needs to be counted.)
    if (farthestInd >= n-1) return jump+1;
    // Main part:- IF we reached out of previous move and farthest reach has more moves then set moves to farthest reach possible index and increase jump.
    if (countMove == i && countMove != farthestInd){
        countMove = farthestInd;
        jump++;
    }
    // ELSE we know we got no moves + this was the farthest reach possible by any previous elements as well. So return -1 since we can't reach end anymore.
    else if (countMove==i && farthestInd == countMove) return -1;
  }
  return jump;
}
