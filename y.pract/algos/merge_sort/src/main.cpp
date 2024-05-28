#include "merge_sort.h"

void merge(vector<int> a, vector<int> b, vector<int> &rez)
{
	int k = 0, maxLen = 0;
	long unsigned int i = 0, j = 0;

	maxLen = a.size() + b.size();

	while (k < maxLen)
	{

		if (i >= a.size() || (b[j] <= a[i] && j < b.size()))
		{
			rez.push_back(b[j]);
			j++;
		}
		else
		{
			rez.push_back(a[i]);
			i++;
		}
		k++;
	}
}

vector<int> merge_sort(vector<int> list)
{
	vector<int> firstHalf, lastHalf, rez;
	int middle = 0;
	if (list.size() == 1)
	{
		return list;
	}
	middle = list.size() / 2;
	copy(list.begin(), next(list.begin(), middle), back_inserter(firstHalf));
	copy(next(list.begin(), middle), list.end(), back_inserter(lastHalf));
	firstHalf = merge_sort(firstHalf);
	lastHalf = merge_sort(lastHalf);
	merge(firstHalf, lastHalf, rez);
	return rez;
}

bool prepare(string input, string output)
{
	ifstream inFile;
	ifstream outFile;
	string res, correctRes;
	vector<int> to_sort, sorted;
	int n, a;

	inFile.open(input);
	outFile.open(output);

	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> a;
		to_sort.push_back(a);
	}

	auto start = std::chrono::high_resolution_clock::now();

	sorted = merge_sort(to_sort);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Время выполнения функции: " << duration.count() << " секунд" << std::endl;

	// for (int i = 0; i < n; i++)
	// {
	// 	cout << sorted[i] << " ";
	// }
	cout << endl;
	inFile.close();
	outFile.close();

	return 1;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/merge_sort/";
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