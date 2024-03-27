#include "ex05.h"

#define DOWN 0
#define UP 1
#define CTRL_X 2
#define CTRL_V 3
#define SHIFT 4

void TextEditor(void)
{
	list<string> content = {};
	string s, buffer = "";
	map<string, int> mapping;

	mapping["Down"] = DOWN;
	mapping["Up"] = UP;
	mapping["Ctrl+X"] = CTRL_X;
	mapping["Ctrl+V"] = CTRL_V;
	mapping["Shift"] = SHIFT;

	while (getline(cin, s) && s != "")
	{
		content.push_back(s);
	}
	s = "";
	content.push_back(s);

	auto iter = content.begin();
	while (getline(cin, s))
	{
		switch (mapping[s])
		{
		case DOWN:
			if (*iter != "")
				iter++;
			break;
		case UP:
			if (iter != content.begin())
				iter--;
			break;
		case CTRL_X:
			if (iter != content.end() && *iter != "")
			{
				buffer = move(*iter);
				iter = content.erase(iter);
			}
			break;
		case CTRL_V:
			content.insert(iter, buffer);
			break;
		case SHIFT:
			content.insert(iter, buffer);
			break;
		default:
			break;
		}
	}
	for (auto it = content.begin(); it != content.end(); ++it)
	{
		cout << *it << endl;
	}
}

void TextEditor_test(string filename)
{
	ifstream test_file;
	deque<string> content = {};
	string s, buffer = "";
	map<string, int> mapping;
	bool shiftIsPressed = false;
	int firstSelected = -1;
	int shift, currentIndex;

	mapping["Down"] = DOWN;
	mapping["Up"] = UP;
	mapping["Ctrl+X"] = CTRL_X;
	mapping["Ctrl+V"] = CTRL_V;
	mapping["Shift"] = SHIFT;

	test_file.open(filename);

	while (getline(test_file, s) && s != "")
	{
		content.push_back(s);
	}
	s = "";
	content.push_back(s);

	for (auto it = content.begin(); it != content.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;

	auto iter = content.begin();
	while (getline(test_file, s))
	{
		switch (mapping[s])
		{
		case DOWN:
			cout << "DOWN" << endl;
			if (*iter != "")
				iter++;
			break;
		case UP:
			cout << "UP" << endl;
			if (iter != content.begin())
				iter--;
			break;
		case CTRL_X:
			cout << "CTRL_X" << endl;
			if (iter != content.end() && *iter != "")
			{
				cout << "*ITER"
					 << " " << *iter << endl;
				if (shiftIsPressed)
				{

					currentIndex = distance(content.begin(), iter);
					if (firstSelected > currentIndex)
						shift = firstSelected - currentIndex;
					else
						shift = currentIndex - firstSelected;
					iter = content.erase(iter, iter + shift);
				}
				else
				{
					buffer = std::move(*iter);
					iter = content.erase(iter);
				}
			}
			break;
		case CTRL_V:
			cout << "CTRL_V" << endl;
			if (buffer != "")
				content.insert(iter, buffer);
			break;
		case SHIFT:
			shiftIsPressed = true;
			firstSelected = distance(content.begin(), iter);
			break;
		default:
			break;
		}
		cout << "BUFFER"
			 << " " << buffer << endl;
	}
	cout << "-----------------" << endl;
	for (auto it = content.begin(); it != content.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "-----------------" << endl;
}

int main()
{
	cout << "TEST 1" << endl;
	TextEditor_test("test_files/test1.txt");

	cout << "TEST 2" << endl;
	TextEditor_test("test_files/test2.txt");

	cout << "TEST 3" << endl;
	TextEditor_test("test_files/test3.txt");

	cout << "TEST 4" << endl;
	TextEditor_test("test_files/test4.txt");

	cout << "TEST 5" << endl;
	TextEditor_test("test_files/test5.txt");

	cout << "TEST 6" << endl;
	TextEditor_test("test_files/test6.txt");
}