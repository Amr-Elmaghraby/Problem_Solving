#include <iostream>
#include <vector>
using namespace std;


//0r Not Best Practical Solution
//0o Time Complixity:  O(N)
//0o Space Complisity: O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        // Precompute left and right max heights
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate water trapped
        int waterTrapped = 0;
        for (int i = 0; i < n; ++i) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }

        return waterTrapped;
    }
};

int main(){
    Solution sl;
    std::vector<int> vc={0,1,0,2,1,0,1,3,2,1,2,1};
    int an = sl.trap(vc);

    std::cout << an;

    return 0;
}