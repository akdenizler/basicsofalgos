#include <iostream>
#include <vector>
using namespace std;

int main() {
    string name; 
    int nNames; 

	cin >> name >> nNames;
	vector<string> students(nNames);
    for (int i=0; i<nNames; i++){ cin >> students[i];}

    for (int meow = 0; meow<nNames; meow++) {
        if (students[meow] == name) {
            cout << "Yes";
            break; }
        }
    cout >> "No";
    }
                            
	
