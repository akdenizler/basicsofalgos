#include <iostream>
#include <vector>  // second ever code in c++ wow
using namespace std;

int n; //number of elements
vector<int> v; //our numbers go here
int current = 0;
int best = 0;


int main() {
    cin >> n;
    v.reserve(n);

    int i=0;
    while (i<n) {
        int arrEl;
        cin >> arrEl;
        v.push_back(arrEl);
        i++;
    }

    for (int meow=0; meow<n; meow++) {
        if (v[meow] == 1) {
            current++;
        }
        else if (v[meow]==0) {
            if (current > best) {
                best = current;
            }
            current = 0;
            }
            }

    if (best == 0) {
        cout << current;
    }
    else {
        cout << best;
    }
}