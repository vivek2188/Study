// LINEAR EQUATION SOLVER
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int size;
	cout << "Size of the matrix: ";
	cin >> size;
	cout << "Enter the matrix:\n";
	float mat[size+1][size+1];
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++)
			cin >> mat[i][j];
	}
	cout << "Performing decomposition...\n";
	int p[size+1];
	for(int i=1;i<=size;i++)
		p[i] = i;
	for(int k=1;k<=size;k++){
		int pi = 0,k1;
		for(int i=k;i<=size;i++){
			if(abs(mat[i][k])>pi){
				pi = abs(mat[i][k]);
				k1 = i;
			}
		}
		if(pi==0){
			cout << "Error\n";
			return 1;	
		}
		swap(p[k],p[k1]);
		for(int i=1;i<=size;i++)
			swap(mat[k][i],mat[k1][i]);
		for(int i=k+1;i<=size;i++){
			mat[i][k] /= mat[k][k];
			for(int j=k+1;j<=size;j++)
				mat[i][j] = mat[i][j] - mat[i][k] * mat[k][j];
		}
	}
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++)
			cout << mat[i][j] << "\t";
		cout << "\n";
	}	
	cout << "Decomposition done\n";
	return 0;
}
