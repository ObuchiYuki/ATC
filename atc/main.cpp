#include <bits/stdc++.h>

#define in(x, from, to) (from <= x && x < to)
#define inr(x, from, to) (from <= x && x <= to)
#define in2(p, W, H) (0 <= p.first && p.first < W && 0 <= p.second && p.second < H)

#define sub(field, p) field[(p).second][(p).first]

#define rep(i, upto) for (int i=0; i<upto; i++)
#define repr(i, from, upto) for (int i=from; i<upto; i++)
#define repv(i, upto) for (int i=upto-1; i>=0; i--)
#define repvr(i, from, upto) for (int i=upto-1; i>=from; i--)

using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T>
using heap = priority_queue<T, vector<T>, greater<T>>;

P operator + (P p0, P p1) { return { p0.first + p1.first, p0.second + p1.second }; }

vector<P> move4 = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
vector<P> move8 = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } };

#ifdef DEBUG
#include "debug.hpp"
#else
template<class T> void print(const T& v) { cout << v << endl; }
void _main(); int main() { _main(); }
#endif

// ================================================================================ //
// main

void _main() {
    string S; cin >> S;
    print("Hello " + S + "!");
}
