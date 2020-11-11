#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double
#define F first
#define S second

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

bool cmp(pair <ll, ll>& a, pair <ll, ll>& b)
{
    if (a.F != b.F) return a.F < b.F;
    return a.S < b.S;
}

int32_t main()
{
    usaco();
    ll t;
    cin >> t;
    while (t--)
    {
        ll c, n, k;
        cin >> c >> n >> k;
        vector <pair <ll, ll>> v(n);
        for (ll i = 0; i < n; ++i) cin >> v[i].F >> v[i].S;
        sort(begin(v), end(v), cmp);
        if (!k)
        {
            ll ok = 1;
            for (ll i = 0; i+1 < n; ++i)
                ok &= (v[i].S < v[i+1].F);
            cout << (ok ? "Good\n" : "Bad\n");
        } else {
            ll p1 = -1, p2 = -1;
            for (ll i = 0; i+1 < n; ++i)
            {
                if (v[i].S >= v[i+1].F)
                {
                    p1 = i;
                    p2 = i+1;
                    break;
                }
            }
            if (p1 == -1 && p2 == -1) cout << "Good\n";
            else {
                vector <pair <ll, ll>> temp = v;
                temp.erase(begin(temp)+p1);
                ll dist = v[p1].S-v[p1].F+1, ok = 0, flag = 0, check = 1;
                flag |= (temp[0].F-1 >= dist || c-temp.back().S >= dist);
                for (ll i = 0; i+1 < n-1; ++i)
                {
                    flag |= (temp[i+1].F-temp[i].S-1 >= dist);
                    check &= (temp[i+1].F > temp[i].S);
                }
                ok |= flag;
                ok &= check;
                if (ok)
                {
                    cout << "Good\n";
                    continue;
                }
                temp = v;
                temp.erase(begin(temp)+p2);
                dist = v[p2].S-v[p2].F+1;
                ok = flag = 0;
                check = 1;
                flag |= (temp[0].F-1 >= dist || c-temp.back().S >= dist);
                for (ll i = 0; i+1 < n-1; ++i)
                {
                    flag |= (temp[i+1].F-temp[i].S-1 >= dist);
                    check &= (temp[i+1].F > temp[i].S);
                }
                ok |= flag;
                ok &= check;
                cout << (ok ? "Good\n" : "Bad\n");
            }
        }
    }
}
