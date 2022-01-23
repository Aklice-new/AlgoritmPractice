/*
* @Author: Aklice
* @Date:   2022-01-23 12:47:36
* @Last Modified time: 2022-01-23 12:52:42
* @Mail address : 2404681701@qq.com
*/
/*
思路：我们可以先假设第一个元素为0，然后通过差分数组去求出整个数组的最大值，和最小值
	然后这个最大最小值的差，就是最后的可以取值的范围，在通过与要求的最大值最小值进行做差
时间复杂度： O(n)
*/
class Solution {
public:
    long long a[100005];
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx = 0,mn = 0;
        for(int i = 0;i < (int)differences.size();i ++){
            a[i + 1] = differences[i] + a[i];
            mx = max(mx,a[i + 1]);
            mn = min(mn,a[i + 1]);
        }
        int len = mx - mn + 1;
        int ltn = upper - lower + 1;
        int ans = ltn - len + 1;
        if(ans <= 0) return 0;
        return ans;
        
    }
};