#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// tests
const lest::test tests[] = {
    {CASE("empty string") {
        const string expected;
        string actual;
        reverse(actual);
        EXPECT(actual == expected);
        cout << "empty string                   passed: actual == expected for \""
             << actual << "\" == \"" << expected << "\"" << endl;
    }},
    {CASE("single character string") {
        const string expected("A");
        string actual("A");
        reverse(actual);
        EXPECT(actual == expected);
        cout << "single char string           passed: actual == expected for \""
            << actual << " == " << expected << endl;
    }},
    {CASE("longer string") {
        const string expected("EDCBA");
        string actual("ABCDE");
        reverse(actual);
        EXPECT(actual == expected);
        cout << "longer string                  passed: actual == expected for \""
             << actual << "\" == \"" << expected << "\"" << endl;
    }}
};

int main(int argc, char** argv)
{
    int result = lest::run(tests, argc, argv);
    if (result == 0) {
        cout << "All " << sizeof(tests)/sizeof(tests[0]) << " selected tests passed." << endl;
    }
    return result;
}


