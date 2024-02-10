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
// https://atcoder.jp/contests/abc140/tasks/abc140_f

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

int main(){
    int n; cin >> n;
    vector<int> s((1<<n));
    rep(i, 0, 1<<n) cin >> s[i];
    comp(s);
    vector<int> cnt(1<<n);
    rep(i, 0, 1<<n){
        cnt[s[i]]++;
    }
    set<int> t(s.begin(), s.end());

    multiset<int> ms;
    int mx = *t.rbegin();
    ms.insert(mx);
    cnt[mx]--;
    if(cnt[mx] == 0) t.erase(mx);

    rep(i, 0, n){
        multiset<int> ms_ = ms;
        for(auto p: ms){
            auto itr = t.upper_bound(p-1);
            if(itr == t.begin()){
                cout << "No" << endl;
                return 0;
            }
            --itr;
            ms_.insert(*itr);
            cnt[*itr]--;
            if(cnt[*itr] == 0) t.erase(*itr);
        }
        swap(ms, ms_);
    }
    cout << "Yes" << endl;
    
    return 0;
}