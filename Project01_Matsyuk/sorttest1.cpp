// FILE: sorttest1.cpp 
//By: Daniel Matsyuk
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include <cstddef>
using namespace std;
string* tempfile = new string[10];
void bubblesort(string data[], size_t n)
{
	int k = 0;
	bool switched = true;
	while (k < n - 1 && switched)
	{
		switched = false;
		k++;
		for (size_t i = 0; i < n - k; ++i)
		{
			if (data[i] > data[i + 1])
			{
				swap(data[i], data[i + 1]);
				switched = true;
			}
		}
	}
}
bool check_ordered(string data[], size_t n)
{
	bool ordered = false;
	for (int i = 0; i < n-1; ++i)
	{
		if (data[i] < data[i + 1]) 
		{
			ordered = true;
		}
		else
		{
			ordered = false;
		}
	}
	return ordered;
}
int readFile(string inputName)
{
	string arraySize;
	fstream inputFile; 
	inputFile.open(inputName, ios::in);
	if (inputFile.is_open())
	{
		getline(inputFile, arraySize);
		int arraySize_INT = stoi(arraySize);
		tempfile[arraySize_INT];
		while (!inputFile.eof())
		{
			for (int i = 0; i < arraySize_INT; i++)
			{
				getline(inputFile, tempfile[i]);
			}
		}
		inputFile.close();
		return arraySize_INT;
	}
	if (inputFile.fail())
	{
		cout << inputName << " Does not exist";
		exit(1);
		return 0;
	}
}
void writeFile(string data[], string outputname)
{
	fstream outputFile;
	outputFile.open(outputname, ios::out);
	if (outputFile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			outputFile << data[i] << "\n";
		}
		outputFile.close();
	}
	if (outputFile.fail())
	{
		cout << outputname << " Does not exist";
		exit(1);
	}
}
void swap(string& s1, string& s2)
{
	string temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}
int main(int argc, char** argv)
{
	string inputFileName = "simpleInputTextFile.txt";
	string outputFileName = "simpleOutputTextFile.txt";
	rsize_t ArraySize = readFile(inputFileName);
	bubblesort(tempfile, ArraySize);
	if (check_ordered(tempfile, ArraySize));
	else { exit(1); }
	writeFile(tempfile,outputFileName);
	delete[] tempfile;
	return 0;
}
