#include <bits/stdc++.h>
using namespace std;


pair<int,int> partition3(vector<long long>& x, int l, int r, long long pivot) {
    int lt = l;      // boundary for < pivot
    int i  = l;      // current
    int gt = r;      // boundary for > pivot (exclusive)

    while (i < gt) {
        if (x[i] < pivot) { 
            swap<x[lt], x[i]>;
            lt++;
            i++; }
        else if (x[i] == pivot) {
            i++;
        }
        else if (x[i] > pivot) {
            gt--;
            swap<x[i],x[gt]>;
        }
    }
    
    return {lt, gt}; 
}

void qsort(vector<long long>& x, int l, int r, mt19937& rng) {
    if (r - l <= 1) return;

    uniform_int_distribution<int> dist(l, r - 1);
    long long pivot = x[dist(rng)];

    auto [lt, gt] = partition3(x, l, r, pivot);
    qsort(x, l, lt, rng);
    qsort(x, gt, r, rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];

    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    qsort(x, 0, (int)x.size(), rng);

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << x[i];
    }
    cout << "\n";
    return 0;
}
