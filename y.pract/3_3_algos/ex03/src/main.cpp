#include "ex03.h"

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
					  InIter2 first2, InIter2 last2,
					  OutIter out)
{
	while ( first1 != last1)
	{
		if (first2 == last2)
			return std::copy(first1, last1, out);

		if (*first1 < *first2)
			*out++ = *first1++;
		else
		{
			if (!(*first2 > *first1))
				++first1;
			++first2;
		}
	}
	return (out);
}

bool prepare(string input, string output)
{
	ifstream inFile, outFile;
	int amount, num;
	vector<int> startVector1 = {}, startVector2 = {},
				myVector(10, 0), corrVector = {};

	inFile.open(input);
	outFile.open(output);

	inFile >> amount;
	for (; amount > 0; amount--)
	{
		inFile >> num;
		startVector1.push_back(num);
	}

	inFile >> amount;
	for (; amount > 0; amount--)
	{
		inFile >> num;
		startVector2.push_back(num);
	}

	outFile >> amount;
	for (; amount > 0; amount--)
	{
		outFile >> num;
		corrVector.push_back(num);
	}

	auto lastIter = SetDifference(startVector1.begin(), startVector1.end(),
								  startVector2.begin(), startVector2.end(),
								  myVector.begin());

	myVector.erase(lastIter, myVector.end());
	cout << "RESULT" << endl;
	for (int i : myVector)
	{
		cout << i << " ";
	}
	cout << endl;
	return myVector == corrVector;
}

int main(int argc, char *argv[])
// int main()
{

	int minTest = (argc > 1 ? stoi(argv[1]) : 2), maxTest = (argc > 1 ? stoi(argv[2]) : 3);
	string inputPath = "test_files/input/", outputPath = "test_files/output/",
		   currDir =
			   "/mnt/c/Users/morozovavv/Documents/learning-cpp/y.pract/3_3_algos/ex03/";
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