// T.C = O(2^n)
// T.C = O(n)
// Using recursion: 
// LOGIC: move n-1 disks in helper tower and then move last(biggest disk) in final/ destination tower.
// Now keep on calling function recursively untill we reach n==1, in this case move that one(last disk) to destination tower.
long long count=0;

void solve(int n, int a, int c, int b){
    // Base condition
    if (n==1){
        cout << "move disk 1 from rod " << a <<" to rod " << c << endl;
        count++;
        return;
    }
    
    solve(n-1, a, b, c);
    cout << "move disk " << n << " from rod "<< a << " to rod " << c << endl;
    count++;
    
    solve(n-1, b, c, a);
}

long long toh(int n, int from, int to, int aux) {
    solve(n,from,to,aux);
    return count;
}
