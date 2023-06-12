//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
            if (source.first == destination.first &&
            source.second == destination.second)
                return 0;

        queue<pair<int,pair<int,int>>>q; //dist,row,col;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        q.push({0,{source.first,source.second}});
        
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int n_row = row+dr[i];
                int n_col = col+dc[i];
                
                if(n_row>=0&&n_row<m&&n_col>=0&&n_col<n&&grid[n_row][n_col]==1){
                    if(dis+1<dist[n_row][n_col]){
                        dist[n_row][n_col] = 1 + dis;
                        if(n_row==destination.first&&n_col==destination.second)
                            return dis+1;
                        q.push({dis+1,{n_row,n_col}});
                    }
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends