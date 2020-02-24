#include <iostream>
#include <fstream>

using namespace std;

void readf(string filename, string country[20], int vvv[20][20], int &kk);
void outm(string country[20], int vvv[20][20], int k);

int main()
{
	int kk = 0;
	int vvv[20][20];
	string country[20];

	readf("C:\\DDDev\\1.txt", country, vvv, kk);
	readf("C:\\DDDev\\2.txt", country, vvv, kk);

	outm(country, vvv, kk);
	return 0;
}

void outm(string country[20], int vvv[20][20], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << country[i];
		for (int j = 0; j < 20; j++)
		{
			cout << vvv[i][j] << " ";
		}
		cout << endl;
	}
}
void readf(string filename, string country[20], int vvv[20][20], int &kk)
{
	ifstream fin(filename);
	int c=-1;
	fin >> c;
	//cout << c << endl;
	for (int i = 0+kk; i < c+kk; i++)
	{
		fin >> country[i];
		for (int j = 0; j < 20; j++)
		{
			fin >> vvv[i][j];
		}
	}
	kk += c;
}