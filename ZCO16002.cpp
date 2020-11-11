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
        freopen((name+".txt").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    usaco();
    int n, ans = 1;
    cin >> n;
    vector <int> a(n);
    gp_hash_table <int, int> m;
    for (int i = 0; i < n; ++i) cin >> a[i], ++m[a[i]];
    sort(begin(a), end(a));
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            int d = a[j]-a[i];
            int cur = a[j]+d;
            int t = 2;
            while (m[cur])
            {
                ++t;
                cur += d;
            }
            ans = max(ans, t);
        }
    }
    cout << ans << '\n';
}
