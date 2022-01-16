/*
* @Author: Aklice
* @Date:   2022-01-16 15:11:36
* @Last Modified time: 2022-01-16 15:13:03
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(target != 1){
            ans ++;
            if(maxDoubles == 0) return ans + target - 2;
            if(target %2 == 0){
                maxDoubles --;
                target /= 2;
            }
            else target -= 1;
        }
        return ans;
    }
};