#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long

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

struct p {
    ll x, y;
    bool operator < (const p& a) {
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
};

int main()
{
    usaco();
    ll n, ans = 0, l = -1;
    cin >> n;
    vector <p> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y;
    sort(begin(v), end(v));
    for (auto i : v)
    {
        if (i.x > l)
        {
            ++ans;
            l = i.y;
        }
    }
    cout << ans << '\n';
}
