#include "ex04.h"
void approximateBinSearch(array<int, 100000> firstArr,
						  array<int, 100000> secondArr, int firstLen,
						  int secondLen)
{
	for (int i = 0; i < secondLen; i++)
	{
		auto lowBound = (lower_bound(firstArr.begin(),
									 firstArr.begin() + firstLen,
									 secondArr[i]));
		if (lowBound != firstArr.begin() && lowBound !=  firstArr.begin() + firstLen)
		{
			auto prev = lowBound - 1;
			int nearest = *lowBound - secondArr[i] < secondArr[i] - *prev
							  ? *lowBound
							  : *prev;
			cout << nearest <<  endl;
		}
		else if (lowBound ==  firstArr.begin() + firstLen)
			cout << *(std::prev( firstArr.begin() + firstLen)) <<  endl;
		else
			cout << *lowBound <<  endl;
	}
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	int num, n, k;
	array<int, 100000> firstArr, secondArr;

	inFile.open(input);
	outFile.open(output);

	inFile >> n >> k;
	for (int i = 0; i < n; i++)
	{
		inFile >> num;
		firstArr[i] = num;
	}

	for (int i = 0; i < k; i++)
	{
		inFile >> num;
		secondArr[i] = num;
	}

	approximateBinSearch(firstArr, secondArr, n, k);

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