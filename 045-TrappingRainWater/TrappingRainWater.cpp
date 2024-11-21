#include <iostream>
#include <vector>


//0r Not best practical Solution
//0o Time Complixity:  O(N^2)
//0o Space Complisity: O(1)
class Solution
{
public:
    int trap(std::vector<int>& height){
        if(height.size()<=2){return 0;}
        int Trapped_Water =0;
        for(int i=0;i<height.size();++i){
            int bars_bn[2] = {0,0};
            int max_bn[2] = {0,0};
            for(int j=i+1;j<height.size();++j)
            {
                if(height[i] <= height[j]){
                    Trapped_Water += ( height[i] * (j-i-1) )- bars_bn[0];
                    i = (j-1);
                    break;
                }
                else
                {
                    if(height[j] >= max_bn[1])
                    {
                        max_bn[0] = j;
                        max_bn[1] = height[j];
                        bars_bn[1] = bars_bn[0];
                    }
                    bars_bn[0] += height[j];
                }
                if(j == height.size()-1)
                {
                    Trapped_Water += ( max_bn[1] * (max_bn[0]-i-1) ) - bars_bn[1];
                    i = (max_bn[0]-1);
                    break;
                }
            }
        }
        return Trapped_Water;
    }
};

int main() {
    Solution sol;
    std::vector<int> vc = {0,1,0,2,1,0,1,3,2,1,2,1};
    int height = sol.trap(vc);

    std::cout << height;

    return 0;
}