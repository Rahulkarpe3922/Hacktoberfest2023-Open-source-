class Solution{
public:
    int solve(int ind, int w, int val[], int wt[], vector<vector<int>> &dp) {
        if(ind == 0) 
            return val[0] * (w / wt[0]);
        
        if(dp[ind][w] != -1)
            return dp[ind][w];
        
        int notTake = solve(ind - 1, w, val, wt, dp);
        int take = -1e9;
        
        if(wt[ind] <= w) 
            take = val[ind] + solve(ind, w - wt[ind], val, wt, dp);
        
        return dp[ind][w] = max(take, notTake);
    }

    int knapSack(int n, int w, int val[], int wt[]) {
        vector<vector<int>> dp(n, vector<int> (w + 1, -1));
        return solve(n - 1, w, val, wt, dp);
    }
};
