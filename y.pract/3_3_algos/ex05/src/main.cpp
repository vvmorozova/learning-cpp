#include "ex05.h"
template <typename T, class OutputIt>
void PrintResults(vector<T>::iterator filtered, OutputIt filteredLast)
{
	cout << "iter" << endl;
	for (auto iter = filtered.begin(); iter != filtered.end(); iter++)
	{
		cout << *iter << " ";
	}
}

template <typename T>
void Process(const std::vector<T> &data)
{
	std::vector<T> filtered;

	std::copy_if(
		data.begin(),
		data.end(),
		std::back_inserter(filtered),
		[](const T &x)
		{ return x > 0; });

	PrintResults(filtered.begin(), filteredLast);
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	// int num, n, k;
	vector<int> data = {2, 1, -10, 3};

	inFile.open(input);
	outFile.open(output);

	Process(data);

	return true;
}

int main(int argc, char *argv[])
// int main()
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 4);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/mnt/c/Users/morozovavv/Documents/learning-cpp/y.pract/3_3_algos/ex04/";
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