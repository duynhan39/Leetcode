using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int sum=nums[0], maxS=nums[0];
        for(int i=1; i<nums.size(); i++) {

            sum=nums[i]+max(sum, 0);
            maxS=max(sum, maxS);
        }

        return maxS;
    }
};
