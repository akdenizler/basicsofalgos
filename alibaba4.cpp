#include <vector>
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int carrCap, nItems;
    cin >> carrCap >> nItems;

    vector<int> wt(nItems), cost(nItems);
    for (int i = 0; i < nItems; i++) cin >> wt[i];
    for (int i = 0; i < nItems; i++) cin >> cost[i];

    // d[i][w] = best value using first i items with capacity w
    vector<vector<int>> d(nItems + 1, vector<int>(carrCap + 1, 0));

    sum
    if (S % 2 != 0)

    for (int i = 1; i <= nItems; i++) {
        for (int w = 1; w <= carrCap; w++) {
            d[i][w] = d[i - 1][w]; // skip item i
            if (wt[i - 1] <= w) {
                d[i][w] = max(d[i][w], d[i - 1][w - wt[i - 1]] + cost[i - 1]);
            }
        } }
        int best = d[nItems][carrCap];

        //reconstruction
        vector<int> chosen;
        int meow = nItems, wow=carrCap;

        while (meow >0 and wow>0) {
            if (d[meow][wow] == d[meow-1][wow]) {
                meow--;
            }
            else {
                chosen.push_back(meow);
                wow -= wt[meow-1];
                meow--;
            }

        }
        cout << best << "\n";
        cout << chosen.size() << "\n";
        for (int idx = 0; idx < (int)chosen.size(); idx++) {
            if (idx) cout << " ";
                cout << chosen[idx];
    }
        cout << "\n";

        return 0;
}

