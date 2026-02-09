#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nPlaces;
int nStudents;

vector<long long> coordinates;

int main() { 
    cin >> nPlaces >> nStudents;
    coordinates.resize(nPlaces);

    for (int i=0; i<nPlaces; i++) {
        cin >> coordinates[i];
    }

    sort(coordinates.begin(), coordinates.end());
    vector<long long> chosenCoords(nStudents);

    int minDistance = coordinates[nStudents - nStudents +1];
    for (int i=0;i<nStudents; i++) { 
        chosenCoords[i] = coordinates[nPlaces - i];
    }





}