class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int n = max(a.size(), b.size());
         while (a.size() < n) a = '0' + a;
        while (b.size() < n) b = '0' + b;

        for(int i = n-1; i>=0; i--){
            int digA = a[i] - '0';
            int digB = b[i] - '0';
            int sum = digA+digB+carry;

            carry = sum/2;
           res += (sum % 2) + '0';  // add binary digit
            carry = sum / 2;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
