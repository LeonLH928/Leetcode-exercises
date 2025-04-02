//  This problem is already solved (using prefix and suffix array).
//  But if you don't understand why prefix and suffix and REALLY want to understand, you can 
// reference my explanation:
//  Our goal is to maximize the (nums[i] - nums[j]) * nums[k] with i < j < k.
//  So, how can we do this? Well, we will have two cases: Maximum and positive or minimum and 
// negative of (nums[i] - nums[j]) and nums[k] (consider -999 * -999 and 999 * 999 will give us 
// the maximum). Luckily, we don't have to care the latter case because the constraint (1 <= nums
// [i] <= 1e6) always ensures the positivity. Therefore, we can just maximize separately (nums
// [i] - nums[j]) (positive) and nums[k] (positive). Multiplying both will give us the maximum.

//  So, how can we do this, again? Well, let's consider (nums[i] - nums[j]), we can maximize 
// nums[i] and minimize nums[j], this will give us the maximum of (nums[i] - nums[j]). num[k] is
// much easier, we just simply maximize it. Then the maximum product needed.

//  Ok, we have got the algorithm quite, but there's a question: why do we keep nums[j] and make 
// suffix for nums[i] and prefix for nums[k]. Why don't we do, for example, keep nums[i] and 
// make some kinda arrays for nums[j] and nums[k]?

//  From here, I'm gonna just explain this question and how the algorithm works.
//  Take [12,6,1,2,7] as an example:
//  If we follow the prefix and suffix algorithm, we will only care about nums[j] and the prefix 
// and suffix array. Because we care about j (note that i < j < k), j will start at least at 
// 1 (i.e, entry 6). Again, we care the maximum of nums[i] and nums[k], in this case it will be 
// 12 (index 0) and 7 (index 4). Quite easy, so lets move to middle, lets say I want to care the
// maximum when j = 2 (nums[j] = 1). What will be the value of nums[i] and nums[k] that satisfy
// the problem? Again, 12 and 7! Do I have to care about nums[i] = 6 and nums[k] = 2? NO! 
// (this is the disadvantage of the three nested loop, it loops through all the available 
// triplets while the maximum triplet can be more simply achieved). Now, you understand the 
// origin of the prefix array (used to get the maximum before nums[j]) and the suffix array 
// (used to get the maximum after nums[j]).
//  About the question, well, we can actuall do the other way. But it will be a little more complex and also not effective as the prefix and suffix algorithm. Basically, keeping nums[j] or nums[i] or even nums[k] and make other 2 arrays to keep maximum or minimum value according to the pivot is theoretically possible. But the implementation in code is not easy like the theory. In the prefix and suffix algorithm, we have to make the prefix and suffix array and this is much simpler than the other algorithms keeping the pivot other than nums[j]. You can make the prefix array simply by keeping track of the maximum at each index from the start and suffix array by keeping track of the minimum at each index from the end. Lets say I want to make two arrays according to nums[i], I have to make nums[j] minimum and nums[k] maximum. But this is not easy anyway... With nums[j] pivot, I can make locally.........
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0), suffix(nums.size(), 0);

        for (int j = 1; j < nums.size(); j++) {
            prefix[j] = max(prefix[j-1], nums[j-1]);
            suffix[nums.size() - j - 1] = max(suffix[nums.size() - j], nums[nums.size() - j]);
        }

        long long ans=0;
        for (int j = 0; j < nums.size(); j++) {
            ans = max(ans, ((long long)prefix[j] - nums[j]) * suffix[j]);
        }
        return ans;
    }
};