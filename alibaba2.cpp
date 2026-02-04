#include <bits/stdc++.h>
using namespace std;

int carrCap;
int numBags;

struct sandBags {
    long long cost;
    long long weight;
    double r;
};

void quickSort3(vector<sandBags> &vec, int low, int high) {
    if (low >= high) return;

    int pivotIndex = low + rand() % (high - low + 1);
    double pivot = vec[pivotIndex].r;

    int lt = low;   //< pivot
    int i  = low;      //current
    int gt = high;    //> pivot

    while (i <= gt) { //compare cost/weight ratios of sandbags
        if (vec[i].r < pivot) {
            swap(vec[lt++], vec[i++]);
        } else if (vec[i].r > pivot) {
            swap(vec[i], vec[gt--]);
        } else {
            i++;
        }
    }

    quickSort3(vec, low, lt - 1);
    quickSort3(vec, gt + 1, high);
}

int main() {

	ios::sync_with_stdio(false); //optimisation stuff 
    cin.tie(nullptr);

    srand((unsigned)time(nullptr));

    cin >> numBags >> carrCap;

    vector<sandBags> vec;
    vec.reserve(numBags);   

    for (int i = 0; i < numBags; i++) {   //input loop
        long long cost, weight;                
        double r;                        

        cin >> cost >> weight;
        r = (double)cost / weight;

        vec.push_back(sandBags{cost, weight, r}); 
    }

    quickSort3(vec, 0, numBags - 1);

    long long bagRN = 0; //bag right now
    long long capRem; //capacity remaining
    long long totalCost = 0;       
    long long lastEl = numBags - 1;    
    int i = 0;

    while (bagRN < carrCap && i < numBags) {
        capRem = carrCap - bagRN; 

        if (vec[lastEl - i].weight > capRem) {
            long long c = vec[lastEl - i].cost * capRem / vec[lastEl - i].weight;
            totalCost += c;
            break;
        } else {
            bagRN += vec[lastEl-i].weight;
            totalCost += vec[lastEl-i].cost;
            i++; 
        }
    }

    cout << totalCost; //output :)
    return 0;
}
