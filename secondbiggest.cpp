#include <iostream>
#include <vector>  // first code ever in c++ wow
#include <limits>

using namespace std;

int main() {
    int i = 0;
    int numEl;
    int secondBiggest = numeric_limits<int>::min();
    int biggestNum = numeric_limits<int>::min();
    bool foundSecond = false;

    cin >> numEl;

    vector<int> v;
    v.reserve(numEl);

    //phase 1: read elements into vector
    while (i < numEl) {
        int arrEl;
        cin >> arrEl;
        v.push_back(arrEl);
        i++;
    }

    //phase 2: early exit check
    if (v.size() <= 1) {
    	cout << -1; 
        return 0;
    }

    //phase 3: find biggest and second biggest
    else {
        i = 0;
        while (i < numEl) { 
            if (v[i] > biggestNum) 
            {
            if (biggestNum != numeric_limits<int>::min()) 
            {
        		foundSecond = true;
    			}
                secondBiggest = biggestNum;
                biggestNum = v[i];
                i++;
            }
            else if (v[i] < biggestNum && v[i] > secondBiggest)
            {
                secondBiggest = v[i];
                foundSecond = true;
                i++;
            }   
            else if (v[i] == biggestNum or v[i]==secondBiggest){
                i++;
                continue;
            }
            else if (v[i] < secondBiggest) {
                i++;
                continue;
            }
            }

        }
//if we have no unique numbers return -1
        if (foundSecond == false) {
        	cout << -1;
            return 0;
        }
        else if (foundSecond == true) //if we do then print secondbiggest and return 0 
        {
            cout << secondBiggest;
            return 0;
        }
    }


