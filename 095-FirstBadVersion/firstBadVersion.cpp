#include <iostream>





class Solution
{
    private:
    bool isBadVersion(int version){
        if(version<189){
            return false;
        }else{
            return true;
        }
    }
    public:
    int firstBadVersion(int n)
    {
        int left = 0;
        int right = n;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(isBadVersion(mid)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};



int main()
{
    int n = 510;
    Solution sol;
    std::cout << sol.firstBadVersion(n);
    return 0;
}