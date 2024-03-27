#include <iostream>

using namespace std;

void    print_num(void)
{
    int    a;

    cin >> a;
    if (a == 0)
        return ;
    print_num();
    cout << a << endl;
}
int main()
{
    print_num();
        
	return 0;
}