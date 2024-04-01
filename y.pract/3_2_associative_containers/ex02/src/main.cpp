#include "ex02.h"

bool findCommonLetters(string input, string output)
{
	ifstream test_file, result;
	map<char, int> letters = {};
	int numOfWords = 0;
	string word, rez, answer;

	test_file.open(input);
	result.open(output);

	while (test_file >> word)
	{
		numOfWords++;
		std::set<char> unique(word.begin(), word.end());
		for (char i : unique)
		{
			auto it = letters.find(i);
			if (letters.find(i) == letters.end())
				letters[i] = 1;
			else
				letters[i]++;
		}
	}
	for (const auto &[letter, num] : letters)
	{
		if (letters[letter] == numOfWords)
		{
			cout << letter;
			answer.push_back(letter);
		}
	}
	cout << endl;
	cout << "answer " << answer << endl;
	result >> rez;
	return (rez == answer);
}
int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	string inputPath = "test_files/input/", outputPath = "test_files/output/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = findCommonLetters(inputPath + "test" + to_string(i) + ".txt",
									 outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}