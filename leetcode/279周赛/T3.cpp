/*
* @Author: Aklice
* @Date:   2022-02-06 13:25:53
* @Last Modified time: 2022-02-06 13:27:41
* @Mail address : 2404681701@qq.com
*/
class Bitset {
public:
    int vis[100005];
    int siz = 0;
    int zeor = 0;
    int re = 0;
    Bitset(int size) {
        siz = size;
        zeor = siz;
        for(int i = 0;i < siz;i ++)
            vis[i] = 0;
    }
    
    void fix(int idx) {
        if(re&1){
            if(vis[idx] == 1) {
                vis[idx] = 0; zeor ++;
            }
        }
        else {
            if(vis[idx] == 0){
                vis[idx] = 1; zeor --;
            }
        }
    }
    
    void unfix(int idx) {
        if(re&1){
            if(vis[idx] == 0) {
                vis[idx] = 1; zeor --;
            }
        }
        else {
            if(vis[idx] == 1){
                vis[idx] = 0; zeor ++;
            }
        }
    }
    
    void flip() {
        re ++;
    }
    
    bool all() {
        if(re&1) return zeor == siz;
        else return zeor == 0;
    }
    
    bool one() {
        if(re&1) return zeor >= 1;
        else return zeor < siz;
    }
    
    int count() {
        if(re&1) return zeor;
        else return  siz - zeor;
    }
    
    string toString() {
        string ans = "";
        if(re&1){
            for(int i = 0;i < siz;i ++){
                if(vis[i]) ans += '0';
                else ans += '1';
            }
        }   
        else{
            for(int i = 0;i < siz;i ++){
                if(vis[i]) ans += '1';
                else ans += '0';
            }
        }   
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */