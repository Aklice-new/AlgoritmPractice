/*
* @Author: Aklice
* @Date:   2022-02-06 13:25:53
* @Last Modified time: 2022-02-06 13:26:29
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>a,b;
        for(int i = 0;i < nums.size();i ++){
            if(i&1) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(a.begin(),a.end());
        vector<int>ans;
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < nums.size();i ++){
            if(i&1) ans.push_back(a[cnt1++]);
            else ans.push_back(b[cnt2++]);
        }
        return ans;
    }
};