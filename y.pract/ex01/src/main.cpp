#include "ex01.h"

int main(int argc, char* argv[]) {
    int d = atoi(argv[1]), m = atoi(argv[2]), y = atoi(argv[3]);
    Date h(d, m, y);
    cout << "hehe " << h.GetDay() << " " << h.GetMonth() << " " << h.GetYear() << endl;
}