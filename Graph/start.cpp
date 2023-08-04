#include <bits/stdc++.h>
using namespace std;
#define comment int

/* dfs =>
 *Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
 *Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list
*/

/* bfs =>
 *Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
 *Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/

/* Connected Component =>
 *Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 
 *Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
*/

/* detect cycle in undirected graph
 *Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
 *Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
*/

class Solution {
   private: 

    vector<int> Dfs;
    vector<int> bfs;

    void dfs(int node, vector<int> adj[], int vis[]) {
        vis[node] = 1; 
        Dfs.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis); 
            }
        }
    }

  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        dfs(start, adj, vis); 
        return Dfs; 
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); 
         
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }

     int noOfConnectedComponent(vector <int> adj[], int V) {
        
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adj, vis); 
            }
        }
        return cnt; 
        
    }

  private: 
  bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout<<endl;
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 4, 3);
    addEdge(adj, 2, 1);

    Solution obj;
    vector <int> bans = obj.bfsOfGraph(5, adj);
    printAns(bans);

    vector <int> dans = obj.dfsOfGraph(5, adj);
    printAns(dans);

    cout<<obj.noOfConnectedComponent(adj,5)<<endl;

    vector<int> adj1[4] = {{}, {2}, {1, 3}, {2,1}};
    
    bool ans = obj.isCycle(4, adj1);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}