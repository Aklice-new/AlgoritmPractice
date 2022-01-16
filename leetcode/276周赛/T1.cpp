/*
* @Author: Aklice
* @Date:   2022-01-16 15:11:15
* @Last Modified time: 2022-01-16 15:12:45
* @Mail address : 2404681701@qq.com
*/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>re;
        for(int i = 0;i < (int)s.size();i += k){
            string tmp = s.substr(i,k);
            re.push_back(tmp);
            
        }
        string b = re.back();
        re.pop_back();
        while(b.size() < k){
            b += fill;
        }
        re.push_back(b);
        return re;
        
    }
};