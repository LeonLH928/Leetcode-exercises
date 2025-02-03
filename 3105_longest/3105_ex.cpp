#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest_increasing = 1, longest_decreasing = 1; // one possible longest length is always one since there are one or one more elements in nums
        int temp_increasing = 0, temp_decreasing = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                temp_increasing = 0;
                if (temp_decreasing == 0) temp_decreasing = 2;
                else temp_decreasing++;
                if (temp_decreasing > longest_decreasing) longest_decreasing = temp_decreasing;
            }
            else if (nums[i] < nums[i + 1]) {
                temp_decreasing = 0;
                if (temp_increasing == 0) temp_increasing = 2;
                else temp_increasing++;
                if (temp_increasing > longest_increasing) longest_increasing = temp_increasing;
            }
            else {
                temp_decreasing = temp_increasing = 0;
            }
        }
        return longest_increasing > longest_decreasing ? longest_increasing : longest_decreasing;
    }
};
int main() {
    vector<int> test_case = {1,4,3,3,2};
    Solution solution;
    cout << solution.longestMonotonicSubarray(test_case);
}