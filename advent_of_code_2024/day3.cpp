
#include <bits/stdc++.h>
#include <cctype>
#include <stack>
using namespace std;


int calculate(string s) {
    stack<int> st;
    int n = s.size();
    int cur_no= 0;
    int sign = 1;
    int res = 0;

    for(int i=0; i<n; i++){
        //digit processing
        if(isdigit(s[i])){
            cur_no = cur_no*10 + (s[i] - '0');
        }
        else if(s[i] == '+'){
            res += cur_no*sign;
            cur_no = 0;
            sign = 1;
        }
        if(s[i] == '-'){
            res += cur_no *sign;
            cur_no = 0;
            sign = -1;
        }
        // parenthesis
        else if(s[i] == '('){
            st.push(res);
            st.push(sign);
            //reset things
            res = 0;
            sign = 1;
        }
        else if(s[i] == ')'){
            res += sign * cur_no;
            cur_no = 0;
            int prev_sign = st.top(); st.pop();
            int prev_res = st.top(); st.pop();
            res = prev_res + prev_sign*res;
        }
    }

    res += sign*cur_no;
    return res;
}


int main () {
    string s = "(1+(4+5+2)-3)+(6+8)";
   cout << calculate(s) << endl;

    return 0;
}
