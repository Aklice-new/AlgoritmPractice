/*
* @Author: Aklice
* @Date:   2022-01-23 12:47:36
* @Last Modified time: 2022-01-23 12:58:27
* @Mail address : 2404681701@qq.com
*/
/*
思路： 根据题目要求，每个挡板中有且仅有两个座椅，那么我们可以在每次分完两个座椅后，进行
		屏风的插入，对于连续的植物，那么这次插入可以有多个位置，利用乘法原理，每次相乘即可
时间复杂度：O(n)
*/
class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int cnt = 0;
        for(auto v : corridor)
            if(v == 'S')
                cnt ++;
        if(!cnt || cnt & 1)return 0;
        int flag = 0,len = 0;
        long long ans = 1;
        vector<int>vec;
        for(int i = 0;i < (int)corridor.size();i ++){
            if(corridor[i] == 'S') {
                if(flag % 2 == 0 && flag){
                    ans *= 1ll * (len + 1);
                    //cout << len + 1 << endl;
                }
                ans %= mod;
                len = 0;
                flag ++;
            }
            else{
                len ++;
            }
        }
        ans %= mod;
        return (int)ans;
    }
};