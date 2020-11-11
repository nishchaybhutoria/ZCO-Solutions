#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector <long long> budgets(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> budgets[i];
    }
    sort(budgets.begin(), budgets.end());
    long long m = -1e8;
    for (int i = 0; i < n; ++i)
    {
        m = max(m, (budgets[i]*(n-i)));
    }
    cout << m << '\n';
}
