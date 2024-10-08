#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const ll N = 1000000000;

int main(){
    int q = 64;
    map<ll, bool> memo;
    // Yes -> true, No -> false
    auto query = [&](ll n) -> bool {
        // すでに質問済みであれば、新たに質問はしない
        if(memo.find(n) != memo.end()) return memo[n];

        // まだ聞いていない数字を聞く
        q--;
        assert(q >= 0);
        cout << "? " << n << endl;
        char res; cin >> res;
        return memo[n] = (res == 'Y'); 
    };

    auto test_query = [&](ll n) -> bool {
        if(n <= N && to_string(n) <= to_string(N)) return true;
        if(n > N && to_string(n) > to_string(N)) return true;
        return false;
    };

    // 桁を特定するためのクエリ用の数字を作る関数
    auto f = [&](ll n) -> ll {
        string s = to_string(n);
        assert(s.size() <= 9);
        while(s.size() < 9) s += '9';
        ll res = stol(s);
        res *= 1e9;
        res++;
        return res;
    };

    auto all_nine = [&](ll n) -> bool {
        string s = to_string(n);
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        return s == "9";
    };

    ll ans = 0;
    // N = 1e9 の判定
    if(query(1e9) && !query(1e8+1)){
        ans = 1e9;
        cout << "! " << ans << endl;
        return 0;
    }

    // 上の桁から決定する
    // 桁数が同じなら、どれでもYES
    // そうでなければ、該当する数字までがYESになるので、その境目を調べる
    // 9 のときめんどくさい
    {
        ll l = 0, r = 10;
        while(r-l > 1){
            ll mid = (l+r)/2;
            ll tmp = f(mid);
            if(query(tmp)) r = mid;
            else l = mid;
        }
        // r が最初の桁
        ans += r;
    }


    while(to_string(ans).size() < 9){ // 9 桁になったら確定
        // この数字で確定しているかどうか
        if(all_nine(ans)){
            if(query(ans*1e9) && !query(ans+1)){
                cout << "! " << ans << endl;
                return 0;
            }
        }else{
            if(query(ans*1e9) && query(ans+1)){
                cout << "! " << ans << endl;
                return 0;
            }
        }

        ll l = -1, r = 10;
        while(r-l > 1){
            ll mid = (l+r)/2;
            ll tmp = f(ans*10+mid);
            if(query(tmp)) r = mid;
            else l = mid;
        }
        // cout << ans << ' ' << r << endl;
        ans = ans*10+r;
    }
    cout << "! " << ans << endl;
    return 0;
}