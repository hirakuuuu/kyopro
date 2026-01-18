#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template <class T>
class FenwickTree {

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
public:
    FenwickTree() : _n(0) {}
    explicit FenwickTree(int n) : _n(n), data(n) {}

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        T tmp = sum(p+1)-sum(p);
        add(p, x-tmp);
    }

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while(p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

};


int main(){
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    int g = gcd(n, m);
    vector<vector<int>> a(g);
    vector<vector<int>> b(g);
    rep(i, 0, n){
        int A; cin >> A;
        a[i%g].push_back(A);
    }
    rep(i, 0, m){
        int B; cin >> B;
        b[i%g].push_back(B);
    }

    auto solve = [](vector<int> &A, vector<int> &B, ll K) -> mint {
        ll N = A.size(), M = B.size();
        vector<pair<int, int>> ord;
        ord.reserve(N+M);
        rep(i, 0, N) ord.push_back({A[i], (i+1)});
        rep(i, 0, M) ord.push_back({B[i], -(i+1)});
        sort(ord.rbegin(), ord.rend());

        vector<int> inv_mn(N), inv_nm(M);
        FenwickTree<mint> bit_a(N+N), bit_b(M+M);
        ll nm = N%M, mn = M%N;
        rep(i, 0, N){
            inv_mn[(mn*i)%N] = i;
        }
        rep(i, 0, M){
            inv_nm[(nm*i)%M] = i;
        }

        mint res = 0;
        mint cnt = K/(N*M);
        int cnt_a = 0, cnt_b = 0;
        rep(i, 0, N+M){
            auto [val, ind] = ord[i];
            // 全体が繰り返される部分について
            if(ind > 0){
                res += cnt*val*cnt_b;
            }else{
                res += cnt*val*cnt_a;
            }
            // res += cnt*val*i;

            // 最後の K%(N*M) 項について
            if(ind > 0){
                ind--;
                int st = inv_nm[ind%M];
                int len = (K%(N*M)-ind+N-1)/N;
                res += bit_b.sum(st, st+len)*val;
                bit_a.add(inv_mn[ind], 1);
                bit_a.add(inv_mn[ind]+N, 1);
                cnt_a++;
            }else{
                ind = -ind-1;
                int st = inv_mn[ind%N];
                int len = (K%(N*M)-ind+M-1)/M;
                res += bit_a.sum(st, st+len)*val;
                bit_b.add(inv_nm[ind], 1);
                bit_b.add(inv_nm[ind]+M, 1);
                cnt_b++;
            }
        }
        return res;
    };

    mint ans = 0;
    rep(i, 0, g){
        ll nk = k/g;
        if(k%g > i) nk++;
        ans += solve(a[i], b[i], nk);
    }
    cout << ans.val() << endl;
    return 0;
}