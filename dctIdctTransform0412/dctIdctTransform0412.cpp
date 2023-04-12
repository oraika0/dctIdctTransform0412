#include <iostream>
#include <math.h>
#include <vector>

#define pi 3.14159265f

using namespace std;
void getData(vector<vector<int>> pic);
void dct_2d(vector<vector<int>> pic, vector<vector<int>> picDct);
void idct_2d(vector<vector<int>> picDct, vector<vector<int>> picDctIdct);
double C(int i);
void print(vector<vector<int>> input);

int main()
{
	vector<vector<int>> pic;
	vector<vector<int>> picDct;
	vector<vector<int>> picDctIdct;
	getData(pic);
	dct_2d(pic, picDct);
	idct_2d(picDct, picDctIdct);
	cout << "original : " << endl;
	print(pic);
	cout << "after dct : " << endl;
	print(picDct);
	cout << "idct: " << endl;
	print(picDctIdct);

}

void getData(vector<vector<int>> pic){
	int length,width;
	cout << "picture's length : ";
	cin >> length;
	cout << "picture's width : ";
	cin >> width;
	cout << "Enter your data from left to right , top to down";
	for (int i = 0; i < length; i++)
	{
		cout << "row " << i + 1 << " : ";
		for (int j = 0; j < width; j++)
		{
			cin >> pic[i][j];
		}
		cout << endl;
	}
	cout << "(input conplete)";
}

void dct_2d(vector<vector<int>> pic , vector<vector<int>> picDct) {
	int M = pic[0].size();
	int N = pic.size();
	for (int u = 0; u < M ; u++){
		for (int v = 0; v < N ; v++) {
			double sigmaCal = 0;
			for (int sigmaI = 0; sigmaI < M ; sigmaI++){
				for (int sigmaJ = 0; sigmaJ < N ; sigmaJ++){
					sigmaCal += pic[sigmaI][sigmaJ] * cos(((2 * sigmaI + 1) * u * pi)/(2 * M)) * cos(((2 * sigmaJ + 1) * v * pi) / 2 * N);
				}
			}
			picDct[u][v] = (2 * C(u) * C(v)) / (sqrt(M * N)) *  sigmaCal;
		}
	}
}

void idct_2d(vector<vector<int>> picDct, vector<vector<int>> picDctIdct) {
	int M = picDct[0].size();
	int N = picDct.size();
	for (int I = 0; I < M; I++) {
		for (int J = 0; J < N; J++) {
			double sigmaCal = 0;
			for (int sigmaU = 0; sigmaU < M; sigmaU++) {
				for (int sigmaV = 0; sigmaV < N; sigmaV++) {
					sigmaCal += (2 * C(sigmaU) * C(sigmaV)) / (sqrt(M * N)) * picDct[sigmaU][sigmaV] * cos(((2 * sigmaU + 1) * I * pi) / (2 * M)) * cos(((2 * sigmaV + 1) * J * pi) / 2 * N);
				}
			}
			picDctIdct[I][J] =  sigmaCal;
		}
	}
}

double C(int i) {
	if (i == 0)
	{
		return 1 / sqrt(2);
	}
	else
	{
		return 1;
	}
}

void print(vector<vector<int>> input) {
	for (int i = 0; i < input[0].size() ; i++)
	{
		for (int j = 0; j < input.size(); j++) {
			cout << input[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

