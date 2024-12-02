// https://leetcode.com/problems/collect-coins-in-a-tree/description/
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        // find number of total nodes
        // remove unnecessary leaf nodes and their parents if they are
        // unnecesssary leafs as well
        // find leafs with coins
        // remove leaf nodes with coins and their parents as well if they are leafs after removing this edge
        // the path required to traverse remaining nodes is the answer

        // why it works
        // no need of leaf nodes without coins
        // then the leafs with coins and thier parents are within distance 2 of the remaining nodes so they don't matter as well
        // removing edges avoids retraversing
        int n = coins.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        int rem = n;
        queue<int>leafCoins;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)q.push(i);
        }
        while(q.size()){
            int node = q.front();
            q.pop();
            if(coins[node]){
                leafCoins.push(node);
                continue;
            }
            rem--;
            for(auto u:adj[node]){
                 auto parent = find(adj[node].begin(),adj[node].end(),u);
                 auto child = find(adj[u].begin(),adj[u].end(),node);
                adj[node].erase(parent);
                adj[u].erase(child);
                if(adj[u].size()==1){
                    q.push(u);
                }
            }
        }
        for(int i=0;i<2;i++){
            int nodeCurLvl = leafCoins.size();
            while(nodeCurLvl--){
                int node = leafCoins.front();
                leafCoins.pop();
                rem--;
                for(int u:adj[node]){
                    auto parent = find(adj[node].begin(),adj[node].end(),u);
                    auto child = find(adj[u].begin(),adj[u].end(),node);
                    adj[node].erase(parent);
                    adj[u].erase(child);
                    if(adj[u].size()==1){
                        leafCoins.push(u); 
                    }
                }
            }
        }
        return rem==0 ? 0:(rem-1)*2 ;

    }
};
