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
    int n;
    cin >> n;
    vector <int> dp(n+1, 1e9), a(n);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int ok = 1;
            for (int k1 = i, k2 = j; k1 > k2; --k1, ++k2)
            {
                if (a[k1] != a[k2])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok) dp[i+1] = min(dp[i+1], dp[j]+1);
        }
    }
    cout << dp[n] << '\n';
}
