#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = -1e18;

int n, q;
vector<int> g[N];
int val[N];

int parent[N], depth[N], sz[N];
int head[N], pos[N], arr[N];
int timer = 0;

struct SegmentTree {
    int st[N<<2];

    void build(int id,int l, int r) {
        if (l == r) {
            st[id] = val[arr[l]];
            return;
        }
        int mid = (l + r) >>1;
        build(id<<1, l, mid);
        build(id<<1|1, mid + 1, r);
        st[id] = max(st[id<<1], st[id<<1|1]);
    }

    void update(int id, int l, int r, int pos, int value) {
        if (l == r) {
            st[id] = value;
            return;
        }
        int mid = (l+r) >>1;
        if (pos <= mid) {
            update(id<<1, l, mid, pos, value);
        } else {
            update(id<<1|1, mid + 1, r, pos, value);
        }
        st[id] = max(st[id<<1], st[id<<1|1]);
    }

    int query(int id, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return INF;
        if (ql <= l && r <= qr) return st[id];
        int mid = (l + r) >>1;
        return max(query(id<<1, l, mid, ql, qr),
                   query(id<<1|1, mid + 1, r, ql, qr));
    }
} seg;

void dfs_size(int u, int par) {
    parent[u] = par;
    sz[u] = 1;

    for (int v : g[u]) {
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        dfs_size(v, u);
        sz[u] += sz[v];
    }
}

void dfs_hld(int u, int par, int h) {
    head[u] = h;
    pos[u] = ++timer;
    arr[timer] = u;

    int heavy_child = -1;
    int max_size = 0;

    for (int v : g[u]) {
        if (v == par) continue;
        if (sz[v] > max_size) {
            max_size = sz[v];
            heavy_child = v;
        }
    }

    if (heavy_child != -1) {
        dfs_hld(heavy_child, u, h);
    }

    for (int v : g[u]) {
        if (v == par || v == heavy_child) continue;
        dfs_hld(v, u, v);
    }
}

int query_path(int u, int v) {
    int result = INF;

    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) {
            swap(u, v);
        }
        result = max(result, seg.query(1, 1, n, pos[head[u]], pos[u]));
        u = parent[head[u]];
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    result = max(result, seg.query(1, 1, n, pos[u], pos[v]));

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[1] = 0;
    dfs_size(1, 0);
    dfs_hld(1, 0, 1);
    seg.build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int s, x;
            cin >> s >> x;
            seg.update(1, 1, n, pos[s], x);
            val[s] = x;
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) << " ";
        }
    }

    return 0;
}

