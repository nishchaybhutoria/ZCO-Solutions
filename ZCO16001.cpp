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

int solve(vector <int> a, vector <int> b, int n, int k)
{
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int i = 0;
    int j = n-1;
    while (k--)
    {
        if (i >= n || j < 0) break;
        else if (a[i] >= b[j]) break;
        else {
            swap(a[i], b[j]);
            ++i;
            --j;
        }
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    return (a[n-1]+b[n-1]);
}

signed main()
{
    usaco();
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    cout << min(solve(a, b, n, k), solve(b, a, n, k)) << '\n';
}
