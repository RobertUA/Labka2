#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readf(string filename, string country[20], int vvv[20][20], int &kk);
void outm(string country[20], int vvv[20][20], int k);

int main()
{
	int kk = 0;
	int vvv[20][20];
	string country[20];

	readf("C:\\DDDev\\11.csv", country, vvv, kk);
	readf("C:\\DDDev\\22.csv", country, vvv, kk);

	outm(country, vvv, kk);
	return 0;
}

void outm(string country[20], int vvv[20][20], int k)
{
	for (int i = 0; i < k; i++)
	{
		if(country[i].find('\n')==0) country[i].erase(0, 1);
		cout << country[i];
		for (int j = 0; j < 20; j++)
		{
			cout << " " << vvv[i][j];
		}
		cout <<  endl;
	}
}
void readf(string filename, string country[20], int vvv[20][20], int &kk)
{
	ifstream fin(filename);
	string LINE;
	string add;
	int c = -1, w = 0;
	fin >> c;
	for (int i = 0+kk; i < c+kk; i++)
	{
		getline(fin, country[i], ',');
		for (int j = 0; j < 19; j++)
		{
			getline(fin, LINE, ',');
			vvv[i][j] = stoi(LINE);
		}
		getline(fin, LINE, '\n');
		vvv[i][19] = stoi(LINE);
	}
	kk += c;
}