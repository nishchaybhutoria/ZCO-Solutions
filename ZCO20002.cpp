#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
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

const int mod = 1e8+7;

signed main()
{
    usaco();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        int a[n+1] = {-1};
        int b[n+1] = {-1};
        for (int i = 0; i < n; ++i) cin >> a[i+1];
        for (int i = 0; i < m; ++i) cin >> b[i+1];
        int dp[n+1][m+1][x+1][2];
        // dp[i][j][k][l] is the number of ways to interleave the first i elements of a with the first j elements of b to form k blocks
        // l is 0 if the element is from a, or else it is 1
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= x; ++k)
                    dp[i][j][k][0] = dp[i][j][k][1] = 0;
        dp[1][0][1][0] = 1;
        dp[0][1][1][1] = 1;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                for (int k = 1; k <= x; ++k)
                {
                    if (i)
                    {
                        if (a[i] == a[i-1]) dp[i][j][k][0] += dp[i-1][j][k][0];
                        else dp[i][j][k][0] += dp[i-1][j][k-1][0];
                        if (a[i] == b[j]) dp[i][j][k][0] += dp[i-1][j][k][1];
                        else dp[i][j][k][0] += dp[i-1][j][k-1][1];
                    }
                    if (j)
                    {
                        if (b[j] == b[j-1]) dp[i][j][k][1] += dp[i][j-1][k][1];
                        else dp[i][j][k][1] += dp[i][j-1][k-1][1];
                        if (a[i] == b[j]) dp[i][j][k][1] += dp[i][j-1][k][0];
                        else dp[i][j][k][1] += dp[i][j-1][k-1][0];
                    }
                    dp[i][j][k][0] %= mod;
                    dp[i][j][k][1] %= mod;
                }
            }
        }
        cout << (dp[n][m][x][0]+dp[n][m][x][1]) % mod << '\n';
    }
}
