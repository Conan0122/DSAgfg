// T.C = O(n)
// S.C = O(n)
// Using Recursion
void fibo(vector<int> &v, int n, int i, int sum){
        int mod = 1e9+7;
        if (i==n) return;
        
        v.push_back(sum);
        i++;
        sum = (sum + v[i-1]) % mod;
        fibo(v, n, i, sum);
    }
    
    vector<int> Series(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        
        fibo(v, n, 1, 1);
        return v;
    }
