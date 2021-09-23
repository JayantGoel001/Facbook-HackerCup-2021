#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin>>t;
	for (int _ = 1; _ <=t; _++) {
	    cout<<"Case #"<<_<<": ";
	    int n;
	    cin>>n;
	    char ar[n][n];
	    for(int i=0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            cin>>ar[i][j];
	        }
	    }
	    set<vector<pii>> x;
	    for(int i = 0;i<n;i++){
	       int cX = 0;
	       vector<pii> e;
	       for(int j = 0;j<n;j++){
	           if(ar[i][j] == 'X'){
	               cX++;
	           }
	           if(ar[i][j] == '.'){
	               e.push_back({i,j});
	           }
	       }
	       if(cX + e.size() == n){
	           x.insert(e);
	       }
	    }
	    for (int j = 0; j < n; j++) {
	       int cX = 0;
	       vector<pii> e;
	       for (int i = 0; i < n; i++) {
	           if(ar[i][j] == 'X'){
	               cX++;
	           }
	           if(ar[i][j] == '.'){
	               e.push_back({i,j});
	           }
	       }
	       if(cX + e.size() == n){
    	       x.insert(e);
	       }
	    }
	    int mini = INT_MAX;
	    for (auto i : x) {
	        int size = i.size();
	        mini = min(mini,size);
	    }
	    if(mini != INT_MAX){
	        int count = 0;
	        for (auto i : x) {
	            if(i.size() == mini){
	                count++;
	            }
	        }
	        cout<<mini<<" "<<count;
	    }else{
	        cout<<"Impossible";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}
