#include <iostream>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int different = 0; 
        char *temp_c1 = nullptr;
        char *temp_c2 = nullptr;
        bool isSecondSame = false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])  {
                if (temp_c1 == nullptr) {
                    temp_c1 = &s1[i];
                    temp_c2 = &s2[i];
                    different++;
                    continue;
                }
                if (*temp_c1 == s2[i] && *temp_c2 == s1[i]) isSecondSame = true;
                different++;
            }
        }
        return (isSecondSame && different == 2) || different == 0;
    }
};