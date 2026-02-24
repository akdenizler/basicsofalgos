#include <vector>
#include <iostream>
using namespace std; 

int N;

int main() {
    cin >> N;
    vector<int> a(N);
    int S = 0;
    for (int i = 0; i < N; i++) { cin >> a[i]; S += a[i]; }

    if ( S % 2 == 1) { cout << "NO"; return 0;}

    int target = S/2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int c : a){ 
    for (int s = target; s >= c; s--) {
        if (dp[s - c]) { dp[s] = true;}

    if (dp[target]) cout << "YES"; else cout << "NO";

}

    }









