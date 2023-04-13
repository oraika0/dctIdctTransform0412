#include <iostream>
#include <math.h>
#include <vector>
#define pi 3.14159265f

using namespace std;
void getData(vector<vector<int>>& pic);
void dct_2d(vector<vector<int>>& pic, vector<vector<int>>& picDct);
void idct_2d(vector<vector<int>>& picDct, vector<vector<int>>& picDctIdct);
double C(int i);
void print(vector<vector<int>>& input);
void error(vector<vector<int>>& input1, vector<vector<int>>& input2);

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
	error(pic, picDctIdct);
}

void getData(vector<vector<int>>& pic) {
	int length, width;
	cout << "picture's width : ";
	cin >> width;
	cout << "picture's length : ";
	cin >> length;

	cout << "Enter your data from left to right , top to down" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "row : " << i + 1 << endl;
		vector<int> tempVector;
		for (int j = 0; j < width; j++)
		{
			int tempInt;
			cin >> tempInt;
			tempVector.push_back(tempInt);
		}
		pic.push_back(tempVector);
		cout << endl;
	}
	cout << "(input complete)";
}

void dct_2d(vector<vector<int>>& pic, vector<vector<int>>& picDct) {
	vector<int> NVector = pic[0];
	int N = pic.size(); //width
	int M = NVector.size();//column
	//cout << N << " " << M;
	for (int u = 0; u < N; u++) {
		vector<int> tempVector;
		for (int v = 0; v < M; v++) {
			double sigmaCal = 0;
			for (int sigmaI = 0; sigmaI < N; sigmaI++) {
				for (int sigmaJ = 0; sigmaJ < M; sigmaJ++) {


					//cout << endl << sigmaJ << " ";
					//cout << pic[sigmaI][sigmaJ] << endl;
					sigmaCal += pic[sigmaI][sigmaJ] * cos(((2 * sigmaI + 1) * u * pi) / (2 * M)) * cos(((2 * sigmaJ + 1) * v * pi) / (2 * N));

				}
			}
			tempVector.push_back((2 * C(u) * C(v)) / (sqrt(M * N)) * sigmaCal);
		}
		picDct.push_back(tempVector);
	}
}

void idct_2d(vector<vector<int>>& picDct, vector<vector<int>>& picDctIdct) {
	vector<int> NVector = picDct[0];
	int N = picDct.size(); //width
	int M = NVector.size();//column
	for (int m = 0; m < M; m++) {
		vector<int> tempVector;
		for (int n = 0; n < N; n++) {
			double sigmaCal = 0;
			for (int sigmaU = 0; sigmaU < N; sigmaU++) {
				for (int sigmaV = 0; sigmaV < M; sigmaV++) {
					sigmaCal += (2 * C(sigmaU) * C(sigmaV)) / (sqrt(M * N)) * picDct[sigmaU][sigmaV] * cos(((2 * m + 1) * sigmaU * pi) / (2 * M)) * cos(((2 * n + 1) * sigmaV * pi) / (2 * N));
				}
			}
			tempVector.push_back(sigmaCal);
		}
		picDctIdct.push_back(tempVector);
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

void print(vector<vector<int>>& input) {
	for (int i = 0; i < input.size(); i++)
	{
		vector<int> tempVector;
		tempVector = input[i];
		for (int j = 0; j < input[0].size(); j++) {
			cout << tempVector[j] << " ";
		}
		cout << endl;
	}
}
void error(vector<vector<int>>& input1, vector<vector<int>>& input2) {
	double error = 0;
	for (int i = 0; i < input1.size(); i++)
	{
		for (int j = 0; j < input1[0].size(); j++) {
			error += abs((double(input1[i][j]) - input2[i][j]) / input2[i][j]);
		}
	}
	cout << "error : " << error / input1.size() * input1[0].size() << "%";
}