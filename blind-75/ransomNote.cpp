class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        int freq[26] = {0};  // frequency for 'a' to 'z'

        for (char c : magazine) {
            freq[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) {
                return false; // not enough letters
            }
        }

        return true;
    }
};

