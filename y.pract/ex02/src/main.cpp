#include "ex02.h"

void students(void)
{
    deque<string> pile = {};
    list<int> order = {};
    int n, m, x;
    string surname, pos, str;

    cin >> n;

    while (n)
    {
        cin >> surname >> pos;
        if (pos == "top")
            pile.push_front(surname);
        else
            pile.push_back(surname);
        n--;
    }
    cin >> m;

   for (int i = 0; i < m; i++)
    {
        cin >> x;
        order.push_back(x);
    }

    auto iter = order.begin();
    while (iter != order.end())
    {
        cout << pile[*iter - 1] << endl;
        iter++;
    }
}

void students_test(string filename, bool test = false)
{
    ifstream test_file;
    deque<string> pile = {};
    list<int> order = {};
    int n, m, x;
    string surname, pos, str;

    test_file.open(filename);
    if (test_file.is_open())
    {
        test_file >> n;
    }

    while (n)
    {
        test_file >> surname >> pos;
        if (pos == "top")
            pile.push_front(surname);
        else
            pile.push_back(surname);
        n--;
    }
    cout << "PILE" << endl;
    for (string s : pile) {
        cout << s << endl;
    }
    test_file >> m;

    for (int i = 0; i < m; i++)
    {
        test_file >> x;
        order.push_back(x);
    }

    auto iter = order.begin();
    while (iter != order.end())
    {
        cout << pile[*iter - 1] << endl;
        iter++;
    }
}

int main()
{
    cout << "TEST 1" << endl;
    students_test("test_files/test1.txt", true);

    cout << "TEST 2" << endl;
    students_test("test_files/test2.txt", true);
}