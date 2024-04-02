#include "ex03.h"

template <typename Iter>
Iter Unique(Iter first, Iter last)
{
	int uniqueNum = 0;

	for (auto iter = first; iter != last; iter++) {
		if (!binary_search(first, first + uniqueNum, *iter))
		{
			*(first + uniqueNum) = *iter;
			uniqueNum++;
		}
	}
	return (first + uniqueNum);
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	inFile.open(input);
	outFile.open(output);

	return true;
}

// int main(int argc, char *argv[])
int main()
{
	vector<int> test = {1, 2, 3, 3, 2, 5, 7, 10, 10, 10};
	auto uniq = Unique(test.begin(), test.end());
	for (int i : test)
	{
		cout << i << " " ;
	}
	cout << endl;
	for (auto iter = test.begin(); iter != uniq; iter++)
	{
		cout << *iter << " " ;
	}
	// int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	// string inputPath = "test_files/input/", outputPath = "test_files/output/";
	// vector<bool> test_rez = {};
	// for (int i = minTest; i < maxTest; i++)
	// {
	// 	cout << "TEST " << i << endl;
	// 	bool rez = prepare(inputPath + "test" + to_string(i) + ".txt",
	// 					   outputPath + "test" + to_string(i) + ".txt");
	// 	test_rez.push_back(rez);
	// }
	// for (long unsigned int i = 0; i < test_rez.size(); i++)
	// {
	// 	cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	// }
}