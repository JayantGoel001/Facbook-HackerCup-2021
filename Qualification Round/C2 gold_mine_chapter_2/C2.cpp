#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 50;
const int K = 50;

int dp[N + 1][3][K + 1];
int temp[3][K + 1];


void DFS(vector<int> *adj,int u,int previous,int *coins,int n,int k){
    dp[u][0][0] = 0;
    dp[u][2][1] = coins[u];
    
    for (auto it : adj[u]) {
        if(it != previous){
            
            DFS(adj,it,u,coins,n,k);
            memcpy(temp,dp[u],sizeof temp);
            
            for(int i = 0; i < 3; i++){
                for(int j = 0;j <= n; j++){
                    for(int l = 0; l < 3; l++){
                        for(int m = 0;m <= n; m++){
                            if(dp[u][i][j] >= 0 && dp[it][l][m] >= 0){
                              
                                if(j + m <= k){
                                    temp[i][j + m] = max(temp[i][j + m],dp[u][i][j] + dp[it][l][m]);
                                }
                              
                                if(j + m + 1 - (i == 1) - (l == 1) <= k){
                                    temp[i%2 + 1][j + m + 1 - (i == 1) - (l == 1)] = max(temp[i%2 + 1][j + m + 1 - (i == 1) - (l == 1)],dp[u][i][j] + dp[it][l][m] + (i == 0) * coins[u] + (l == 0) * coins[it]);
                                }
                            }
                        }
                    }
                }
            }
            
            memcpy(dp[u],temp,sizeof temp);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin>>t;
	for (int _ = 1; _ <=t; _++) {
	    cout<<"Case #"<<_<<": ";
	    int n,k;
	    cin>>n>>k;
	    int coins[n];
	    for (int i = 0; i <n; i++) {
	        cin>>coins[i];
	    }
	    vector<int> adj[n];
	    vector<pair<int,int>> contains1;
	    for (int i = 1; i < n; i++) {
	        int u,v;
	        cin>>u>>v;
	        u--;
	        v--;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    memset(dp,-1,sizeof dp);
	    
	    DFS(adj,0,-1,coins,n,k);
	    
	    int maxi = coins[0];
	    for (int i = 1; i < 3; i++) {
	        for(int j = 0;j <= k;j++){
	            maxi = max(maxi,dp[0][i][j]);
	        }
	    }
	    cout<<maxi;
	    cout<<"\n";
	}
	return 0;
}
