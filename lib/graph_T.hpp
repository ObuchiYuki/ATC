#define in(x, from, to) (from <= x && x < to)
#define inr(x, from, to) (from <= x && x <= to)
#define in2(p, W, H) (0 <= p.first && p.first < W && 0 <= p.second && p.second < H)

#define sub(map, p) map[(p).second][(p).first]

P operator + (P p0, P p1) { return { p0.first + p1.first, p0.second + p1.second }; }
P operator - (P p0, P p1) { return { p0.first - p1.first, p0.second - p1.second }; }

vector<P> move4 = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
