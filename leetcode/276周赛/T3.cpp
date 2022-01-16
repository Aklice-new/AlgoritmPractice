/*
* @Author: Aklice
* @Date:   2022-01-16 15:11:38
* @Last Modified time: 2022-01-16 15:13:19
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    long long dp[100005][2];
    long long mostPoints(vector<vector<int>>& questions) {
        reverse(questions.begin(),questions.end());
        dp[0][0] = 0;
        dp[0][1] = questions[0][0];
        long long ans = 0;
        for(int i = 1;i < (int)questions.size();i ++){
            int pre = i - questions[i][1] - 1;
            if(pre < 0)
                dp[i][1] = questions[i][0];
            else 
                dp[i][1] = max(dp[pre][1],dp[pre][0]) + questions[i][0];
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
            
        }
        for(int i = 0;i < questions.size();i ++)
            ans = max({ans,dp[i][0],dp[i][1]});
        return ans;
    }
};