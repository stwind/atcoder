#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

class LazySegTree {
public:
    int n = 1, h;
    VLL data, lazy;

    LazySegTree(int N) {
        while (n < N) n *= 2;
        data.resize(2 * n);
        lazy.resize(2 * n);
        h = sizeof(int) * 8 - __builtin_clz(n);
    }

    void apply(int i, LL val) {
        data[i] += val;
        if (i < n) lazy[i] += val;
    }

    void build(int i) {
        while (i > 1) {
            i >>= 1;
            data[i] = max(data[i << 1], data[i << 1 | 1]) + lazy[i];
        }
    }

    void incr(int l, int r, LL val) {
        l += n; r += n;
        int l0 = l, r0 = r;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, val);
            if (r & 1) apply(--r, val);
        }
        build(l0);
        build(r0 - 1);
    }

    void push(int p) {
        for (int s = h; s > 0; s--) {
            int i = p >> s;
            if (lazy[i] != 0) {
                apply(i << 1, lazy[i]);
                apply(i << 1 | 1, lazy[i]);
                lazy[i] = 0;
            }
        }
    }

    LL query(int l, int r) {
        l += n; r += n;
        push(l);
        push(r - 1);
        LL res = LONG_MIN;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, data[l++]);
            if (r & 1) res = max(res, data[--r]);
        }
        return res;
    }
};

int main() {
    IOS;

    int N, M;
    cin >> N >> M;
    unordered_map<int, VI> add;
    unordered_map<int, vector<pair<int, int>>> del;
    int l, r, a;
    forn(i, 0, M) {
        cin >> l >> r >> a;
        add[l].push_back(a);
        del[r].push_back(make_pair(l, a));
    }

    LazySegTree seg(N);
    LL res = 0;
    for (int k = 1; k <= N; k++) {
        for (auto a: add[k])
            seg.incr(0, k, a);

        LL mx = seg.query(0, k);
        res = max(res, mx);
        seg.incr(k, k + 1, mx);

        for (auto d: del[k])
            seg.incr(0, d.first, -d.second);
    }

    cout << res << endl;

    return 0;
}
