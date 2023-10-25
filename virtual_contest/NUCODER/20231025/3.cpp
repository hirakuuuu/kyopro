#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n, a; cin >> n >> a;
    a--;
    string k; cin >> k;
    vector<int> b(n); 
    rep(i, 0, n){
        cin >> b[i];
        b[i]--;
    }

    vector<ll> seen(n);
    int tmp = a;
    vector<int> roop = {a};
    while(!seen[tmp]){
        seen[tmp] = true;
        tmp = b[tmp];
        if(!seen[tmp]) roop.push_back(tmp);
    }

    int l = 0;
    while(roop[l] != tmp) l++;
    ll mk = 0, m = roop.size()-l, ten = 1;
    rrep(i, k.size()-1, 0){
        mk += (k[i]-'0')*ten;
        mk %= m;
        ten *= 10;
        ten %= m;
    }

    string sl = to_string(l);
    if(k.size() < sl.size() || (k.size() == sl.size() && k < to_string(l))){
        cout << roop[stoi(k)]+1 << endl;
    }else{
        
        cout << roop[l+(mk+m-l%m)%m]+1 << endl;
    }
    
    return 0;
}