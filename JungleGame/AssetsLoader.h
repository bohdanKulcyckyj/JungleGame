#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class AssetsLoader
{
public:
	static vector<string> loadImagesFromDirectory(string dir);
};

