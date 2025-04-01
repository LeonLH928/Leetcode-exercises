#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<long long> result;
        // which: 0 for whatever, 1 for earn, 2 for skip
        long long mostPoints(vector<vector<int>>& questions, int ini=0, int idx=0, int which=0) {
            if (!ini) result.resize(questions.size(), -1);
            
            if (idx >= questions.size()) return 0;
            if (result[idx] != -1) return result[idx];
            if (which == 1) return questions[idx][0] + std::max(mostPoints(questions, 1, idx + 1 + questions[idx][1], 1), mostPoints(questions, 1, idx + 1 + questions[idx][1], 2));
            if (which == 2) return mostPoints(questions, 1, idx + 1);
    
            long long maxEarn = mostPoints(questions, 1, idx, 1);
            long long maxSkip = mostPoints(questions, 1, idx, 2);
            
            result[idx] = std::max(maxEarn, maxSkip);
    
            return result[idx];
        }
    };