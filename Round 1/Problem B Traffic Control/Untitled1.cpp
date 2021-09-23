#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ofstream myfile;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
	int t;
	cin>>t;
    for(int _ = 1;_<=t;_++){
        cout<<"Case #"<<_<<": ";
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        int ar[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ar[i][j] = 1;
            }
        }
        ar[n - 1][0] = b - (n - 1) - (m - 1);
        ar[n - 1][m - 1] = a - (n - 1) - (m - 1);

        if(ar[n-1][0] > 0 && ar[n-1][m-1] > 0){
            cout<<"Possible\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<ar[i][j]<<" ";
                }
                cout<<"\n";
            }
        }else{
            cout<<"Impossible\n";
        }
    }
    cin.close();
    cout.close();
	return 0;
}
