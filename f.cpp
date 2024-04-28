#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int N, A[400000];
vector<int> v;
ll ans = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i)
        v.push_back(A[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    fenwick_tree<ll> cnt(N), sum(N);
    for (int i = 0; i < N; ++i)
    {
        int idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        ans += cnt.sum(0, idx) * A[i] - sum.sum(0, idx);
        cnt.add(idx, 1);
        sum.add(idx, A[i]);
    }
    cout << ans << '\n';
}
