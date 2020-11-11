#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    vector <int> a(n), dp(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n < 3)
    {
        cout << "0\n";
        return 0;
    }
    dp[0] = a[0], dp[1] = a[1], dp[2] = a[2];
    for (int i = 3; i < n; ++i) dp[i] = a[i]+min({dp[i-1], dp[i-2], dp[i-3]});
    cout << min({dp[n-1], dp[n-2], dp[n-3]}) << '\n';
}
