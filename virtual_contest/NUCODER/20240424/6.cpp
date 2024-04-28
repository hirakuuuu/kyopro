#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s; cin >> s;
    int total_q = 0, cnt_q = 0;
    mint cnt_a = 0, cnt_c = 0;
    rep(i, 0, s.size()){
        if(s[i] == 'C') cnt_c++;
        if(s[i] == '?') total_q++;
    }
    mint ans = 0;
    rep(i, 0, s.size()){
        if(s[i] == 'B'){
            ans += (cnt_a)*(cnt_c)*mint(3).pow(total_q);
            if(total_q-1 >= 0) ans += mint(cnt_q)*(cnt_c)*mint(3).pow(total_q-1);
            if(total_q-1 >= 0) ans += (cnt_a)*(total_q-cnt_q)*mint(3).pow(total_q-1);
            if(total_q-2 >= 0) ans += mint(cnt_q)*(total_q-cnt_q)*mint(3).pow(total_q-2);
        }else if(s[i] == '?'){
            if(total_q-1 >= 0) ans += (cnt_a)*(cnt_c)*mint(3).pow(total_q-1);
            if(total_q-2 >= 0) ans += mint(cnt_q)*(cnt_c)*mint(3).pow(total_q-2);
            if(total_q-2 >= 0) ans += (cnt_a)*(total_q-cnt_q-1)*mint(3).pow(total_q-2);
            if(total_q-3 >= 0) ans += mint(cnt_q)*(total_q-cnt_q-1)*mint(3).pow(total_q-3);
            cnt_q++;
        }else if(s[i] == 'A'){
            cnt_a++;
        }else if(s[i] == 'C'){
            cnt_c--;
        }
        // cout << i << ' ' << ans.val() << endl;
    }
    cout << ans.val() << endl;
    
    return 0;
}