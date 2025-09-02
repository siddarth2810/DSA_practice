#include <bits/stdc++.h>
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> mergeVectors(vector<int> myVector, vector<int> alicesVector) {
  int myIdx = 0;
  int aliceIdx = 0;
  int myVecSize = myVector.size();
  int aliceVecSize = alicesVector.size();
  vector<int> merged;

  while (myIdx < myVecSize && aliceIdx < aliceVecSize) {
        if(myVector[myIdx] < alicesVector[aliceIdx]) {
            merged.push_back(myVector[myIdx++]);
        }else {
            merged.push_back(alicesVector[aliceIdx++]);
        }
  }
    if(aliceIdx < aliceVecSize){
        for(int i = aliceIdx; i<aliceVecSize; i++){
            merged.push_back(alicesVector[i]);
        }
    }
    if(myIdx < myVecSize){
        for(int i = myIdx; i<myVecSize; i++){
            merged.push_back(myVector[i]);
        }
    }

    for(auto it: merged){
        cout << it << " ";
    }
    cout << endl;

    return merged;
}


const lest::test tests[] = {
    {CASE("both vectors are empty") {
        const vector<int> myVector;
        const vector<int> alicesVector;
        const vector<int> expected;
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("first vector is empty") {
        const vector<int> myVector;
        const vector<int> alicesVector {1, 2, 3};
        const vector<int> expected {1, 2, 3};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("second vector is empty") {
        const vector<int> myVector {5, 6, 7};
        const vector<int> alicesVector;
        const vector<int> expected {5, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("both vectors have some numbers") {
        const vector<int> myVector {2, 4, 6};
        const vector<int> alicesVector {1, 3, 7};
        const vector<int> expected {1, 2, 3, 4, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("vectors are different lengths") {
        const vector<int> myVector {2, 4, 6, 8};
        const vector<int> alicesVector {1, 7};
        const vector<int> expected {1, 2, 4, 6, 7, 8};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char **argv) {
  int result = lest::run(tests, argc, argv);
  if (result == 0) {
    cout << "All " << sizeof(tests) / sizeof(tests[0])
         << " selected tests passed." << endl;
  }
  return result;
}


