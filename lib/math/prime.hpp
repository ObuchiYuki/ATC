//
//  prime.hpp
//  ATC
//
//  Created by yuki on 2022/04/17.
//

bool is_prime(int N) {
    for (int i=2; i*i <= N; i++) if (N%i == 0) return false;
    return true;
}

auto eratosthenes(int N) -> vector<bool> {
    auto prime = vector<bool>(N+1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p <= N; ++p) if (prime[p]) {
        for (int q = p * 2; q <= N; q += p) prime[q] = false;
    }
    return prime;
}

auto eratosthenes(ll A, ll B) -> vector<bool> {
    auto isprime_sqrtB = vector<bool>((int)sqrt(B)+1, true);
    auto isprime_AB = vector<bool>(B-A+1, true);
    
    for (ll p = 2; p*p <= B; p++) if (isprime_sqrtB[p]) {
        for (ll q = p*2; q*q <= B; q += p) isprime_sqrtB[q] = false;
    
        ll start = (A+p-1)/p * p;
        if (start == p) start = p*2;
        
        for (ll q = start; q <= B; q += p) isprime_AB[q-A] = false;
    }
    
    return isprime_AB;
}
