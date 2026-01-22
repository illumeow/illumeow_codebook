vector<int> linearSieve(int n) {
    // div: smallest prime divisor
    vector<int> primes, divs(n+1);
    for (int i = 2; i <= n; i++) {
        if (divs[i] == 0) {
            primes.emplace_back(i);
            divs[i] = i;
        }
        for (auto p: primes) {
            if (i * p > n) break;
            divs[i * p] = p;
            if (i % p == 0) break;
        }
    }
    return divs;
}