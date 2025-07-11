#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int recFun(vector<int>& heights, int ind) {
        if (ind == 0) {
            return 0;
        }
        
        int left = recFun(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        
        int right = INT_MAX;
        if (ind > 1) {
            right = recFun(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
        }
        
        return min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return recFun(heights, n - 1);
    }
};

int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    
    vector<int> heights(n);
    cout << "Enter the heights of the stones:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    Solution sol;
    int minCost = sol.frogJump(heights);
    cout << "Minimum total cost for the frog: " << minCost << endl;

    return 0;
}
