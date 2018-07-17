#include <bits/stdc++.h>

using namespace std;

const int max4 = 10004;
const int maxx = 100005;
const int lg5 = 17;

int n, q, arr[maxx];
string type; int iq, jq, xq;

int root[maxx], id = 0, nxt = 0;

struct node {
    int l, r, val;
} tree[2 * lg5 * maxx];

void build(int &v, int l, int r) {
    v = ++nxt;
    if (l == r) {
        tree[v].val = arr[r], tree[v].l = tree[v].r = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(tree[v].l, l, mid);
    build(tree[v].r, mid + 1, r);
}

void update(int &v, int par, int l, int r, int i, int val) {
    v = ++nxt, tree[v] = tree[par];
    if (l == r) {
        tree[v].val = val, tree[v].l = tree[v].r = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        update(tree[v].l, tree[par].l, l, mid, i, val);
    } else {
        update(tree[v].r, tree[par].r, mid + 1, r, i, val);
    }
}

int query(int v, int l, int r, int i) {
    if (l == r) {
        return tree[v].val;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        return query(tree[v].l, l, mid, i);
    }
    return query(tree[v].r, mid + 1, r, i);
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(root[++id], 1, n);
    cin >> q;
    while(q --) {
        cin >> type;
        if (type[0] == 'c') {
            cin >> iq >> jq >> xq;
            update(root[++id], root[iq], 1, n, jq, xq);
        } else {
            cin >> iq >> jq;
            cout << query(root[iq], 1, n, jq) << endl;
        }
    }
    return 0;
}
