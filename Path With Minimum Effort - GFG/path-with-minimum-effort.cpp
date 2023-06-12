//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row==m-1 && col==n-1) return dis;
            for(int i=0;i<4;i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n){
                    int nValue = max(dis,abs(heights[nr][nc]-heights[row][col]));
                    if(dist[nr][nc]>nValue){
                        dist[nr][nc]=nValue;
                        pq.push({nValue,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends