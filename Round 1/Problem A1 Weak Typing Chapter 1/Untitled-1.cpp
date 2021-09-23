#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ofstream myfile;
    ifstream is("weak_typing_chapter_1_input.txt");
    ofstream out("output.txt");
	int t;
	is>>t;
    for(int _ = 1;_<=t;_++){
        out<<"Case #"<<_<<": ";
        int n;
        is>>n;
        string str;
        is>>str;

        char prev = str[0];
        int count = 0;
        for(int i=1;i<n;i++){
            if(str[i]=='F'){
                continue;
            }else{
                if(prev!='F' && prev != str[i]){
                    count++;
                }
                prev = str[i];
            }
        }
        out<<count<<"\n";
    }
    is.close();
    out.close();
	return 0;
}
