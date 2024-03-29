#pragma once

#include <cstdio>
#include <iostream>
#include <list>
#include <iterator>
#include <deque>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void print_list(list<string> toPrint, string msg);
bool print_to_file_and_compare(list<string> toPrint, string reference);
