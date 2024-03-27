#include "ex03.h"

#define PLUS_LEFT 0
#define PLUS_RIGHT 1
#define MINUS_LEFT 2
#define MINUS_RIGHT 3

void MakeTrain(void)
{
	deque<int> trains = {};
	char delimiter = ' ';
	int num;
	string s, cmd;
	map<string, int> mapping;

	mapping["+left"] = PLUS_LEFT;
	mapping["+right"] = PLUS_RIGHT;
	mapping["-left"] = MINUS_LEFT;
	mapping["-right"] = MINUS_RIGHT;

	while (getline(cin, s))
	{
		cmd = s.substr(0, s.find(delimiter));
		s.erase(0, s.find(delimiter));
		num = stoi(s);
		switch (mapping[cmd])
		{
		case PLUS_LEFT:
			trains.push_front(num);
			break;
		case PLUS_RIGHT:
			trains.push_back(num);
			break;
		case MINUS_LEFT:
			if (num > (int)trains.size())
				num = (int)trains.size();
			trains.erase(trains.begin(), trains.begin() + num);
			break;
		case MINUS_RIGHT:
			if (num > (int)trains.size())
				num = (int)trains.size();
			trains.erase(trains.end() - num, trains.end());
			break;
		default:
			break;
		}
	}
	for (int i : trains)
	{
		cout << i << " ";
	}
	cout << endl;
}

void MakeTrain_test(string filename)
{
	ifstream test_file;
	deque<int> trains = {};
	char delimiter = ' ';
	int num;
	string s, cmd;
	map<string, int> mapping;

	mapping["+left"] = PLUS_LEFT;
	mapping["+right"] = PLUS_RIGHT;
	mapping["-left"] = MINUS_LEFT;
	mapping["-right"] = MINUS_RIGHT;

	test_file.open(filename);

	while (getline(test_file, s))
	{
		cmd = s.substr(0, s.find(delimiter));
		s.erase(0, s.find(delimiter));
		num = stoi(s);
		switch (mapping[cmd])
		{
		case PLUS_LEFT:
			trains.push_front(num);
			break;
		case PLUS_RIGHT:
			trains.push_back(num);
			break;
		case MINUS_LEFT:
			if (num > (int)trains.size())
				num = (int)trains.size();
			trains.erase(trains.begin(), trains.begin() + num);
			break;
		case MINUS_RIGHT:
			if (num > (int)trains.size())
				num = (int)trains.size();
			trains.erase(trains.end() - num, trains.end());
			break;
		default:
			break;
		}
		cout << "NON FINAL RESULT" << endl;
		for (int i : trains)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "RESULT" << endl;
	for (int i : trains)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	cout << "TEST 1" << endl;
	MakeTrain_test("test_files/test1.txt");

	cout << "TEST 2" << endl;
	MakeTrain_test("test_files/test2.txt");

	cout << "TEST 3" << endl;
	MakeTrain_test("test_files/test3.txt");
}