// T.C = O(n)
// S.C = O(1)
// We have to keep on adding char from back with carry(if any) till both i and j gets less than 0.
// And after each addition we store resultant sum(which is int) value into string.
class Solution {
  public:
    string findSum(string X, string Y) {
        string ans="";
        int i=X.size()-1, j=Y.size()-1, carry=0;
        
        while (i>=0 || j>=0){
            // IF one of the value(i or j) < 0 (which means they are out of bound) then they will hold 0 value.
            // ELSE we assign them to int value at ith index in string.
            int num1=0, num2=0;
            if (i>=0) num1 = X[i] - '0';
            if (j>=0) num2 = Y[j] - '0';
            // Calculate sum of both char at ith index with carry.
            int sum = num1 + num2 + carry;
            int lastDigit = sum%10;
            carry = sum/10;
            // Add lastDigit of sum in ans string. (We adding lastdigit cuz resultant sum could be two digit number(>9).
            ans += to_string(lastDigit);
            i--,j--;
        }
        // IF carry is > 0 then this means we have another char to add into our ans string
        if (carry>0) ans += to_string(carry);
        // Now start iterating through ans string for 0's from beginning.
        // IF we encounter 0 at first we remove that char and move on to next char,
        // ELSE we just break out of the loop.
        // This is because we only want to remove 0's from beginning of ans string and not from mid or back.
        for (int i=ans.size()-1; i>=0; i--){
            if (ans[i]=='0') ans.erase(i);
            else{ break; }
        }
        // IF the ans string size is less than 1 then we know that the values were all 0 and thus got removed in previous step.
        // ELSE reverse the ans string and return.
        if (ans.size()<=0){
          ans = to_string(0);
          return ans;
        }
        // Reverse the ans string.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
