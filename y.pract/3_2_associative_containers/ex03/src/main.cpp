#include "ex03.h"

bool fileSystem(string input, string output)
{
	ifstream inFile, outFile;
	string path, delimiter = "/", currPath, s;
	map<string, int> allPathes;

	inFile.open(input);
	outFile.open(output);

	while (inFile >> path)
	{
		cout << "path " << path << endl;
		size_t pos = 0, prevLen = 0;
		std::string elem, pathCopy = path, elemShort;
		do
		{
			elem = path.substr(0, pos + prevLen + 1);
			elemShort = pathCopy.substr(0, pos);
			cout << "elemShort " << elemShort << endl;
			cout << "pathCopy " << pathCopy << endl;
			cout << "ELEM " << elem << endl;
			if (elem != "")
			{
				cout << "prevElem " << elem << endl;
				if (allPathes.find(elem) != allPathes.end())
					allPathes[elem] = 1;
				else
					allPathes[elem]++;
			}
			pathCopy.erase(0, pos + delimiter.length());
			prevLen += elemShort.size() + 1;
		} while ((pos = pathCopy.find(delimiter)) != std::string::npos);
	}
	cout << "ANSWERS" << endl;
	for (const auto &[pathName, content] : allPathes)
	{
		// if (content > 0)
		cout << pathName << endl;
		currPath = pathName;
		outFile >> s;
		// cout << s << endl;
		if (s != currPath)
		{
			cout << "here 1" << endl;
			return false;
		}
	}
	string sLast;
	outFile >> sLast;
	if (s != sLast && sLast != "") 
	{
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int minTest = (argc > 1 ? stoi(argv[1]) : 3), maxTest = (argc > 1 ? stoi(argv[2]) : 5);
	string inputPath = "test_files/input/", outputPath = "test_files/output/";
	vector<bool> test_rez = {};
	for (int i = minTest; i < maxTest; i++)
	{
		cout << "TEST " << i << endl;
		bool rez = fileSystem(inputPath + "test" + to_string(i) + ".txt",
							  outputPath + "test" + to_string(i) + ".txt");
		test_rez.push_back(rez);
	}
	for (int i = 0; i < test_rez.size(); i++)
	{
		cout << "TEST " << i + minTest << (test_rez[i] ? " OK" : " FAIL") << endl;
	}
}