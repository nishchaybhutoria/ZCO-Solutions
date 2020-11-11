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

#define ll long long

int main()
{
    usaco();
    ll n, t;
    cin >> n >> t;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    gp_hash_table <ll, ll> cnt({},{},{},{},{1<<21});
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < k-1; ++i)
            if (a[i]+a[k-1] <= 1e6)
                ++cnt[a[i]+a[k-1]];
        for (int l = n-1; l > k; --l)
            if (a[k]+a[l] <= t)
                ans += cnt[t-(a[k]+a[l])];
    }
    cout << ans << '\n';
}
