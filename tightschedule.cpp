#include <vector>
#include <iostream>
using namespace std; 
int questions;
int minLeft; 
int questionBank =0;

int main() {
    cin >> questions >> minLeft;
    vector<int> minReq_for_Qi(questions);
    for (int i=1; i<=questions; i++){cin >> minReq_for_Qi[i];}

    int j=0;
    while (questionBank < minLeft) { 
        questionBank += minReq_for_Qi[j];
        j++;
    }
    cout << ;
}