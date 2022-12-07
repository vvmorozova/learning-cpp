#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    int    d;
    double    sqrt_d, x1, x2;
   
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d < 0) {
        cout << "No real roots" << endl;
        return (0);
    }
    sqrt_d = sqrt(d);
    cout << "d = " << d << "sqrt " << sqrt_d << endl;
    x1 = ((- (double)b + sqrt_d) / (2 * (double)a ));
    x2 = ((- (double)b - sqrt_d) / (2 * (double)a ));
    cout << x1 << " " << x2 << endl;
    return 0;
}