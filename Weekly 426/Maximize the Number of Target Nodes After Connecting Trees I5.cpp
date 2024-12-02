https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/
class Solution {
public:
    // constraints are small
    // for every node in tree 1 find how many nodes are reachable (within k) using bfs or any algo
    // for every node in tree 2 find how many are reachable in (k-1)
    // select the node with max number of reachable nodes from tree2
    // for each query the answer will be number of reachable nodes from that node in tree1 + max in tree2
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+2;
        vector<vector<int>>tree1(n),tree2(m);
        for(auto it:edges1){
            tree1[it[0]].push_back(it[1]);
            tree1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            tree2[it[0]].push_back(it[1]);
            tree2[it[1]].push_back(it[0]);
        }
        vector<int>inK1(n,0),inK2(m,0);
        for(int i=0;i<n;i++){
            queue<pair<int,int>>q;
            vector<int>vis(n,0);
            q.push({i,0});
            int cnt = 1;
            vis[i] = 1;
            while(q.size()){
                int node = q.front().first;
                int dis = q.front().second;
                q.pop();
                for(int v:tree1[node]){
                    if(!vis[v] && dis+1<=k){
                        q.push({v,dis+1});
                        cnt++;
                        vis[v] = 1;
                    }
                }
            }
            inK1[i] = cnt;
        }
        k--;
        for(int i=0;i<m;i++){
            queue<pair<int,int>>q;
            vector<int>vis(m,0);
            
            int cnt=0;
            if(k>=0){
                q.push({i,0});
                cnt = 1;
                vis[i] = 1;
            }
            
            
            while(q.size()){
                int node = q.front().first;
                int dis = q.front().second;
                q.pop();
                for(int v:tree2[node]){
                    if(!vis[v] && dis+1<=k){
                        q.push({v,dis+1});
                        cnt++;
                        vis[v] = 1;
                    }
                }
            }
            inK2[i] = cnt;
        }
        vector<int>ans;
        int maxi = 0;
        for(int i=0;i<m;i++){
            maxi = max(maxi,inK2[i]);
        }
        for(int i=0;i<n;i++){
            ans.push_back(maxi + inK1[i]);
        }
        return ans;
    }
};
