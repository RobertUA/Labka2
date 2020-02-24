#include <iostream>
#include <fstream>

using namespace std;

void readf(string filename, string country[20], int vvv[20][20]);

int main()
{
	///						Ет шоб зчитувать з файлу (одного)
	//int vvv[20][20];
	//string country[20];
	//readf("C:\\DDDev\\1.txt", country, vvv);
	return 0;
}

void readf(string filename, string country[20], int vvv[20][20])
{
	ifstream fin(filename);
	int c=-1;
	fin >> c;
	cout << c << endl;
	for (int i = 0; i < c; i++)
	{
		fin >> country[i];
		for (int j = 0; j < 20; j++)
		{
			fin >> vvv[i][j];
		}
	}
	for (int i = 0; i < c; i++)
	{
		cout << country[i];
		for (int j = 0; j < 20; j++)
		{
			cout << " " << vvv[i][j];
		}
		cout << endl;
	}
}