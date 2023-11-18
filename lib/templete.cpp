//
//  templete.cpp
//  ATC
//
//  Created by yuki on 2022/04/08.
//

template<class H, class... T> void print(H h, T... t) { cout << h << ' '; print(t...); }

#define in(x, from, to) (from <= x && x < to)
#define inr(x, from, to) (from <= x && x <= to)
#define in2(p, W, H) (0 <= p.first && p.first < W && 0 <= p.second && p.second < H)

#define rep(i, to) for (int i=0; i<to; i++)
#define repr(i, from, to) for (int i=from; i<to; i++)
#define repv(i, to) for (int i=to-1; i>=0; i--)
#define repvr(i, from, to) for (int i=to-1; i>=from; i--)

#define all(v, func) [&](){ for (auto _: v) if (!(func)) return false; return true; }()
#define any(v, func) [&](){ for (auto _: v) if (func) return true; return false; }()
#define sub(map, p) map[(p).second][(p).first]

template<class It, class F> It max_where(It b, It e, F f) {
    if (b != e) { auto i = b; while (++i != e) if (f(*b) < f(*i)) b = i; } return b;
}

template<class T> T in() { T a; cin >> a; return a; }

template<class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

template<class T> auto sum(vector<T> v, T initial = T(0)) -> T {
    T res = initial; for(auto e: v) res += e; return res;
}
template<class T> auto sum(set<T> v, T initial = T(0)) -> T {
    T res = initial; for(auto e: v) res += e; return res;
}
template<class T> auto range(T to) -> vector<T> {
    vector<T> v(to); iota(v.begin(), v.end(), T()); return move(v);
}
template<class T> auto range(T from, T to) -> vector<T> {
    vector<T> v(to-from+1); iota(v.begin(), v.end(), from); return move(v);
}

P operator + (P p0, P p1) { return { p0.first + p1.first, p0.second + p1.second }; }
P operator - (P p0, P p1) { return { p0.first - p1.first, p0.second - p1.second }; }
P operator * (P p0, P p1) { return { p0.first * p1.first, p0.second * p1.second }; }
P operator / (P p0, P p1) { return { p0.first / p1.first, p0.second / p1.second }; }
P operator * (P p, T v) { return { p.first * v, p.second * v }; }
P operator / (P p, T v) { return { p.first / v, p.second / v }; }

double abs(P p) { return sqrt(p.first*p.first + p.second*p.second); }
int abs2(P p) { return p.first*p.first + p.second*p.second; }

vector<P> move4 = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
vector<P> move8 = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } };

P max(P p0, P p1) {
    return { max(p0.first, p1.first), max(p0.second, p1.second) };
}
P min(P p0, P p1) {
    return { min(p0.first, p1.first), min(p0.second, p1.second) };
}

template<class T>
using heap = priority_queue<T, vector<T>, greater<T>>;
