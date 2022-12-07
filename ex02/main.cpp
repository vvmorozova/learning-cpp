#include <iostream>
using namespace std;

int main()
{
    int    t;
    int    pow;
    int    max;
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        pow = 0;
        cin >> max;
        while (max > 1) {
            max /= 2;
            pow++;
        }
        cout << pow << endl;
    }
	return 0;
}
