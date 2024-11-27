// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      //Is a graph type problem to find shortest distances between first and last node
      // so we store distances to each ndoe from node 0
        vector<int>dist(n,0);
      // we create an adj list (mainly to store the new edges)
        vector<vector<int>>adj(n);
      // (distance to each node is it's value and there is a unidirectional edge between 
      // cur and next node so add in adj list)
        for(int i=0;i<n;i++){
            if(i!=n-1)adj[i].push_back(i+1);
            dist[i] = i;
        }
      // the answer to each query
        vector<int>ans;
      // process each query
        for(auto edge:queries){
            int u=edge[0],v = edge[1];
          // add edge to adj list
          adj[u].push_back(v);
          // queue to track nodes where there is change in distances 
            queue<int>q;
          // add current node if the edge reduced it's distance
            if(dist[v]> (dist[u]+1)){
                dist[v] = dist[u]+1;
                q.push(v);
            }
            while(q.size()){
                int cur = q.front();
              //check for change in distances of cur node
                for(int node:adj[cur]){
                    if(dist[node] > dist[cur]+1){
                        dist[node] = dist[cur]+1;
                        q.push(node);
                    }
                }
                q.pop();
            }
          // find the distance between first and last node
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};
