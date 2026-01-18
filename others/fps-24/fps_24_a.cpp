#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

// =============== Formal Power Series Library =============== //
template <typename Mint>
struct FormalPowerSeries : vector<Mint> {
    // FPS のメンバ関数群の中に入れる（FormalPowerSeries<Mint> の中に書く）
    private:
    static vector<Mint> convolution_fps(const vector<Mint>& a, const vector<Mint>& b, int max_deg = -1) {
        if (a.empty() || b.empty()) return {};
        // a, b を整数ベクタに変換
        vector<long long> aa(a.size()), bb(b.size());
        for (size_t i = 0; i < a.size(); ++i) aa[i] = (long long)a[i].val();
        for (size_t i = 0; i < b.size(); ++i) bb[i] = (long long)b[i].val();

        // atcoder::convolution を呼ぶ
        auto cc = atcoder::convolution(aa, bb); // cc は vector<long long>

        int need = (int)cc.size();
        if (max_deg >= 0) need = min(need, max_deg + 1);
        vector<Mint> res(need);
        for (int i = 0; i < need; ++i) res[i] = Mint(cc[i]); // Mint(long long) で mod 化される
        return res;
    }

public:
    using vector<Mint>::vector;
    using FPS = FormalPowerSeries;
    
    FPS& operator+=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];
        return *this;
    }
    FPS& operator-=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];
        return *this;
    }
    FPS& operator*=(const FPS& r) {
        auto tmp = convolution_fps(static_cast<const vector<Mint>&>(*this), static_cast<const vector<Mint>&>(r));
        this->assign(tmp.begin(), tmp.end());
        return *this;
    }
    FPS operator+(const FPS& r) const { return FPS(*this) += r; }
    FPS operator-(const FPS& r) const { return FPS(*this) -= r; }
    FPS operator*(const FPS& r) const { return FPS(*this) *= r; }

    // 多項式を次数 max_deg に切り詰める
    void shrink(int max_deg) {
        if ((int)this->size() > max_deg + 1) this->resize(max_deg + 1);
    }

    // 多項式の累乗（2分累乗）
    FPS pow(long long e, int max_deg) const {
        FPS base = *this, res = {1};
        while (e > 0) {
            if (e & 1) {
                res *= base;
                res.shrink(max_deg);
            }
            e >>= 1;
            if (e) {
                base *= base;
                base.shrink(max_deg);
            }
        }
        return res;
    }
};
// ============================================================ //

int main() {
    int d, n; cin >> d >> n;
    using FPS = FormalPowerSeries<mint>;

    FPS f(7);
    f[1] = 1;
    f[3] = 1;
    f[4] = 1;
    f[6] = 1;

    FPS g = f.pow(d, n);
    mint ans = 0;
    if ((int)g.size() > n) ans = g[n];

    cout << ans.val() << '\n';
    return 0;
}
