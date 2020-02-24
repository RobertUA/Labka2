﻿#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readf(string filename, string country[20], int vvv[20][20], int &kk);
void outm(string country[20], int vvv[20][20], int k);
void countscore(int ctry, int vvv[20][20], int k, int score[20]);
void top10sort(string country[20], int score[20], int k);
void topout(string country[20], int score[20], int k);

int main()
{
	int kk = 0;
	int vvv[20][20];
	int score[20] = { 0 };
	string country[20];

	readf("C:\\DDDev\\test1.csv", country, vvv, kk);
	readf("C:\\DDDev\\test2.csv", country, vvv, kk);

	//outm(country, vvv, kk);
	for (int i = 0; i < 20; i++) countscore(i, vvv, kk, score);

	top10sort(country, score, kk);
	topout(country, score, kk);
	return 0;
}

void topout(string country[20], int score[20], int k)
{
	ofstream fout("results.csv");
	for (int i = 0; i < (k > 10 ? 10 : k); i++)
	{
		fout << country[i] << "," << score[i] << endl;
	}
}
void top10sort(string country[20], int score[20], int k)
{
	int h;
	string hh;
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i; j < k; j++)
		{
			if (score[i] < score[j])
			{
				hh = country[i];
				country[i] = country[j];
				country[j] = hh;
				h = score[i];
				score[i] = score[j];
				score[j] = h;
			}
		}
	}
}
void countscore(int ctry, int vvv[20][20], int k, int score[20])
{
	int nv[20][2];
	int h;
	for (int i = 0; i < k; i++)
	{
		nv[i][0] = vvv[i][ctry];
		nv[i][1] = i;
	}
	for (int i = 0; i < k-1; i++)
	{
		for (int j = i; j < k; j++)
		{
			if (nv[i][0] < nv[j][0])
			{
				h = nv[i][0];
				nv[i][0] = nv[j][0];
				nv[j][0] = h;
				h = nv[i][1];
				nv[i][1] = nv[j][1];
				nv[j][1] = h;
			}
		}
	}
	for (int i = 0; i < (k > 10 ? 10 : k); i++)
	{
		if(i==0) score[nv[i][1]] += 12;
		else if(i==1) score[nv[i][1]] += 10;
		else if(i>=2 && i<=9) score[nv[i][1]] += 10 - i;
		//cout << nv[i][0] << " " << nv[i][1] << endl;
	}
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