class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        long long sum=0;
        long long ans = 0;
        unordered_map<int,int>mp;        
        while(j<nums.size()){
            
            mp[nums[j]]++;
            sum+=nums[j];
            
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                
                if(mp.size()==k) ans = max(sum,ans);
                sum-=nums[i];
                mp[nums[i]]--;
                if(!mp[nums[i]]) mp.erase(nums[i]);
                i++;
                j++;
                
            }
        }
            
        return ans;
    }
};