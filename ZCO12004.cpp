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
    vector <long long> a1(n), a2(n), dp1(n), dp2(n);
    for (int i = 0; i < n; ++i) cin >> a1[i];
    a2 = a1;
    reverse(begin(a2), end(a2));
    if (n == 1) cout << a1[0] << '\n';
    if (n == 2) cout << min(a1[0], a2[0]) << '\n';
    if (n < 3) return 0;
    dp1[0] = a1[0];
    dp2[0] = a2[0];
    dp1[1] = a1[1];
    dp2[1] = a2[1];
    for (int i = 2; i < n; ++i)
    {
        dp1[i] = a1[i]+min(dp1[i-1], dp1[i-2]);
        dp2[i] = a2[i]+min(dp2[i-1], dp2[i-2]);
    }
    cout << min({dp1[n-1], dp2[n-1]}) << '\n';
}
