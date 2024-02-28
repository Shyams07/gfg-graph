//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int time=0;
    
    void dfs(int node, int parent, vector<int> &tim, vector<int> &low,
    vector<int> &vis, vector<int> adj[], vector<int> &mark){
        
        vis[node]=1;
        tim[node]=low[node]=time++;
        int child=0;
        
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                child++;
                 dfs(it,node,tim,low,vis,adj,mark);
                 low[node]=min(low[node],low[it]);
                 if(low[it]>=tim[node] && parent!=-1){
                     mark[node]=1;
                 }
            }else{
                low[node]=min(low[node],tim[it]);
            }
        }
        if(parent==-1 && child>1){
            mark[node]=1;
        }
    }  
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int>tim(V,-1);
        vector<int> low(V,-1);
        vector<int> vis(V,0);
        vector<int> mark(V,-1);
 
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,tim,low,vis,adj,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends