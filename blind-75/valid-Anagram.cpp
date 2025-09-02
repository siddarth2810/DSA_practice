class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s(26,0);
        vector<int> count_t(26,0);

        if (s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++){
            count_s[s[i] - 'a']++;
            count_t[t[i] - 'a']++;
        }

        for(int i=0; i<count_s.size(); i++){
            if(count_t[i] != count_s[i]) return false;
        }

        return true;


    }
};
