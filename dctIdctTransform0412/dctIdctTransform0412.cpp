#include <iostream>
#include <math.h>
#include <vector>

#define pi 3.14159265f

using namespace std;
void getData(vector<vector<int>>& pic);
void dct_2d(vector<vector<int>>& pic, vector<vector<double>>& picDct);
void idct_2d(vector<vector<double>>& picDct, vector<vector<double>>& picDctIdct);
double C(int i);
void print(vector<vector<double>>& input);
void print(vector<vector<int>>& input);

int main()
{
	vector<vector<int>> pic;
	vector<vector<double>> picDct;
	vector<vector<double>> picDctIdct;
	getData(pic);
	print(pic);
	dct_2d(pic, picDct);
	idct_2d(picDct, picDctIdct);
	cout << "original : " << endl;
	//print(pic);
	cout << "after dct : " << endl;
	print(picDct);
	cout << "idct: " << endl;
	print(picDctIdct);

}

void getData(vector<vector<int>>& pic){
	int length,width;
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

void dct_2d(vector<vector<int>>& pic , vector<vector<double>>& picDct) {
	vector<int> NVector = pic[0]; 
	int N = NVector.size();//width
	int M = pic.size(); //height
	//cout << N << " " << M;
	for (int u = 0; u < M ; u++){
		vector<double> tempVector;
		for (int v = 0; v < N ; v++) {
			double sigmaCalOut = 0;
			for (int sigmaI = 0; sigmaI < M ; sigmaI++){
				double sigmaCalIn = 0;
				for (int sigmaJ = 0; sigmaJ < N ; sigmaJ++){


					//cout << endl << sigmaJ << " ";
					//cout << pic[sigmaI][sigmaJ] << endl;
					sigmaCalIn += pic[sigmaI][sigmaJ] * cos(((2 * sigmaI + 1) * u * pi) / (2 * N)) * cos(((2 * sigmaJ + 1) * v * pi) / (2 * M));
				}
				sigmaCalOut += sigmaCalIn;
			}
			tempVector.push_back((2 * C(u) * C(v)) / (sqrt(M * N)) * sigmaCalOut);
		}
		picDct.push_back(tempVector);
	}
}

void idct_2d(vector<vector<double>>& picDct, vector<vector<double>>& picDctIdct) {
	//vector<double> NVector = picDct[0];
	//int N = NVector.size();//width
	//int M = picDct.size(); //height
	//for (int I = 0; I < M; I++) {
	//	vector<double> tempVector;
	//	for (int J = 0; J < N; J++) {
	//		double sigmaCalOut = 0;
	//		for (int sigmaU = 0; sigmaU < M; sigmaU++) {
	//			double sigmaCalIn = 0;
	//			for (int sigmaV = 0; sigmaV < N ; sigmaV++) {
	//				sigmaCalIn += (2 * C(sigmaU) * C(sigmaV)) / (sqrt(M * N)) * picDct[sigmaU][sigmaV] * cos(((2 * sigmaU + 1) * I * pi) / (2 * N)) * cos(((2 * sigmaV + 1) * J * pi) / (2 * M));
	//			}
	//			sigmaCalOut += sigmaCalIn;
	//		}
	//		tempVector.push_back(sigmaCalOut);
	//	}
	//	picDctIdct.push_back(tempVector);
	//}

	vector<double> NVector = picDct[0];
	int N = NVector.size();//width
	int M = picDct.size(); //height
	//cout << N << " " << M;
	for (int u = 0; u < M; u++) {
		vector<double> tempVector;
		for (int v = 0; v < N; v++) {
			double sigmaCalOut = 0;
			for (int sigmaI = 0; sigmaI < M; sigmaI++) {
				double sigmaCalIn = 0;
				for (int sigmaJ = 0; sigmaJ < N; sigmaJ++) {


					//cout << endl << sigmaJ << " ";
					//cout << pic[sigmaI][sigmaJ] << endl;
					sigmaCalIn += (((2 * C(sigmaI) * C(sigmaJ)) / (sqrt(M * N))) * picDct[sigmaI][sigmaJ] * cos(((2 * sigmaI + 1) * u * pi) / (2 * N)) * cos(((2 * sigmaJ + 1) * v * pi) / (2 * M)));
				}
				sigmaCalOut += sigmaCalIn;
			}
			tempVector.push_back( sigmaCalOut);
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

void print(vector<vector<double>>& input) {
	for (int i = 0; i < input.size() ; i++)
	{
		vector<double> tempVector;
		tempVector = input[i];
		for (int j = 0; j < input[0].size(); j++) {
			cout << tempVector[j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
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
	cout << endl;
}

