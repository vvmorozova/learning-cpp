#include "ex01.h"

int isBracketClosed(ifstream &inFile)
{
	stack<char> brackets;
	string bracketStr;
	array<char, 3> brOpen = {'{', '[', '('}, brClosed = {'}', ']', ')'};

	inFile >> bracketStr;
	for (char c : bracketStr)
	{
		if (find(begin(brOpen), end(brOpen), c) != end(brOpen))
			brackets.push(c);
		else
		{
			if (brackets.size() > 0 &&
				distance(brClosed.begin(), find(begin(brClosed), end(brClosed), c)) ==
					distance(brOpen.begin(), find(begin(brOpen), end(brOpen), brackets.top())))
			{
				brackets.pop();
			}
			else
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (brackets.size() > 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 1;
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	string s1, s2;

	inFile.open(input);
	outFile.open(output);

	outFile >> s2;
	int answer = (s2 == "YES" ? 1 : 0);

	return isBracketClosed(inFile) == answer;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/mnt/c/Users/morozovavv/Documents/learning-cpp/y.pract/3_4_adapters_n_views/ex01/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = prepare(currDir + inputPath + "test" + to_string(i) + ".txt",
						   currDir + outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (long unsigned int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}