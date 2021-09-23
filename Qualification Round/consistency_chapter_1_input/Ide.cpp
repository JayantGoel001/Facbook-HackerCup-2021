#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for (int _ = 1; _ <= t; _++) {
	    cout<<"Case #"<<_<<": ";
	    
	    string str;
	    cin>>str;
	    
	    map<char,int> mpv,mpc;
	    
	    for (int i = 0; i < str.size(); i++) {
	        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I'  || str[i] == 'O' || str[i] == 'U'){
	            mpv[str[i]]++;
	        }else{
	            mpc[str[i]]++;
	        }
	    }
	    
	    char maxV = 'A';
	    char maxC = 'Z';
	    
	    for (auto i : mpv) {
	        if(mpv[maxV] < i.second){
	            maxV = i.first;
	        }
	    }
	    
	    for (auto i : mpc) {
	        if(mpc[maxC] < i.second){
	            maxC = i.first;
	        }
	    }
	    
	    int vc = 0;
	    for (auto i : mpv) {
	        vc += i.second;
	    }
	    
	    for (auto i : mpc) {
	        if(i.first != maxC){
	            vc += 2 * i.second;
	        }
	    }
	    
	    
	    int cv = 0;
	    for (auto i : mpc) {
	        cv += i.second;
	    }
	    
	    for (auto i : mpv) {
	        if(i.first != maxV){
	            cv += 2 * i.second;
	        }
	    }
	    cout<<min(vc,cv);
	    cout<<"\n";
	}
	
	return 0;
}
