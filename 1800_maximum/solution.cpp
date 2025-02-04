#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int temp_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                temp_sum += nums[i];
            }
            else {
                temp_sum = nums[i];
            }
            if (temp_sum > max_sum) max_sum = temp_sum;
        }    
        return max_sum;
    }
};
int main() {
    vector<int> test = {10,20,30,40,50};
    Solution solution;
    cout << solution.maxAscendingSum(test);
}