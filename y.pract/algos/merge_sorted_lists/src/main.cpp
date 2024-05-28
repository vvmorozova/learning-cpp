#include "merge_sorted_lists.h"

void merge_sorted_lists(ifstream &inFile)
{
	string line;
	int n, m, k = 0, maxLen = 0, min, minI = 0, l;
	vector<int> rez;
	vector<vector<int>> sequences;

	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		sequences.push_back({});
		inFile >> m;
		maxLen += m;

		for (int j = 0; j < m; j++)
		{
			inFile >> l;
			sequences[i].push_back(l);
		}
	}

	while (k < maxLen)
	{
		min = 2147483647;
		for (int i = 0; i < n; i++)
		{

			if (sequences[i].size() && sequences[i][0] <= min)
			{

				min = sequences[i][0];
				minI = i;
			}
		}
		rez.push_back(min);
		cout << min << " ";
		sequences[minI].erase(sequences[minI].begin());
		k++;
	}
}

bool prepare(string input, string output)
{
	ifstream inFile;
	ifstream outFile;
	string res, correctRes;

	inFile.open(input);
	outFile.open(output);

	merge_sorted_lists(inFile);

	cout << "REZ " << res << endl;
	cout << "COR " << correctRes << endl;
	inFile.close();
	outFile.close();

	return 1;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/merge_sorted_lists/";
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