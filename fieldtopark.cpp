#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, x, y;

bool reachableDP(const vector<vector<int>>& blocked) {
    int N = blocked.size();
    int M = blocked[0].size();

    vector<vector<bool>> reach(N, vector<bool>(M, false));

    if (blocked[0][0]) return false;
    reach[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (i == 0 && j == 0) continue;

            if (blocked[i][j]) {
                reach[i][j] = false;
            } else {
                bool fromUp = false;
                bool fromLeft = false;

                if (i > 0 && reach[i-1][j] == true) fromUp = true;
                if (j > 0 && reach[i][j-1] == true) fromLeft = true;

                if (fromUp || fromLeft) reach[i][j] = true;
                else reach[i][j] = false; 
              }
       }
    }

    if (reach[N-1][M-1] == true) return true;
    else return false;
}

bool check(int t, int N, int M, const vector<pair<int,int>>& trees) {
    vector<vector<int>> blocked(N, vector<int>(M, 0));

    for (int k = 0; k <= t; k++) {
        int r = trees[k].first;
        int c = trees[k].second;
        blocked[r][c] = 1;
    }

    if (blocked[0][0] || blocked[N-1][M-1]) return false;
    else return reachableDP(blocked);
}

int main() {
    cin >> N >> M >> K;
    vector<pair<int,int>> trees(K);

    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        trees[i] = {x, y};
    }

    if (check(K-1, N, M, trees)) {
        cout << -1;
        return 0;

    int left = 0;
    int right = K - 1;

    while (left < right) {
    int mid = (left + right) / 2;

    if (check(mid, N, M, trees)) {
        left = mid + 1;
    } else {
        right = mid;
    }

    cout << left; 
}



}

    return 0;
}
