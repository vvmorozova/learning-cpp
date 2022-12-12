#include <iostream>
// учесть случаи shift == 0 и shift >= size
using namespace std;

void rotate(int a[], unsigned size, int shift);
void test1()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 5, 1, 2, 3};
    int shift = 3;
    unsigned size = 5;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test2()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 5, 1, 2, 3};
    int shift = 8;
    unsigned size = 5;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test3()
{
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};
    int shift = 3;
    unsigned size = 3;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test4()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int shift = 40;
    unsigned size = 9;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test5()
{
    int a[] = {1, 2};
    int b[] = {2, 1};
    int shift = 23;
    unsigned size = 2;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test6()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {5, 6, 1, 2, 3, 4};
    int shift = 10;
    unsigned size = 6;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test7()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {3, 4, 5, 6, 7, 8, 1, 2};
    int shift = 2;
    unsigned size = 8;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test8()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {7, 8, 1, 2, 3, 4, 5, 6};
    int shift = 6;
    unsigned size = 8;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test9()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {3, 4, 5, 6, 7, 8, 1, 2};
    int shift = -6;
    unsigned size = 8;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

void test10()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int shift = 0;
    unsigned size = 8;

    rotate(a, size, shift);

    for (unsigned i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;

    for (unsigned i = 0; i < size; i++)
    {
        cout << b[i];
    }
    cout << '\n' << endl;
}

// shift > size / 2

void rotater(int a[], unsigned size, int shift)
{
    int t, wait = 0, i, j, store, store_i = -1;

    for (i = 0; i < shift; i++) {
        for (j = i; j <= size - 1; j += shift) {
            if (j == store_i) {
                wait = store;
                continue;
            }
            if (j != i) {
                t = a[j];
                a[j] = wait;
                wait = t;
            }
            else
                wait = a[j];
        }
        store = a[j - size];
        store_i = j -  size;
        a[store_i] = wait;
    }
}

void rotatel(int a[], unsigned size, int shift)
{
    int t, wait = 0, i, j, store, store_i;;

    for (i = size - 1; i > size - 1 - shift; i--) {
        for (j = i; j >= 0; j -= shift) {
            if (j == store_i) {
                wait = store;
                continue;
            }
            if (j != i) {
                t = a[j];
                a[j] = wait;
                wait = t;
            }
            else
                wait = a[j];
        }
        store = a[size + j];
        store_i = size + j;
        a[store_i] = wait;
    }
}

void rotate(int a[], unsigned size, int shift)
{
    if (shift > size)
        shift = shift % size;
    if (shift < size / 2)
        rotatel(a, size, shift);
    else
        rotater(a, size, size - shift);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, size = 8, shift = 3;

    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    cout << endl;
    rotate(a, size, shift);
    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    cout << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
	return 0;
}