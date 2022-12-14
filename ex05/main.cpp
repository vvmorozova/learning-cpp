#include <iostream>
// учесть случаи shift == 0 и shift >= size
using namespace std;

void rotate(int a[], unsigned size, int shift)
{
    int t, wait, last, store;

    if (shift > size)
        shift = shift % size;
    store = a[shift - 1];
    for (int j = 0; j < shift; j++) {
        for (int i = j; i < size; i+= shift) {
            if (i - shift >= 0) {
                t = a[i];
                a[i] = wait;
                wait = t;
            }
            else
                wait = a[i];
            if (i == shift - 1)
                wait = store;
            last = i;
        }
        a[shift - (size - last)] = wait;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5}, size = 5, shift = 4;

    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    cout << endl;
    rotate(a, size, shift);
    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    cout << endl;
	return 0;
}