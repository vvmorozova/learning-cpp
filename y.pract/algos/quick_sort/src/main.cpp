#include "quick_sort.h"

int lomuto_splitting(vector<int> &list, int left, int right)
{
	vector<int> listLess, listMore;

	int pivot = list[left], index;

	for (int j = left + 1; j <= right; j++)
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
	index = listLess.size() + left;
	list.erase(next(list.begin(), left + 1), next(list.begin(), right + 1));
	list.insert(next(list.begin(), left + 1), listLess.begin(), listLess.end());
	swap(list[left], list[listLess.size() + left]);
	list.insert(next(list.begin(), left + 1 + listLess.size()), listMore.begin(), listMore.end());

	return index;
}

void quick_sort(vector<int> &list, int left, int right)
{

	if (left < right)
	{
		int pivot_index = lomuto_splitting(list, left, right);
		quick_sort(list, left, pivot_index - 1);
		quick_sort(list, pivot_index + 1, right);
	}
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

	quick_sort(to_split, 0, to_split.size() - 1);

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
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/quick_sort/";
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