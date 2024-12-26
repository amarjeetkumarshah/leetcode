class Solution {
public:

    int f(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        // base cases.
        if (index==0) {
            if (target==0 && nums[index]==0) return 2;
            if (nums[index]==target || target==0) return 1;
            return 0;
        }
        // yoyo dp
        if(dp[index][target]!=-1) return dp[index][target];
        // Pick case.
        int Pick=0;
        if (nums[index]<=target) Pick=f(index-1, target-nums[index], nums, dp);
        // not Pick case
        int notPick=f(index-1, target, nums, dp);

        return dp[index][target] = Pick+notPick;

    }

    int tab(int n, int k, vector<int> &nums){
        vector<int> prev(k+1, 0), curr(k+1, 0);

        if (nums[0]==0) prev[0]=2;
        else prev[0]=1;

        if (nums[0]!=0 && nums[0]<=k) prev[nums[0]]=1;

        for (int index=1; index<n; index++){
            for (int target=0; target<=k; target++){
                int Pick=0;
                if (nums[index]<=target) Pick=prev[target-nums[index]];
                // not Pick case
                int notPick=prev[target];

                curr[target] = Pick+notPick;
            }
            prev=curr;
        }return prev[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int k=(sum-target);
        if (k<0 || k%2!=0){
            return 0;
        }

        int n=nums.size();
        //vector<vector<int>> dp(n, vector<int> (k+1, -1));
        //return f(n-1, k/2, nums, dp);
        return tab(n, k/2, nums);

    }
};