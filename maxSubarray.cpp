using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> begin;
        vector<int> end;
        int max=0;
        
        bool zero=false;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                nums.erase(nums.begin()+i);
                i--;
                zero=true;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0 && (i==0 || nums[i-1]<0))
                begin.push_back(i);
            if(nums[i]>0 && (i==nums.size()-1 || nums[i+1]<0))
                end.push_back(i);
        }

        if(begin.size()==0) {
            if(zero)
                return 0;
            return *max_element(nums.begin(), nums.end());
        }

        for(int bIndex=0; bIndex<begin.size(); bIndex++) {
            int eIndex=0;

            while(end[eIndex]<begin[bIndex])
                eIndex++;
            int sum=nums[begin[bIndex]];

            for(int each=begin[bIndex]+1; each<=end[eIndex]; each++) {
                sum+=nums[each];
            }

            if(sum>max)
                max=sum;

            for(eIndex; eIndex<end.size()-1; eIndex++) {
                for(int each=end[eIndex]+1; each<=end[eIndex+1]; each++) {
                    sum+=nums[each];
                }
                if(sum>max)
                    max=sum;
            }
        }
        
        return max;
    }
};

