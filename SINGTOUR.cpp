#pragma GCC optimize("O4")

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, li, ri;
        cin >> n;
        vector <int> s(n);
        vector <pair <int, int>> l(n), r(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> li >> ri;
            l[i] = {li, i};
            r[i] = {ri, i};
        }
        sort(begin(l), end(l));
        sort(rbegin(r), rend(r));
        for (int i = 0; i < n; ++i)
        {
            s[l[i].second] += (n-i-1);
            s[r[i].second] += (n-i-1);
        }
        for (int i : s) cout << i << " ";
        cout << '\n';
    }
}
