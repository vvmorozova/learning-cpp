#include "greedy_algo.h"

int findMeetingRoom(ifstream &inFile)
{
	vector<pair<int, int>> segments;
	int number, l, r, minL, minR, amount = 0;

	inFile >> number;
	for (int i = 0; i < number; i++)
	{
		inFile >> l >> r;
		segments.push_back(std::make_pair(l, r));
	}
	sort(segments.begin(), segments.end(), [](pair<int, int> &a, pair<int, int> &b)
		 { return b.second > a.second; });

	while (segments.size() > 0)
	{
		minL = segments[0].first;
		minR = segments[0].second;
		while (((segments[0].first >= minL && segments[0].first <= minR) ||
				(segments[0].second >= minL && segments[0].second <= minR) ||
				(segments[0].first <= minL && segments[0].second  >= minR)) &&
			   segments.begin() != segments.end())
		{
			segments.erase(segments.begin());
		}
		amount++;
	}
	cout << "my res " << amount << endl;
	return amount;
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	int res;

	inFile.open(input);
	outFile.open(output);

	outFile >> res;
	cout << "right res " << res << endl;

	return findMeetingRoom(inFile) == res;
}

int main(int argc, char *argv[])
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/home/rubetek/Documents/learning-cpp/y.pract/algos/greedy_algos/";
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