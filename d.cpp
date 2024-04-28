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

int H, W;
string S[1000];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool inner(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W && S[x][y] != '#'; }
bool inner(pr &r) { return inner(r.first, r.second); }
pr next(int x, int y, int k) { return make_pair(x + dx[k], y + dy[k]); }
pr next(pr &r, int k) { return next(r.first, r.second, k); }

int cnt, ans = 1;
bool seen[1000][1000], fix[1000][1000];
set<pr> s;

void dfs(int x, int y)
{
    if (seen[x][y])
        return;
    seen[x][y] = 1;
    ++cnt;
    for (int k = 0; k < 4; ++k)
    {
        pr r = next(x, y, k);
        auto [nx, ny] = r;
        if (!inner(nx, ny) || s.find(r) != s.end())
            continue;

        if (fix[nx][ny])
        {
            s.insert(r);
            ++cnt;
        }
        else
            dfs(nx, ny);
    }
}

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        cin >> S[i];

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            if (S[i][j] == '#')
                for (int k = 0; k < 4; ++k)
                {
                    auto [x, y] = next(i, j, k);
                    if (inner(x, y))
                        fix[x][y] = 1;
                }
        }

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            if (!inner(i, j) || fix[i][j] || seen[i][j])
                continue;
            cnt = 0;
            s.clear();
            dfs(i, j);
            chmax(ans, cnt);
        }
    cout << ans << '\n';
}
