//
//  pow(fast).h
//  ATC
//
//  Created by yuki on 2022/04/16.
//


// O(log(N))時間で終わるint特化のpow

ll ipow(ll x, ll n) {
    if (n == 0) return 1;
    auto res = ipow(x, n / 2);
    res *= res;
    if (n%2 == 1) res *= x;
    return res;
}

ll ipow(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    auto res = ipow(x, n/2, mod);
    res *= res;
    if (n%2 == 1) res *= x;
    return res % mod;
}
