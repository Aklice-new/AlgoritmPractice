/*
* @Author: Aklice
* @Date:   2022-02-06 13:25:53
* @Last Modified time: 2022-02-06 13:28:17
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    int pre[200005],bak[200005];
    int minimumTime(string s) {
        int cnt = 0;
        if(s[0] == '1') {
            pre[0] = 1; cnt = 1;
        }
        else pre[0] = 0;
        // cout << pre[0] << ' ';
        for(int i = 1;i < s.size();i ++){
            if(s[i] == '1') cnt ++;
            if(s[i] == '1')
                pre[i] = min({i + 1,2 * cnt,pre[i - 1] + 2});
            else
                pre[i] = pre[i - 1];
            //cout << pre[i] << ' ';
        }
        //cout << endl;
        cnt = 0;
        for(int i = s.size() - 1;i >= 0;i --){
            if(s[i] == '1') cnt ++;
            if(s[i] == '1')
                bak[i] = min({(int)s.size() - i,2 * cnt,bak[i + 1] + 2});
            else 
                bak[i] = bak[i + 1];
            //cout << bak[i] << ' ';
        }
        int ans = min(pre[(int)s.size() - 1],bak[0]);
        for(int i = 1;i < s.size();i ++){
            ans = min(ans,pre[i - 1] + bak[i]);
        }
        return ans;
    }
};