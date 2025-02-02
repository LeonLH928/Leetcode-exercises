#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (target % 2 == 0) {
            vector<int>::iterator it_1 = find(nums.begin(), nums.end(), target / 2);
            vector<int>::iterator it_2 = find(it_1 + 1, nums.end(), target / 2);
            if (it_1 != nums.end() && it_2 != nums.end()) {
                result.push_back(distance(nums.begin(), it_1));
                result.push_back(distance(nums.begin(), it_2));
                return result;
            } 
        }
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if (target % 2 == 0 && nums[i] == target / 2) continue;
            hash_map[nums[i]] = i;
        }
        for (const auto& ele : nums) {
            unordered_map<int, int>::iterator it_1 = hash_map.find(ele);
            unordered_map<int, int>::iterator it_2 = hash_map.find(target - ele);
            if (it_1 != hash_map.end() && it_2 != hash_map.end()) {
                result.push_back(it_1->second);
                result.push_back(it_2->second);
                break;
            }
        }
        return result;
    }
};
int main() {
    vector<int> vt = {2,7,11,15};
    int target = 9;
    Solution calculate;
    vector<int> result = calculate.twoSum(vt, target);
    for (auto& ele : result) cout << ele << ' ';
}