#include <iostream>
#include <math.h>
#include <vector>

#define pi 3.14159265f

using namespace std;
void getData(vector<vector<int>> pic);
void dct_2d(vector<vector<int>> pic, vector<vector<int>> picDct);
void idct_2d(vector<vector<int>> picDct, vector<vector<int>> picDctIdct);
double C(int i);

int main()
{
	vector<vector<int>> pic;
	vector<vector<int>> picDct;
	vector<vector<int>> picDctIdct;
	getData(pic);
	dct_2d(pic, picDct);
	idct_2d(picDct, picDctIdct);

}

void getData(vector<vector<int>> pic){
	int length;
	cout << "picture's length(lenght should be equal to height to calculate) : ";
	cin >> length;
	cout << "Enter your data from left to right , top to down";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; i < length; j++)
		{
			cin >> pic[i][j];
		}
	}
	cout << "(input conplete)";
}

void dct_2d(vector<vector<int>> pic , vector<vector<int>> picDct) {
	for (int i = 0; i < pic.size() ; i++)
	{
		for (int j = 0; j < pic.size(); j++) {
			double sigmaCal = 0;
			for (int sigmaX = 0; sigmaX < pic.size() ; sigmaX++)
			{
				for (int sigmaY = 0; sigmaY < pic.size(); sigmaY++)
				{
					sigmaCal += pic[i][j] * cos(((2 * sigmaX + 1) * i * pi)/2 * pic.size()) * cos(((2 * sigmaY + 1) * j * pi) / 2 * pic.size());
				}
			}
			picDct[i][j] = 1 / 2 * sqrt(2 * pic.size()) * C(i) * C(j) * sigmaCal;
		}
	}
}

void idct_2d(vector<vector<int>> picDct, vector<vector<int>> picDctIdct) {
	;
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


