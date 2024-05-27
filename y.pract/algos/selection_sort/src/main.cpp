#include "selection_sort.h"

int *selection_sort(int n, int a[1000])
{
	int tmp;
	for (int i = 0; i < n; i++)
	{
		int *min = a + i;
		for (int j = i; j < n; j++)
		{
			if (*min > a[j])
				min = a + j;
		}
		tmp = *min;
		*min = a[i];
		a[i] = tmp;
	}
	return a;
}

bool prepare(string input, string output)
{
	ifstream inFile;
	ifstream outFile;
	string res, correctRes;
	int n, a[1000], *rez;

	inFile.open(input);
	outFile.open(output);

	inFile >> n;
	for (int i = 0; i < n; i++)
		inFile >> a[i];
	rez = selection_sort(n, a);
	for (int i = 0; i < n; i++)
	{
		res.append(to_string(rez[i]));
		if (i + 1 < n)
			res.append(" ");
	}
	for (int i = 0; i < n; i++)
	{
		string s;
		outFile >> s;
		correctRes.append(s);
		if (i + 1 < n)
			correctRes.append(" ");
	}
	cout << "REZ " << res << endl;
	cout << "COR " << correctRes << endl;

	return res == correctRes;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/selection_sort/";
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