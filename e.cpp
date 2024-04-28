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

int N, X, Y;
vector<int> odd_x, odd_y, even_x, even_y;

ll ans = 0;

void calc(vector<int> &v)
{
    sort(v.begin(), v.end());
    const int N = v.size();
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        ans += (ll)v[i] * i - sum;
        sum += v[i];
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> X >> Y;
        bool isOdd = (X + Y) & 1;
        Y += isOdd;
        (isOdd ? odd_x : even_x).push_back((X + Y) / 2);
        (isOdd ? odd_y : even_y).push_back((X - Y) / 2);
    }

    calc(odd_x);
    calc(odd_y);
    calc(even_x);
    calc(even_y);
    cout << ans << '\n';
}
