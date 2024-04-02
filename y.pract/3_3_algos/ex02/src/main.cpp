#include "ex02.h"

template <typename Iter>
Iter Unique(Iter first, Iter last)
{
	if (first == last)
		return (first);

	Iter result;
	while (++first != last)
		if (!(*result == *first) && ++result != first)
			*result = std::move(*first);
	return ++result;
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	int elem;
	vector<int> test;
	inFile.open(input);
	outFile.open(output);

	while (inFile >> elem)
	{
		test.push_back(elem);
	}
	cout << "before" << endl;
	for (int i : test)
	{
		cout << " " << i;
	}
	cout << endl;
	auto uniq = Unique(test.begin(), test.end());
	cout << "after" << endl;
	for (auto iter = test.begin(); iter != uniq; iter++)
	{
		outFile >> elem;
		if (elem != *iter)
			return false;
		cout << " " << *iter;
	}
	cout << endl;

	return true;
}

int main(int argc, char *argv[])
// int main()
{
	// vector<int> test = {1, 2, 3};

	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	string inputPath = "test_files/input/", outputPath = "test_files/output/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = prepare(inputPath + "test" + to_string(i) + ".txt",
						   outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (long unsigned int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}