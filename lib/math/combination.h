//
//  nCr.h
//  ATC
//
//  Created by yuki on 2022/04/16.
//

ll nCr(int n, int r) {
    static map<P, ll> memo;
    if (r == 0 || r == n) return 1;
    if (r == 1) return n;
    P key = { n, r };
    if (memo.count(key)) return memo[key];
    return memo[key] = nCr(n-1, r) + nCr(n-1, r-1);
}

ll nHr(int n, int r) {
    return nCr(n+r-1, r);
}

// MODが素数の場合のみO(N)のnCr

//const auto MOD = 1000000007;
//
//ll nCr(int n, int k) {
//    assert(!(n < k));
//    assert(!(n < 0 || k < 0));
//    static vector<ll> fact, fact_inv;
//    {
//        static vector<ll> inv;
//        static bool initilized = false;
//        static int last_n = 2;
//        fact.resize(n+5);
//        fact_inv.resize(n+5);
//        inv.resize(n+5);
//        if (!initilized) {
//            fact[0] = fact[1] = 1;
//            fact_inv[0] = fact_inv[1] = 1;
//            inv[1] = 1;
//        }
//        for (int i=last_n; i < n+5; i++) {
//            fact[i] = fact[i - 1] * i % MOD;
//            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
//            fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
//        }
//        last_n = n;
//    }
//    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
//}

template<class F>
void combUtil(int n, int r, int index, vector<int>& data, int i, F func) {
    if (index == r) {
        func(data);
        return;
    }

    if (i >= n) return;

    data[index] = i;
    combUtil(n, r, index + 1, data, i + 1, func);
    combUtil(n, r, index, data, i + 1, func);
}

template<class F>
void comb(int n, int r, F func) {
    vector<int> data(r);
    combUtil(n, r, 0, data, 0, func);
}
