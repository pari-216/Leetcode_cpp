class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), count=0, candidate=0, num;
        for(int i=0; i<n; i++){
            num= nums[i];
            if(count==0){
                candidate=num;
            }
            if(num==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};