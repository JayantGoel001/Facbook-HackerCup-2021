#include <bits/stdc++.h>
#define int unsigned long long int
using namespace std;
vector<bool> included(51,false);
void findAllPathUtil(vector<int> *adj,int u,int v,vector<bool> &isVisited,vector<int> &path,vector<vector<int>> &allPaths){
    
    isVisited[u] = true;
    path.push_back(u);
    
    if(u == v){
        allPaths.push_back(path);
    }else{
        for (auto it : adj[u]) {
            if(!isVisited[it] && !included[it]){
                findAllPathUtil(adj,it,v,isVisited,path,allPaths);
            }
        }
    }
    
    path.pop_back();
    isVisited[u] = false;
}

vector<vector<int>> findAllPath(vector<int> *adj,int u,int v,int n){
    vector<bool> isVisited(n+1,false);
    
    vector<int> path;
    vector<vector<int>> allPaths;
    
    findAllPathUtil(adj,u,v,isVisited,path,allPaths);
    
    return allPaths;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin>>t;
	for (int _ = 1; _ <=t; _++) {
	    cout<<"Case #"<<_<<": ";
	    int n;
	    cin>>n;
	    int coins[n+1];
	    for (int i = 1; i <=n; i++) {
	        cin>>coins[i];
	    }
	    if(n>1){
    	    vector<int> adj[n + 1];
    	    vector<pair<int,int>> contains1;
    	    for (int i = 1; i < n; i++) {
    	        int u,v;
    	        cin>>u>>v;
    	        adj[u].push_back(v);
    	        adj[v].push_back(u);
    	    }
    	    vector<vector<int>> dp[n+1];
            for(int j = 1; j<=n; j++){
                dp[j] = findAllPath(adj,1,j,n);
            }
    	    vector<int> maxPath;
    	    int maxSum = 0;
    	    for (int i = 1; i <=n; i++) {
    	        for (auto it : dp[i]) {
    	            int sum = 0;
    	            for (auto it2 : it) {
    	                sum += coins[it2];
    	            }
    	            if(sum > maxSum){
    	                maxSum = sum;
    	                maxPath = it;
    	            }
    	        }
    	    }
    	    
    	    int src = maxPath[maxPath.size() - 1];
    	    
    	    for (int i = 1; i < maxPath.size(); i++) {
    	        included[maxPath[i]] = true;
    	    }
    	    
    	    adj[src].clear();
    	    
    	    for (int i = 1; i <=n; i++) {
    	        if(i != src && !included[i]){
    	            adj[src].push_back(i);
    	        }
    	    }
            vector<vector<int>> allPaths = findAllPath(adj,src,1,n);
            included[1] = true;
            
    	    int maxSum2 = 0;
    	    for (auto it : allPaths) {
    	        int sum = 0;
    	        for(int i = 0;i<it.size();i++){
    	            if(!included[it[i]]){
    	                sum += coins[it[i]];
    	            }
    	        }
    	        maxSum2 = max(maxSum2,sum);
    	    }
    	    cout<<maxSum+maxSum2;
    	    for(int i = 0;i<=50;i++){
    	        included[i] = false;
    	    }
	    }else{
	        cout<<coins[1];
	    }
	    cout<<"\n";
	}
	return 0;
}
