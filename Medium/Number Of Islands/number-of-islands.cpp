//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int findUpr(int node){
        if(node== parent[node])
            return node;
        return parent[node]=findUpr(parent[node]);
    }
    
    void UnionbyRank(int u,int v){
        int ulp_u= findUpr(u);
        int ulp_v= findUpr(v);
        
        if(ulp_u==ulp_v)return;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
    private:
    bool isvalid( int adjr, int adjc, int n, int m){
        return adjr>=0 && adjc>=0 && adjr<n && adjc<m;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(m*n);
        int vis[n][m];
        memset(vis,0, sizeof vis);
        int cnt=0;
        vector<int> ans;
        
        for(auto it : operators){
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int adjr=row+dr[i];
                int adjc=col+dc[i];
                
                if(isvalid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){
                        int nodeNo= row*m +  col;
                        int adjNodeNo= adjr*m + adjc;
                        if(ds.findUpr(nodeNo)!= ds.findUpr(adjNodeNo)){
                            cnt--;
                            ds.UnionbyRank(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends