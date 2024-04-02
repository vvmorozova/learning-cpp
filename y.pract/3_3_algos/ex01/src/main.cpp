#include "ex01.h"

template <typename T>
void Duplicate(std::vector<T> &v)
{
	auto len = v.size();
	for (long unsigned int i = 0; i < len; i++)
	{
		v.push_back(v[i]);
	}
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
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
	vector<int> test = {1, 2, 3};
	Duplicate(test);
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