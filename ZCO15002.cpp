#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    vector <long long> v(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long i = 0, j = 0, count = 0;
    while (i < n)
    {
        if (i > j)
            j = i;
        else if (j >= n)
            break;
        if (v[j] - v[i] >= k)
        {
            ++i;
            count += (n-j);
        } else
            ++j;
    }
    cout << count << '\n';
}
