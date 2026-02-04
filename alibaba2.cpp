// C++ Program to demonstrate how to implement the quick
// sort algorithm
#include <bits/stdc++.h>
using namespace std;

int carrCap;
int numBags;

struct sandBags {
    int cost;
    int weight;
    double r;
}


int partition(vector<sandBags> &vec, int low, int high) {

    // Selecting last element as the pivot
    sandBags pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element's cw ratio is smaller than or
        // equal to pivot
        if (vec[j].r <= pivot.r) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    vector<SandBag> vec;
    vec.reserve(nBun);  

    for (int i = 0; i < nBun; i++) {
        cin >> cost >> weight;
        r = (double)cost / weight;
        vec.push_back({cost, weight, r}); }
	
  	// Calling quicksort for the vector vec
    quickSort(vec, 0, n - 1);
    
    int bagRN = 0; //where we keep track of whats in da bag (weightwise)
    int capRem; //remaining bag capacity 
    int totalCost = 0
    int lastEl = numBags -1
    int i=0;

    while (bagRN < carrCap) {
        if (vec[lastEl+i].weight > capRem) {
             c = c_i * w / w_i;
             c += totalCost;
             capRem = carrCap - bagRN;
        }
        else {
            bagRN += vec[lastEl].weight;
            totalCost += vec[lastEl].cost;
            capRem = carrCap - bagRN;
            i++;
        }
      
    }

    
    for (auto i : vec) {
        cout << i << " ";
    }
    return 0;