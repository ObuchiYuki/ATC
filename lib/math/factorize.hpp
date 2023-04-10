//
//  factorize.hpp
//  ATC
//
//  Created by yuki on 2022/04/15.
//

// 1260 -> { 2, 2, 3, 3, 5, 7 }
auto pfactorize(int N) -> multiset<int> {
    multiset<int> res;
    for (int i=2; i*i <= N; i++) while (N%i == 0) {
        res.insert(i); N /= i;
    }
    if (N != 1) res.insert(N);
    return res;
}

auto pfactorize(int N) -> vector<int> {
    vector<int> res;
    for (int i=2; i*i <= N; i++) while (N%i == 0) {
        res.push_back(i); N /= i;
    }
    if (N != 1) res.push_back(N);
    return res;
}

// 1260 -> { 2, 3, 5, 6, 7 }
auto factorize(int N) -> multiset<int> {
    multiset<int> res;
    for (int i=2; i*i <= N; i++) if (N%i == 0) {
        res.insert(i); N /= i;
    }
    if (N != 1) res.insert(N);
    return res;
}
