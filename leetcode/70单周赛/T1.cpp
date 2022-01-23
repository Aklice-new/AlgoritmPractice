/*
* @Author: Aklice
* @Date:   2022-01-23 12:47:36
* @Last Modified time: 2022-01-23 12:50:06
* @Mail address : 2404681701@qq.com
*/
/*
思路：贪心的去思考，每次从大到小的，取完较大的两个，即可顺便免费带走第三小的
时间复杂度： O(nlogn)
*/
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int ans = 0;
        int j =0;
        for(int i = 0;i + 2 <(int)cost.size();i += 3){
            ans += cost[i] + cost[i + 1];
            j = i + 3;
        }
        for(;j < (int)cost.size();j ++)
            ans += cost[j];
        return ans;
    }
};