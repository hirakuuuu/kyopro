#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    string infilename = "J";
    string outfilename = "out.txt";
    ifstream reading_file(infilename);
    ofstream writing_file(outfilename);

    int n;
    
    while(reading_file >> n){
        if(n == 0) break;
        
        int ans = 0;
        // コメント追加
        rep(i, 0, n){
            int A; reading_file >> A;
            ans = max(A, ans);
        }
        writing_file << ans << endl;


    }
    
    return 0;
}