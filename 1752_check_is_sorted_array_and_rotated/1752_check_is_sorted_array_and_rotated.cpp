#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int limit_allowed = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) limit_allowed++;
        }
        if (nums[nums.size() - 1] > nums[0]) limit_allowed++;
        return limit_allowed < 2;
    }
};
int main() {
    Solution calculate;
    vector<int> nums = {6,10,6};
    cout << calculate.check(nums);
}