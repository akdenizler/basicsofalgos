#include <stack>
#include <iostream>
using namespace std;

string sequence;
stack<char> brackStack;

int main() {
    cin >> sequence;

    for (int i = 0; i < sequence.length(); i++) {
        char c = sequence[i];
        
        if (c == '(' || c == '[' || c == '{') { //opneing
            brackStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') { //closing
            if (brackStack.empty()) { ///check for empty stakc
                cout << "NO";
                return 0;
            }

            char top = brackStack.top();

            if (
                (c == ')' && top != '(') || //check to see if tops are mtching bottoms, if not, return NO
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')
            ) {
                cout << "NO";
                return 0;
            }

            brackStack.pop();
        }
    }

    if (!brackStack.empty()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}

}
