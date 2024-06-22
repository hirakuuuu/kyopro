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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int cnt = 0;
// ソートの関数をこれにすれば、nlogn 回の質問でソートにできる
bool f(int a, int b){
    assert(cnt < 25000);
    cout << "? " << a << ' ' << b << endl;
    cnt++;
    int q; cin >> q;
    return (bool)q;
}

int main(){
    int n; cin >> n;
    vector<int> index(n);
    iota(index.begin(), index.end(), 1);
    sort(index.begin(), index.end(), f);

    while(index.size() > 1){
        assert(cnt < 25000);
        cout << "+ " << index[0] << ' ' << index.back() << endl;
        cnt++;
        int p; cin >> p;
        index.pop_back();
        index.erase(index.begin());
        if(index.empty()) break;
        // l: p より真に小さいindex, r: p以上のindex
        int l = -1, r = index.size();
        while(r-l > 1){
            int mid = (l+r)/2;
            if(f(index[mid], p)) l = mid;
            else r = mid;
        }
        index.insert(index.begin()+r, p);
    }

    cout << '!' << endl;

    return 0;
}