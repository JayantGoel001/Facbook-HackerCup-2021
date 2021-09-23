#include <bits/stdc++.h>
using namespace std;

int cti(char ch){
    return (int)(ch - 'A');
}

int minDist(list<int> *adj,int u,int v){
    vector<bool> isVisited(26,false);
    
    vector<int> distance(26,INT_MAX);
    
    queue<int> q;
    distance[u] = 0;
    
    q.push(u);
    
    isVisited[u] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for (auto i : adj[x]) {
            if(!isVisited[i]){
                distance[i] = distance[x] + 1;
                q.push(i);
                isVisited[i] = true;
            }
        }
    }
    return distance[v];
}
int main() {
	int t;
	cin>>t;
	for (int _ = 1; _ <=t; _++) {
	    cout<<"Case #"<<_<<": ";
	    string str;
	    cin>>str;
	    
	    int n;
	    cin>>n;
	    
	    list<int> adj[26];
	    
	    for (int k = 0; k <n; k++) {
	        string s;
	        cin>>s;
	        
	        int u = cti(s[0]);
	        int v = cti(s[1]);
	        
	        adj[u].push_back(v);
	    }
	    
	    int size = str.size();
	    int mini = INT_MAX;
	    for (int i = 0; i < 26; i++) {
	        int count = 0;
	        for(int j = 0; j<size; j++){
	            int u = cti(str[j]);
	            int v = i;
	            int dist = minDist(adj,u,v);
	            if(dist == INT_MAX){
	                count = INT_MAX;
	                break;
	            }
	            count += dist;
	        }
	        mini = min(mini,count);
	    }
	    if(mini == INT_MAX){
	        cout<<"-1\n";
	    }else{
    	    cout<<mini<<"\n";
	    }
	}
	return 0;
}
