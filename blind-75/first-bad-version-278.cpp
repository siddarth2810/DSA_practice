// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binSearch(int low, int high){
        int mid = low + (high - low)/2;
        if(low >= high){
            return low;
        }
        if(isBadVersion(mid)){
            // left half
            return binSearch(low, mid);
        }
        else {
            return binSearch(mid +1 , high);
        }
    }
    int firstBadVersion(int n) {
        int low = 0;
        int high = n;

        return binSearch(low, high);
    }
};
