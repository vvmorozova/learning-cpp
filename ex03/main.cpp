#include <cstdio>
unsigned gcd(unsigned a, unsigned b)
{
    if (b > a)
        return (gcd(b, a));
    if (a % b == 0)
        return (b);
    return (gcd(b, a % b));
    
}

int main()
{
    printf(" %d\n", gcd(1000, 550));
}