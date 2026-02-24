#include <iostream>
#include <vector>
using namespace std; 
int nSteps;
int nGrasshoppers;
vector<int> stairHeights;
vector<int> grassHeights; //doubles as a grasshopper holding cell
int currentHopper;

int main(){
    cin >> nSteps >> nGrasshoppers;

    vector<int> stairHeights(nSteps);
    vector<int> grassHeights(nGrasshoppers);

    for (int i = 0; i < nSteps; i++) { cin >> stairHeights[i]; }
    for (int i = 0; i < nGrasshoppers; i++) { cin >> grassHeights[i]; }
    
    std::sort(stairHeights.begin(), stairHeights.end());
    std::sort(grassHeights.begin(), grassHeights.end());

    currentHopper = 0;
    int i=0;

    sort(stairHeights.begin(), stairHeights.end());

    for (int currentHopper = 0; currentHopper < nGrasshoppers; currentHopper++) {
        int jump = grassHeights[currentHopper];

        int pos = upper_bound(stairHeights.begin(), stairHeights.end(), jump) - stairHeights.begin();

        cout << pos;
        }

    }
}
