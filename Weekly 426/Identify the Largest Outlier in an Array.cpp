// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/
class Solution {
public:
    // observation : 
    // the sum of all elements is y
    // if an element is a possible outlier then
    // y - cur_element = 2x (must be true)
    // where x is sum of all special elements
    // so just apply above formula and check if an x exists

    int getLargestOutlier(vector<int>& nums) {
        int maxi = -1e9;
        unordered_map<int,int>mpp;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            mpp[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int sample = sum - nums[i];
            if(sample%2==0){
                if(mpp.find(sample/2)!=mpp.end() && mpp[sample/2]!=i){
                    maxi = max(maxi,nums[i]);
                }
            }
        }
        return maxi;
    }
};
