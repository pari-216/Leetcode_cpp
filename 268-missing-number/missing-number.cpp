class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing;
        int n=nums.size();
        int sum =0, sumRange;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sumRange= (n*(n+1))/2;
        missing= sumRange-sum;
        return missing;
    }
};