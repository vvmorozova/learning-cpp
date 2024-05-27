#include "rocks.h"
int rocks(ifstream &inFile)
{
	int rockArray[1000][1000], n, m;
	inFile >> n >> m;
	// one rock
	for (int i = 1; i < n + 1; i++)
		if (rockArray[i - 1][0] == 1)
			rockArray[i][0] = 0;
		else
			rockArray[i][0] = 1;

	for (int j = 1; j < m + 1; j++)
		if (rockArray[0][j - 1] == 1)
			rockArray[0][j] = 0;
		else
			rockArray[0][j] = 1;
	// two rocks from one pile
	for (int i = 2; i < n + 1; i++)
		for (int j = 2; j < m + 1; j++)
			if (rockArray[i - 2][j] == 1 && rockArray[i][j - 2] == 1 &&
				rockArray[i][j - 1] == 1 && rockArray[i - 1][j] == 1)
				rockArray[i][j] = 0;
			else
				rockArray[i][j] = 1;
	// three rocks, 2 from one pile and 1 from another
	for (int i = 2; i < n + 1; i++)
		for (int j = 2; j < m + 1; j++)
			if (rockArray[i - 2][j - 1] == 1 && rockArray[i - 1][j - 2] == 1 &&
				rockArray[i - 2][j] == 1 && rockArray[i][j - 2] == 1 &&
				rockArray[i][j - 1] == 1 && rockArray[i - 1][j] == 1)
				rockArray[i][j] = 0;
			else
				rockArray[i][j] = 1;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << rockArray[i][j] << " ";
		cout << endl;
	}
	cout << "my res " << rockArray[n][m] << endl;
	return rockArray[n][m];
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	string res;

	inFile.open(input);
	outFile.open(output);

	outFile >> res;
	cout << "right res " << res << endl;

	return rocks(inFile) == (res == "Win" ? 1 : 0);
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/rocks2/";
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