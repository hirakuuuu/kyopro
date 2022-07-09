#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    string infilename = "A";
    string outfilename = "out.txt";
    ifstream reading_file(infilename);
    ofstream writing_file(outfilename);

    int n;
    
    while(reading_file >> n){
        if(n == 0) break;
        
        int ans = 0;
        vector<int> v(n);
        // コメント追加
        rep(i, 0, n){
            reading_file >> v[i];
        }
        rep(i, 1, n-1){
            if(v[i] > v[i-1] and v[i] > v[i+1]){
                ans++;
            }
        }
        writing_file << ans << endl;
    }
    
    return 0;
}