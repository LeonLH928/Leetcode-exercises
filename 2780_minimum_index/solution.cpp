#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isDominant(int fre, int len) {
        return fre * 2 > len;
    }
    void getMaxFre(unordered_map<int, int>& fre, int newNum, int &max_val, int &max_s1) {
        fre[newNum]++;
        if (fre[newNum] > max_s1) {
            max_s1 = fre[newNum];
            max_val = newNum;
        }
    }
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> h;
        for (auto &num : nums) {
            h[num]++;
        }
        unordered_map<int, int> fre;
        int max_s1 = 0;
        int max_val;
        for (int i = 0; i < nums.size(); i++) {
            getMaxFre(fre, nums[i], max_val, max_s1);
            int max_s2 = h[max_val] - max_s1;
            if (isDominant(max_s1, i + 1) && isDominant(max_s2, nums.size() - i - 1)) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << s.minimumIndex(nums);
}