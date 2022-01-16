/*
* @Author: Aklice
* @Date:   2022-01-16 15:11:37
* @Last Modified time: 2022-01-16 15:13:50
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:

    bool check(long long mid,int n,vector<int>& batteries){
        long long sum = 0;
        for(int i = 0;i < batteries.size();i ++){
            if(batteries[i] <= mid)
                sum += batteries[i];
            else sum +=  mid;
        }
        return sum >=  mid * 1ll * n ;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long l = 1,r = 100000000000000;
        while(l < r){
            long long mid = (l + r + 1)/2;
            if(check(mid,n,batteries))
                l = mid;
            else r = mid - 1;
        }
        return l;
    }
};