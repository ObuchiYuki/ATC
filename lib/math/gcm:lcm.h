//
//  gcm:lcm.h
//  ATC
//
//  Created by yuki on 2022/04/16.
//

template<class T>
T gcd(vector<T> v) {
    T res = -1;
    for (auto e: v) res = res == -1 ? e : gcd(res, e);
    return res;
}
template<class T>
T lcm(vector<T> v) {
    T res = -1;
    for (auto e: v) res = res == -1 ? e : lcm(res, e);
    return res;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll d = exgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
