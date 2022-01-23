/*
* @Author: Aklice
* @Date:   2022-01-23 12:47:36
* @Last Modified time: 2022-01-23 12:55:12
* @Mail address : 2404681701@qq.com
*/
/*
思路：普通的bfs，将每个点按bfs的顺序进行遍历，遍历到的步数就是最短步数，然后根据题目意思进行
	筛选合适的点，取前k大就行。
时间复杂度：O(n*m * log(n * m))
*/
class Solution {
public:
    struct node{
        int x,y; //行列坐标
        int price;//价格
        int dis;
        bool operator<(const node &other)const{
            if(dis != other.dis) return dis < other.dis;
            if(price != other.price) return price < other.price;
            if(x != other.x) return x < other.x;
            return y < other.y;
        }
    }s[100005];
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    int dis[100005];
    int vis[100005];
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        memset(dis,0x3f,sizeof dis);
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{start[0],start[1]},0});
        dis[start[0] * m + start[1]] = 0;
        while(!q.empty()){
            auto now = q.front();
            int x = now.first.first;
            int y = now.first.second;
            int z = now.second;
            q.pop();
            if(vis[x * m + y]) continue;
            vis[x * m + y] = 1;
            for(int i = 0;i < 4;i ++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx<0||xx>=n||yy<0||yy>=m||grid[xx][yy]==0||vis[xx * m + yy]) continue;
                dis[xx * m + yy] = z + 1;
                //cout << xx << ' ' << yy << ' ' << z + 1 << endl;
                q.push({{xx,yy},z + 1});
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(vis[i * m + j] && grid[i][j] != 0 && grid[i][j] != 1 && grid[i][j] <= pricing[1] && grid[i][j] >= pricing[0])
                    s[cnt++] = node{i,j,grid[i][j],dis[i * m + j]};
            }
        }
        sort(s,s + cnt);
        vector<vector<int>>ans;
        for(int i =0 ;i < min(k,cnt);i ++)
            ans.push_back({s[i].x,s[i].y});
        return ans;
    }
};