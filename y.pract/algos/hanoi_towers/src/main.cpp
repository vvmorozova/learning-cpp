#include "hanoi_towers.h"

void hanoi_towers(int n, int fromPeg, int toPeg)
{
	if (n == 1)
	{
		cout << fromPeg << " " << toPeg << endl;
		return;
	}
	int unusedPeg = 6 - fromPeg - toPeg;
	hanoi_towers(n - 1, fromPeg, unusedPeg);
	cout << fromPeg << " " << toPeg << endl;
	hanoi_towers(n - 1, unusedPeg, toPeg);
}

bool prepare(string input, string output)
{
	ifstream inFile;
	// ifstream outFile;
	(void)output;
	// string res;
	int n;

	inFile.open(input);

	inFile >> n;
	cout << pow(2, n) - 1 << endl;
	hanoi_towers(n, 1, 3);

	return 1;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/hanoi_towers/";
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