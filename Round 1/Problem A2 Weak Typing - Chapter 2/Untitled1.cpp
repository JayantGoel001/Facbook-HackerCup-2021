#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int MOD = 1000000007;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ofstream myfile;
    ifstream is("input.txt");
    ofstream out("output.txt");
	int t;
	is>>t;
    for(int _ = 1;_<=t;_++){
        out<<"Case #"<<_<<": ";
        int n;
        is>>n;
        string str;
        is>>str;

        vector<char> v;
        vector<int> index;

        for(int i=0;i<n;i++){
            if(str[i]!='F'){
                v.push_back(str[i]);
                index.push_back(i);
            }
        }
        int count = 0;
        int size = v.size();
        for(int i=0;i<size-1;i++){
            if(v[i]!=v[i+1]){
                count = (count + (index[i] + 1) * (n - index[i+1]))%MOD;
            }
        }

        out<<count<<"\n";
    }
    is.close();
    out.close();
	return 0;
}
