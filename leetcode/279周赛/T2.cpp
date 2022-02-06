/*
* @Author: Aklice
* @Date:   2022-02-06 13:25:53
* @Last Modified time: 2022-02-06 13:27:09
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    long long smallestNumber(long long num) {
        if(num < 0){
            num *= -1;
            string str = to_string(num);
            sort(str.begin(),str.end());
            reverse(str.begin(),str.end());
            long long ans = atoll(str.c_str());
            ans *= -1;
            return ans;
        }
        else{
            string str = to_string(num);
            sort(str.begin(),str.end());
            if(str[0] == '0'){
                int pos = 0;
                for(int i = 0;i < str.size();i ++)
                    if(str[i] != '0'){
                        pos = i;break;
                    }
                swap(str[0],str[pos]);
            }
            
            long long ans = atoll(str.c_str());
            return ans;
        }
    }
};