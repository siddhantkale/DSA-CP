// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/
class Solution {
public:
    // we can observe that if a node has a nodes at even dis
    // then all of it's children (adj nodes) will have n - a nodes at even dis
    // use this observation to find nodes at even dis from each node o(n)
    // now we can either connect cur_node in tree 1 with a node with  min evens ( max odds) at odd dis  or max evens at even distance in tree2
  
    vector<vector<int>>maketree(int size,vector<vector<int>>& edges){
        vector<vector<int>>tree(size);
        for(auto it:edges){
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        return tree;
    }
    vector<int>findEvens(vector<vector<int>>tree,int size){
        queue<pair<int,int>>q;
        vector<int>vis(size,0);
        q.push({0,0});
        vis[0] = 1;
        int cnt = 1;
        vector<int>ans(size,0);
        while(q.size()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(int u:tree[node]){
                if(!vis[u]){
                    q.push({u,!dis});
                    if(dis){
                       cnt++; 
                    }
                    vis[u] = 1;
                }
            }
            
        }
        ans[0] = cnt;
        vector<int>vis2(size,0);
        queue<int>q2;
        vis2[0] = 1;
        q2.push(0);
        while(q2.size()){
            int node = q2.front();
            q2.pop();
            for(int u:tree[node]){
                if(!vis2[u]){
                    vis2[u] = 1;
                    q2.push(u);
                    ans[u] = size - ans[node];
                }
            }
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
         int n = edges1.size()+1,m = edges2.size()+1;
        vector<vector<int>>tree1 = maketree(n,edges1);
        vector<vector<int>>tree2 = maketree(m,edges2);
        vector<int>evens1 = findEvens(tree1,n);
        vector<int>evens2 = findEvens(tree2,m);
        int maxEvens = 0,maxOdds = 0;
        for(int i:evens2){
            maxEvens = max(maxEvens,i);
            maxOdds = max(maxOdds,m-i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = evens1[i] + max(maxEvens,maxOdds);
        }
        return ans;
    }
};
