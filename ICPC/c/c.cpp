#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

ll renshu(ll x){
    return x*x;
}

ll kyusoku(ll x){
    return -x*x;
}

int main(){
    string infilename = "C";
    string outfilename = "out.txt";
    ifstream reading_file(infilename);
    ofstream writing_file(outfilename);

    ll n, m;
    
    while(reading_file >> n >> m){
        if(n == 0 and m == 0) break;
        ll ans = -(1LL<<60);

        if(!n or !m){
            ans = n*n-m*m;
        }else{
            rep(i, 1, n+1){
                ll cnt = 0;
                cnt += renshu(n-i+1)+(i-1);
                cnt += (i+1-m%(i+1))*kyusoku(m/(i+1))+(m%(i+1))*kyusoku(m/(i+1)+1);
                if(cnt >= ans){
                    ans = cnt;
                }else{
                    break;
                }
            }
        }
        writing_file << ans << endl;
    }
    
    return 0;
}