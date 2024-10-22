#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

void Z_algorithm(const string &s, vector<int> &a) {
	int sz = (int)s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz && (s[j] == s[i + j] || s[j] == '?' || s[i+j] == '?'))++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz&&k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

int main(){
    vector<string> a(3);
    rep(i, 0, 3) cin >> a[i];


    auto merge_string = [&](string s, string t) -> vector<string> {
        vector<string> res;
        int n = (int)s.size(), m = (int)t.size();
        rep(i, 0, n+1){
            bool ok = true;
            string tmp = s;
            rep(j, i, n){
                if(j-i >= m) continue;
                if(s[j] != t[j-i]){
                    if(s[j] != '?' && t[j-i] != '?') ok = false;
                    if(s[j] == '?') tmp[j] = t[j-i]; // 帰れるなら t の方に変えておく
                }
            }
            if(!ok) continue;
            if(inr(0, n-i, m)) tmp += t.substr(n-i);
            res.push_back(tmp);
        }
        return res;
    };

    int ans = IINF;
    rep(i, 0, 3){
        rep(_, 0, 2){
            vector<string> res1 = merge_string(a[(i+1)%3], a[(i+2)%3]);
            for(auto na: res1){
                // na と a[i] をいくつかぶせられるか
                // z アルゴリズム
                string tmp = a[i]+na;
                int tot = (int)(a[i].size()+na.size());
                vector<int> cnt;
                Z_algorithm(tmp, cnt);
                rep(j, (int)a[i].size(), tot){
                    if((int)a[i].size() <= tot-j){
                        // a[i] がすっぽり埋まるパターン
                        if(cnt[j] >= (int)a[i].size()) chmin(ans, (int)na.size());
                    }else{
                        // a[i] がはみ出るパターン
                        if(cnt[j] >= tot-j) chmin(ans, j);
                    }
                }
                cout << na << ' ' << a[i] << ' ' << ans << endl;
                cout << tmp << endl;
                rep(j, 0, tot){
                    cout << tmp.substr(j) << ' ' << cnt[j] << endl;
                }
                return 0;
            }
            swap(a[(i+1)%3], a[(i+2)%3]);
        }
    }
    cout << ans << endl;

    
    return 0;
}