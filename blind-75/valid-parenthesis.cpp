#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size() == 0) return false;
        for (auto it : s) {
            switch (it) {
            case '(':
                st.push(it);
                break;

            case ')':
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(it);
                break;

            case '[':
                st.push(it);
                break;
            case ']':
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(it);
                break;

            case '{':
                st.push(it);
                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    st.push(it);
                break;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

