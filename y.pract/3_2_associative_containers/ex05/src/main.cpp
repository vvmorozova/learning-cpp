#include "ex05.h"

bool symbols(string input, string output)
{
	ifstream inFile, outFile;
	map<string, int> combinations;
	map<int, set<string>> numComb;
	string word;
	int m, n;

	inFile.open(input);
	outFile.open(output);

	inFile >> m >> n;
	for (int i = 0; i < m; i++)
	{
		inFile >> word;
		if ((long unsigned int)n > word.size())
			continue;
		for (int j = 0; (long unsigned int)j < word.size() - n + 1; j++)
		{
			string sub = word.substr(j, n);
			cout << "substr " << sub << endl;
			if (combinations.find(sub) != combinations.end())
			{
				combinations[sub]++;
			}
			else
			{
				combinations[sub] = 1;
			}
		}
	}
	cout << "ANSWER" << endl;
	for (auto iter = combinations.begin(); iter != combinations.end(); iter++) {
		numComb[iter->second].insert(iter->first);
	}
	for (auto iter = numComb.crbegin(); iter != numComb.crend(); ++iter) {
        for (const auto& currComb : iter->second) {
            cout << currComb << " - " << iter->first << endl;
        }
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
		bool rez = symbols(inputPath + "test" + to_string(i) + ".txt",
						   outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (long unsigned int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}