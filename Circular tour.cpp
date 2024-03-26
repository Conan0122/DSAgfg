// T.C = O(n)
// S.C = O(1)
// Using two pointer technoque and with queue operation logic.
int tour(petrolPump p[],int n)
{
    int ptotal = 0, j = 0, prepetrol = 0;
  
    for (int i=0; i<n; i++){
        ptotal += p[i].petrol - p[i].distance;

        // IF total petrol till now gets < 0 then we need to update start position of truck(j) to i + 1.
        // Update total petrol amount to 0 since we gonna start it over again.
        // Also update/add deficit petrol in a variable so that we can use it later to check if petrol is enough to complete a cycle not.
        if (ptotal < 0){
            prepetrol += ptotal;
            j = i+1;
            ptotal = 0;
        }
    }
    // IF total petrol + deficit petrol >= 0 then return start position,
    // Else we know that truck can't complete the cycle.
    if (ptotal+prepetrol >= 0) return j;
    return -1;
}
