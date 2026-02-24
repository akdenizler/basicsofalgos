#include <vector>
#include <iostream>
#include <numeric>
using namespace std; 



int main(){ //meown (get it? main? meown?)
    int nitems;
    cin >> nitems;
    vector<int> gearturns(nitems);
    for (int hi = 0; hi < nitems; hi++) {
        cin >> gearturns[hi];
}
    int l = gearturns[0];


    for (int i = 1; i < nitems; i++) {
        if (l == 1) {
            break;
        }
        else {
            l = l / std::gcd(l, gearturns[i]) * gearturns[i]; }

    cout << l / gearturns[0];


}
