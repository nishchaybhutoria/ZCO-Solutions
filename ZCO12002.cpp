#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define f first
#define s second

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    usaco();
    ll n, x, y, ans = 1e18, z;
    cin >> n >> x >> y;
    vector <pair<ll, ll>> a(n);
    oset <ll> v, w;
    for (int i = 0; i < n; ++i) cin >> a[i].f >> a[i].s;
    for (int i = 0; i < x; ++i)
    {
        cin >> z;
        v.insert(z);
    }
    for (int i = 0; i < y; ++i)
    {
        cin >> z;
        w.insert(z);
    }
    for (auto i : a)
    {
        ll p = w.order_of_key(i.s);
        ll q = v.order_of_key(i.f+1);
        p = (p == y ? p-1 : p);
        q = (q != 0 ? q-1 : q);
        ll c = (*(w.find_by_order(p)));
        ll d = (*(v.find_by_order(q)));
        if (c < i.s || d > i.f || c < d) continue;
        ans = min(ans, c-d+1);
    }
    cout << ans << '\n';
}
