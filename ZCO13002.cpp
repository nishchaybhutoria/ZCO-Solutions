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

int main()
{
    usaco();
    ll n, m, x, y, z;
    cin >> n >> m;
    vector <vector <ll>> a(n, vector <ll> (n)), b(n, vector <ll> (n)), dp(n, vector <ll> (n));
    for (ll i = 0; i < n; ++i) for (ll j = 0; j < n; ++j) cin >> a[i][j];
    for (ll k = 0; k < m; ++k)
    {
        cin >> y >> x >> z;
        for (ll i = max(0LL, x-z-1); i < min(x+z, n); ++i)
            for (ll j = max(0LL, y-z-1); j < min(y+z, n); ++j)
                if (abs(j+1-y)+abs(i+1-x) <= z)
                    b[j][i] = 1;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = (b[i][j] ? a[i][j] : -1e12);
    dp[0][0] = b[0][0];
    for (int i = 1; i < n; ++i)
    {
        dp[0][i] = b[0][i]+dp[0][i-1];
        dp[i][0] = b[i][0]+dp[i-1][0];
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] = b[i][j]+max(dp[i-1][j], dp[i][j-1]);
    if (dp[n-1][n-1] < -250000000) cout << "NO\n";
    else cout << "YES\n" << dp[n-1][n-1] << '\n';
}
