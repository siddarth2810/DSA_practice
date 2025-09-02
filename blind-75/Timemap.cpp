#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto &vec = mpp[key];
        string res = "";
        int low = 0, high = mpp[key].size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(vec[mid].first <= timestamp) {
                low = mid + 1;
                res = vec[mid].second;
            }
            else high = mid - 1; //not mid
        }
        return res;
    }
};


int main() {
  TimeMap* obj = new TimeMap();
    obj->set("sid", "sloth", 1);
    obj->set("sid", "sloww", 2);
  return 0;
}


