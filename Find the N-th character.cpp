// T.C = O(n*r)
// S.C = O(n)
char nthCharacter(string s, int r, int n) {
        string ans="";
        
        while (r>0){
            string str = "";
            for (int i=0; i<s.size(); i++){
                if (s[i] == '0'){
                    str += "01";
                }
                else{
                    str += "10";
                }
                if (i>n) break;
            }
            r--;
            s = str;
            ans = str;
        }
        
        return ans[n];
    }
