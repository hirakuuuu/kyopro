#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://yukicoder.me/problems/no/5020

const int TIME_LIMIT = 990;
constexpr ll base = 5e17;
const double start_temp = 1000, end_temp = 1;

int main(){
    auto start_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    random_device seed_gen;
    mt19937 engine(seed_gen());
    int n; cin >> n;
    vector<pair<ll, ll>> card(n), init(n);
    rep(i, 0, n){
        ll a, b; cin >> a >> b;
        card[i] = {a, b};
        init[i] = {a, b};
    }
    vector<ll> ope(n-1);
    iota(ope.begin(), ope.end(), 1);

    // スコア
    auto score = [&](pair<ll, ll> card_) -> ll {
        return (ll) max(abs(card_.first-base), abs(card_.second-base));
    };

    // 操作
    auto simulation = [&](vector<ll> &ope_) -> ll {
        vector<pair<ll, ll>> card_ = init;
        for(auto v: ope_){
            auto [a, c] = card_[0];
            auto [b, d] = card_[v];
            card_[0] = {(a+b)/2, (c+d)/2};
            card_[v] = {(a+b)/2, (c+d)/2};
        }
        return score(card_[0]);
    };

    ll best_score = simulation(ope);
    constexpr int ope_size = 44;

    // 焼き鈍し
    int cnt = 0;
    int f1 = 0, f2 = 0;
    while(true){
        auto now_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        if(now_time-start_time >= TIME_LIMIT) break;
        vector<ll> new_ope = ope;
        int u = engine()%ope_size, v = engine()%ope_size;
        while(u == v) v = engine()%ope_size;
        swap(new_ope[u], new_ope[v]);
        ll new_score = simulation(new_ope);
        // 温度関数
        // 遷移確率関数(最大化の場合)
        double prob = exp((log10(best_score)-log10(new_score))/0.2);
        // 確率probで遷移する
        if (prob > (engine()%IINF)/(double)IINF) { 
            swap(ope, new_ope);
            swap(best_score, new_score);
        }
        cnt++;
        f2 ^= f1;
        f1 ^= 1;
    }

    //cout << simulation(ope) << ' ' << cnt << endl;
    // 出力
    cout << ope.size() << endl;
    for(auto v: ope){
        cout << 1 << ' ' << v+1 << endl;
    }
    return 0;
}