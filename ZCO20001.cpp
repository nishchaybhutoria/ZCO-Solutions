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
    int t;
    cin >> t;
    while (t--)
    {
        long long p, idx, ans = 0;
        cin >> p >> idx;
        --p;
        while (idx)
        {
            ans += ((idx & 1) << p);
            idx >>= 1;
            --p;
        }
        cout << ans << '\n';
    }
}
