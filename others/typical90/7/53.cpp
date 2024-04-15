#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

/*
三分探索を前に手に入れた情報を使って、より少ない質問階数で適用できるようにしたい
https://qiita.com/tanaka-a/items/f380257328da421c6584　
フィボナッチ数列の形が現れるように分けてあげるとうまくいく（黄金分割探索）
*/

vector<int> idx(1601, -1);
vector<int> fib = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};

int ask(int pos){
    if(idx[pos] == -1){
        cout << "? " << pos << endl;
        int ans; cin >> ans;
        idx[pos] = ans;
        return ans;
    }
    return idx[pos];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        rep(i, 0, n+1) idx[i] = -1;
        rep(i, n+1, 1601) idx[i] = -i;
        int cl = 0, cr = 1597, dl = 610, dr = 987;
        int al = ask(dl), ar = ask(dr);
        if(al < ar){
            cl = dl, dl = dr, dr = -1, al = ar, ar = -1;
        }else{
            cr = dr, dr = dl, dl = -1, ar = al, al = -1;
        }
        rrep(i, 12, 0){
            if(dl == -1){
                dl = cl+fib[i];
                al = ask(dl);
            }
            if(dr == -1){
                dr = cr-fib[i];
                ar = ask(dr);
            }
            if(al < ar){
                cl = dl, dl = dr, dr = -1, al = ar, ar = -1;
            }else{
                cr = dr, dr = dl, dl = -1, ar = al, al = -1;
            }
        }
        int ans = -1;
        rep(i, cl+1, cr) chmax(ans, ask(i));
        cout << "! " << ans << endl;
    }
    return 0;
}