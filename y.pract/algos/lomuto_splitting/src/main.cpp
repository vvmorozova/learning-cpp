#include "lomuto_splitting.h"

int lomuto_splitting(vector<int> &list, int left, int right)
{
	vector<int> listLess, listMore;

	int pivot = list[left];

	int i = left + 1;
	for (int j = left + 1; j < right; j++)
	{
		if (list[j] <= pivot)
		{
			listLess.push_back(list[j]);
		}
		else
		{
			listMore.push_back(list[j]);
		}
	}
	list.erase(next(list.begin(), 1), list.end());
	list.insert(list.end(), listLess.begin(), listLess.end());
	swap(list[left], list[list.size() - 1]);
	list.insert(list.end(), listMore.begin(), listMore.end());

	return i + 1;
}

bool prepare(string input, string output)
{
	ifstream inFile;
	ifstream outFile;
	string res, correctRes;
	vector<int> to_split, sorted;
	int n, a;

	inFile.open(input);
	outFile.open(output);

	inFile >> n;
	for (int i = 0; i < n; i++)
	{
		inFile >> a;
		to_split.push_back(a);
	}

	auto start = std::chrono::high_resolution_clock::now();

	lomuto_splitting(to_split, 0, to_split.size());

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Время выполнения функции: " << duration.count() << " секунд" << std::endl;

	for (int i = 0; i < n; i++)
	{
		cout << to_split[i] << " ";
		res.append(to_string(to_split[i]));
		res.append(" ");
	}
	cout << endl;
	getline(outFile, correctRes);
	cout << "CORRECT " << endl;
	cout << correctRes << endl;
	cout << endl;
	inFile.close();
	outFile.close();

	return correctRes == res;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/lomuto_splitting/";
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