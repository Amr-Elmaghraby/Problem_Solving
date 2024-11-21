#include <iostream>
#include <vector>


//0r Best practical Solution "Two Pointer Solution"
//0o Time Complixity:  O(N)
//0o Space Complisity: O(1)

class Solution{
    public:
    int trap(std::vector<int>& height){
        int n = height.size();
        if(n<3){return 0;}
        int left =0,right=n-1;
        int left_max=0,right_max=0;
        int Trapped_Water=0;
        // طول ما اليمين مأمني 
        // Taking the POV of left if right height is biggert than left,
        // then it will take the empty space between the current location and the previous on
        // as right height is bigger so it insures me to do so and also for the right one if left
        // height is bigger 
        //0r to get it more just think of this input example being solved "4,0,0,0,2,0,0,3,0,0,0,6"
        // Explaining on the example
        // as right is the biggest height then left will reach it adding all the possible spaces
        // between as right is insuring it to be a valid trapped water
        // like at index 7, height 3 i can add the extra one trapped water
        // as right height is insuring that "being bigger height "   
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>= left_max){
                    left_max = height[left];
                }
                else{
                    Trapped_Water += left_max - height[left];
                }
                ++left;
            }
            else{
                if(height[right] >=right_max){
                    right_max = height[right];
                }
                else{
                    Trapped_Water += right_max - height[right];
                }
                --right;
            }
        }
        return Trapped_Water;
    }
};


int main(){
    Solution sl;
    std::vector<int> vc = {0,1,0,2,1,0,1,3,2,1,2,1};
    int hd = sl.trap(vc);


    std::cout << hd;
    return 0;
}