#include "hanoi_towers.h"
//{0,1,3,5,9,13,17,25,33,41,49,65,81,97,113}
int hanoi_towers(int n)
{
	int res = 0;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int k = static_cast<int>(round(sqrt(2 * n)));
	res = 2 * hanoi_towers(n - k) + pow(2, k) - 1;
	return res;
}

bool prepare(string input, string output)
{
	ifstream inFile;
	ifstream outFile;
	// string res;
	int n, moves, resMoves;

	inFile.open(input);
	outFile.open(output);

	inFile >> n;
	cout << " N " << n << endl;
	moves = hanoi_towers(n);
	cout << " res " << moves << endl;
	outFile >> resMoves;

	return resMoves == moves;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/hanoi_towers4/";
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