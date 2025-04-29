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


int main(){
    int H, W; cin >> H >> W;
    vector<int> e(3);
    rep(i, 0, 3) cin >> e[i];
    vector<string> s(H);
    int sh, sw, gh, gw;
    rep(i, 0, H){
        cin >> s[i];
        rep(j, 0, W){
            if(s[i][j] == 'S') sh = i, sw = j;
            if(s[i][j] == 'G') gh = i, gw = j;
        }
    }

    vector<vector<int>> acc(H+1, vector<int>(W+1));
    rep(i, 1, H+1){
        rep(j, 1, W+1){
            acc[i][j] = acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
            if(s[i-1][j-1] == '#') acc[i][j]++;
        }
    }

    auto calc_sum = [&](int si, int sj, int ti, int tj) -> int {
        return acc[ti][tj]-acc[ti][sj]-acc[si][tj]+acc[si][sj];
    };

    vector<vector<int>> state;
    {
        vector<int> id(3);
        iota(id.begin(), id.end(), 0);
        do{
            state.push_back(id);
        }while(next_permutation(id.begin(), id.end()));
    }

    struct State
    {
        int eid;
        int pu, pl;
        State(int _eid, int _pu, int _pl){
            eid = _eid;
            pu = _pu;
            pl = _pl;
        }
        State(){};
    };

    auto rev_eid = [&](int i, int j, int k) -> int {
        rep(l, 0, 6){
            if(state[l][0] == i && state[l][1] == j && state[l][2] == k){
                return l;
            }
        }
    };
    
    
    queue<pair<int, State>> que;
    auto is_start = [&](int si, int sj, int ti, int tj) -> bool {
        return (inr(si, sh, ti) && inr(sj, sw, tj));
    };
    rep(j, 0, 6){
        int idh = -1, idw = -1;
        rep(i, 0, 3){
            if(state[j][i] == 0) idh = i;
            if(state[j][i] == 1) idw = i;
        }
        // cout << idh << ' ' << idw << endl;
        rep(si, 0, H){
            rep(sj, 0, W){
                if(
                    si+e[idh] <= H && sj+e[idw] <= W 
                     && is_start(si, sj, si+e[idh], sj+e[idw]) 
                    && calc_sum(si, sj, si+e[idh], sj+e[idw]) == 0){
                    State new_state(j, si, sj);
                        que.push({0, new_state});
                    }
            }
        }
    }

    int ans = IINF;
    auto is_goal = [&](int si, int sj, int ti, int tj) -> bool {
        return (inr(si, gh, ti) && inr(sj, gw, tj));
    };
    map<tuple<int, int, int>, bool> seen;

    while(!que.empty()){
        auto [d, tmp] = que.front(); que.pop();
        int idh = -1, idw = -1, idn = -1;
        rep(i, 0, 3){
            if(state[tmp.eid][i] == 0) idh = i;
            if(state[tmp.eid][i] == 1) idw = i;
            if(state[tmp.eid][i] == 2) idn = i;
        }
        cout << tmp.pl << ' ' << tmp.pu << ' ' << e[idh] << ' ' << e[idw] << endl;
        // 右
        {   
            // [tmp.pu, tmp.pl+e[idw]] ~ [tmp.pu+e[idh], tmp.pl+e[idw]+e[idn]]
            if(tmp.pl+e[idw]+e[idn] <= W && calc_sum(tmp.pu, tmp.pl+e[idw], tmp.pu+e[idh], tmp.pl+e[idw]+e[idn]) == 0){
                State new_state(tmp.eid, tmp.pu, tmp.pl+e[idw]);
                swap(idw, idn);
                new_state.eid = rev_eid(idh, idw, idn);
                if(seen[{new_state.eid, new_state.pu, new_state.pl}]) continue;
                seen[{new_state.eid, new_state.pu, new_state.pl}] = true;
                
                if(is_goal(tmp.pu, tmp.pl+e[idw], tmp.pu+e[idh], tmp.pl+e[idw]+e[idn])) chmin(ans, d+1);

                que.push({d+1, new_state});
            }
        }
        // 左
        {   
            // [tmp.pu, tmp.pl-e[idn]] ~ [tmp.pu+e[idh], tmp.pl]
            if(0 <= tmp.pl-e[idn]  && calc_sum(tmp.pu, tmp.pl-e[idn], tmp.pu+e[idh], tmp.pl) == 0){
                State new_state(tmp.eid, tmp.pu, tmp.pl-e[idn]);
                swap(idw, idn);
                new_state.eid = rev_eid(idh, idw, idn);
                if(seen[{new_state.eid, new_state.pu, new_state.pl}]) continue;
                seen[{new_state.eid, new_state.pu, new_state.pl}] = true;
                if(is_goal(tmp.pu, tmp.pl-e[idn], tmp.pu+e[idh], tmp.pl)) chmin(ans, d+1);
                que.push({d+1, new_state});
            }
        }

        // 下
        {   
            if(tmp.pu+e[idh]+e[idn] <= H && calc_sum(tmp.pu+e[idh], tmp.pl, tmp.pu+e[idh]+e[idn], tmp.pl+e[idw]) == 0){
                State new_state(tmp.eid, tmp.pu+e[idh], tmp.pl);
                swap(idh, idn);
                new_state.eid = rev_eid(idh, idw, idn);
                if(seen[{new_state.eid, new_state.pu, new_state.pl}]) continue;
                seen[{new_state.eid, new_state.pu, new_state.pl}] = true;
                if(is_goal(tmp.pu+e[idh], tmp.pl, tmp.pu+e[idh]+e[idn], tmp.pl+e[idw])) chmin(ans, d+1);
                que.push({d+1, new_state});
            }
        }
        // 下
        {   
            // [tmp.pu, tmp.pl-e[idn]] ~ [tmp.pu+e[idh], tmp.pl]
            if(0 <= tmp.pu-e[idn] && calc_sum(tmp.pu-e[idn], tmp.pl, tmp.pu, tmp.pl+e[idw]) == 0){
                State new_state(tmp.eid, tmp.pu-e[idn], tmp.pl);
                swap(idh, idn);
                new_state.eid = rev_eid(idh, idw, idn);
                if(seen[{new_state.eid, new_state.pu, new_state.pl}]) continue;
                seen[{new_state.eid, new_state.pu, new_state.pl}] = true;
                if(is_goal(tmp.pu-e[idn], tmp.pl, tmp.pu, tmp.pl+e[idw])) chmin(ans, d+1);
                que.push({d+1, new_state});
            }
        }

    }
    cout << ans << endl;

    
    return 0;
}