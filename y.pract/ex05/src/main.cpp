#include "ex05.h"

#define DOWN 0
#define UP 1
#define CTRL_X 2
#define CTRL_V 3
#define SHIFT 4

void controlX(list<string> &content, list<string> &buffer, bool &shiftIsPressed,
			  list<string>::iterator &iter, list<string>::iterator &shiftStr,
			  int &shiftOffset)
{
	cout << "Shift offset hehe " << shiftOffset << endl;
	if (*iter != "")
	{

		buffer.erase(buffer.begin(), buffer.end());
		if (shiftIsPressed && shiftOffset != 0)
		{
			cout << " offset !!! 0" << endl;
			if (shiftOffset > 0)
			{
				buffer.splice(buffer.begin(), content, shiftStr, iter);
			}
			else
			{
				buffer.splice(buffer.begin(), content, iter, shiftStr);
				iter = shiftStr;
			}
		}
		else
		{
			cout << " offset == 0" << endl;
			auto toSplice = iter;
			iter = std::next(iter);
			buffer.splice(buffer.begin(), content, toSplice);
		}
	}

	shiftIsPressed = false;
	shiftOffset = 0;
}

void controlV(list<string> &content, list<string> &buffer, bool &shiftIsPressed,
			  list<string>::iterator &iter, list<string>::iterator &shiftStr,
			  int &shiftOffset)
{
	cout << "HERE-1" << endl;
	if (buffer.size())
	{
		if (shiftIsPressed && shiftOffset != 0)
		{
			cout << "HERE0" << endl;
			if (shiftOffset > 0)
			{
				iter = content.erase(shiftStr, next(shiftStr, shiftOffset));
			}
			else
			{
				iter = content.erase(prev(shiftStr, shiftOffset), shiftStr);
			}
			cout << "HERE1" << endl;
			content.splice(iter, buffer);
		}
		else
		{
			cout << "HERE2" << endl;
			content.splice(iter, buffer);
		}
	}
	shiftIsPressed = false;
	shiftOffset = 0;
}

void moveUp(list<string> &content, list<string>::iterator &iter,
			bool shiftIsPressed, list<string>::iterator &shiftStr,
			int &shiftOffset)
{
	cout << "ITER UP" << endl;
	if (iter != content.begin())
	{
		if (shiftIsPressed)
			shiftOffset--;
		iter--;
	}
}

void moveDown(list<string>::iterator &iter, list<string> &content,
			  bool shiftIsPressed, int &shiftOffset)
{
	if (*iter != "")
	{
		if (shiftIsPressed)
			shiftOffset++;
		iter++;
	}
}

void editFile(list<string> &content, ifstream &test_file,
			  map<string, int> mapping)
{
	list<string> buffer = {};
	list<string>::iterator shiftStr;
	int shiftOffset = 0; // -1 - не задано, 0 - вниз, 1 - вверх;
	bool shiftIsPressed = false;
	string s;
	auto iter = content.begin();

	while (getline(test_file, s))
	{
		switch (mapping[s])
		{
		case DOWN:
		{
			cout << "|DOWN|" << endl;
			cout << "iter " << *iter << endl;
			moveDown(iter, content, shiftIsPressed, shiftOffset);
			print_list(content, "CONTENT");
			break;
		}
		case UP:
		{
			cout << "|UP|" << endl;
			moveUp(content, iter, shiftIsPressed, shiftStr, shiftOffset);
			print_list(content, "CONTENT");
			break;
		}
		case CTRL_X:
		{
			cout << "|CTRL_X|" << endl;
			controlX(content, buffer, shiftIsPressed, iter, shiftStr, shiftOffset);
			print_list(content, "CONTENT");

			break;
		}
		case CTRL_V:
		{
			cout << "|CTRL_V|" << endl;
			controlV(content, buffer, shiftIsPressed, iter, shiftStr, shiftOffset);
			print_list(content, "CONTENT");
			break;
		}
		case SHIFT:
		{
			cout << "|SHIFT|" << endl;
			cout << "ITER " << *iter << endl;
			print_list(content, "CONTENT");
			shiftIsPressed = true;
			shiftStr = iter;
			break;
		}
		default:
			break;
		}
	}
}

bool TextEditor_test(string filename, string reference)
{
	ifstream test_file;
	list<string> content = {};
	string s;
	map<string, int> mapping;

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

	print_list(content, "CONTENT");

	editFile(content, test_file, mapping);
	return print_to_file_and_compare(content, reference);
}

int main(int argc, char *argv[])
{
	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	string inputPath = "test_files/input/", outputPath = "test_files/output/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = TextEditor_test(inputPath + "test" + to_string(i) + ".txt",
								   outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}

bool print_to_file_and_compare(list<string> toPrint, string reference)
{
	ifstream out_file;
	string s, err_s = "", err_s_file = "";
	bool was_error = false;

	out_file.open(reference);

	for (auto it = toPrint.begin(); *it != ""; ++it)
	{
		cout << *it << endl;
		getline(out_file, s);
		if ((*it != s))
		{
			was_error = true;
			err_s = *it;
			err_s_file = s;
		}
	}
	if (was_error)
	{
		for (int i = 0; i < 20; i++)
			cout << "!";
		cout << endl;
		cout << "TEST FAILED" << endl;
		cout << err_s << endl;
		for (int i = 0; i < 20; i++)
			cout << "!";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < 20; i++)
			cout << "*";
		cout << endl;
		cout << "TEST OK" << endl;
		cout << err_s << endl;
		for (int i = 0; i < 20; i++)
			cout << "*";
		cout << endl;
	}
	return !was_error;
}

void print_list(list<string> toPrint, string msg)
{
	cout << msg << endl;
	cout << "-----------------" << endl;
	for (auto it = toPrint.begin(); it != toPrint.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "-----------------" << endl;
}
