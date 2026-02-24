/* Ali Baba returned back to cave, and took his knapsack with carrying capacity 
1⩽W⩽5000 to take treasures out of the cave

When he came into cave he found a room with 0 ⩽ N ⩽ 1000 gold bars in it. 

For each bar he knows weight 1⩽wi⩽100000 and cost 1⩽wi⩽100000

As usual, he wants to maximize total cost of treasures taken out.
The bars are undividable.

goal : calculate maximum obtainable profit and gives indices of items (items are enumerated from 1)
he should place into knapsack to maximize total cost.

input: carrying capacity 1⩽W⩽5000 and number of items 0 ⩽ N ⩽ 1000

second line N positive integers divided by space chatacters w1, w2, w3
third line N positive integers divided by space character c1, c2, c3

output: first line - max total cost ali  baba can have :)
second line - number of items K which allow to maximize total cost 
third line: K positive integers separated by a space character. 

items are enumerated from 1 */

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
            if (d[meow][wow] == d[meow-1][wow] {
                meow--;
            }
            else {
                chosen.pushback(meow)
                wow -= wt[meow-1]
                meow--
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


    }