#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include"Header.h"
#include"Source5.cpp"
using namespace std;



int main()
{
	int k = 0;
	int vvv[20][20];
	int score[20] = { 0 };
	string country[20];
	setlocale(0, "ukrainian");
	filein(country, vvv, k);
	for (int i = 0; i < 20; i++) countscore(i, vvv, k, score);
	top10sort(country, score, k);
	topout(country, score, k);
	return 0;
}

