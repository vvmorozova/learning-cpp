#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string  s1;
    char c = '\0';
    int was_space = 0;
    

    while (cin.get(c)) {
        if ((was_space == 0 && c == ' ') || c != ' ')
            s1.append(1, c);
        if (c == ' ')
            was_space = 1;
        else
            was_space = 0;
    }
    cout << s1 << endl;
	return 0;
}