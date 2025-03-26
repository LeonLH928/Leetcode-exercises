#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size();
        int col = grid[0].size();
        int len = row * col;
        vector<int> a(len);
        int idx = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                a[idx++] = grid[i][j];
            }
        }
        sort(a.begin(), a.end());
        int min = a[(len) / 2];
        int remainder = a[0] % x;
        int c = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] % x != remainder) {
                return -1;
            }
            if (a[i] == min) {
                continue;
            }
            int temp = abs(min - a[i]);
            c += temp / x;
        }
        return c;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }
    int x;
    cin >> x;
    cout << Solution::minOperations(grid, x);
}