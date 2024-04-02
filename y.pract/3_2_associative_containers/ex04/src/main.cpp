#include "ex04.h"

bool subjectIndex(string input, string output)
{
	std::map<int, std::set<std::string>> words;
	ifstream inFile, outFile;
	string word;
	int amount, page;

	inFile.open(input);
	outFile.open(output);

	inFile >> amount;

	cout << "num " << amount << endl;
	for (int i = 0; i < amount; i++)
	{
		inFile >> word >> page;
		cout << "page " << page << " word " << word << endl;
		words[page].insert(word);
	}

	cout << "ANSWER" << endl;
	string prevWord = "";
	for (const auto& [currPage, wordsSet] : words)
	{
		cout << currPage;
		for (string s : wordsSet)
		{
			cout << " " << s;
		}
		cout << endl;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	string inputPath = "test_files/input/", outputPath = "test_files/output/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = subjectIndex(inputPath + "test" + to_string(i) + ".txt",
								outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (long unsigned int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}