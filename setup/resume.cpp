#include <bits/stdc++.h>
using namespace std;

#include "lest.hpp"

class Solution {
public:
  int minDistance(string word1, string word2) {
        if(word1.size() == 0 && word2.size() == 0 ) {
            return 0;
        }
        if(word1.size() == 0 && word2.size() != 0 ) {
            return word2.size();
        }
        if(word2.size() == 0 && word1.size() != 0 ) {
            return word1.size();
        }

        if(word1.size() == word2.size()){
            //recurse
        }

        return 0;
    }
};


const lest::test tests[] = {
    {CASE("horse and ros"){
        int min = 3;
        Solution s;
        int res = s.minDistance("horse", "ros");
        EXPECT(min == res);
    }},
};

int main(int argc, char**argv) {
  int result = lest::run(tests, argc, argv);
    if(result == 0){
        cout <<"All " << sizeof(tests)/sizeof(tests[0])
            << " selected tests have passed" << endl;
    }
  return 0;
}

