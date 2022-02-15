#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	vector <int> start = {1, 1}; // (Y, X)
	
	vector <int> mX = {0, 0, -1, 1};
	vector <int> mY = {-1, 1, 0, 0};
	// (U, D, L, R) = ( 상, 하, 좌, 우)
	vector <string> move = {"U", "D", "L", "R"};
	vector <string> run;
	
	cin >> n;
	
	vector <vector<int>> map(n, vector<int>(n));
	
	for(int i = 0; i < 6; i++) {
		string input;
		cin >> input;
		run.push_back(input);
	}
	
	for(auto &item : run){
		for(int i = 0; i < move.size(); i++){
			if( item == move[i]) {
				if( (start[1] + mX[i]) > n || (start[0] + mY[i]) > n || (start[1] + mX[i]) < 1 || (start[0] + mY[i]) < 1)
					continue;
				cout << i << "\n";
				start[1] += mX[i];//X
				start[0] += mY[i];//Y
			}
		}
	}
	cout << start[0] << ", "<< start[1]<< "\n";
	
	//code run
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << map[j][i] << " ";
		}
		cout << "\n";
	}
	
	
	
	return 0;
}