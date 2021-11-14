// al7619_hw14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
//

vector<int> minMax(vector<int>& v, int min, int max);
vector<int> compare(vector<int>& vect1, vector<int>& vect2);

int main()
{
	vector<int> vect;

	for (int i = 0; i < 20; i++) {
		vect.push_back(rand() % 50 + 1);
	}

	for (int x : vect)
		cout << x << " ";
	cout << endl;

	vector<int> vectFunc = minMax(vect, 0, vect.size() - 1);
	cout << "min: " << vectFunc[0] << "\nmax: " << vectFunc[1] << endl;
	return 0;
}

vector<int> minMax(vector<int>& v, int min, int max) {
	if (min == max) {
		vector<int> minMaxVect{ v[min] };
		minMaxVect.push_back(v[min]);
		return minMaxVect;
	}
	else {
		int mid = (max + min) / 2;
		vector<int> left = minMax(v, min, mid);
		vector<int> right = minMax(v, mid + 1, max);
		return compare(left, right);
	}
}

vector<int> compare(vector<int>& vect1, vector<int>& vect2) {
	vector<int> combine(2);

	if (vect1[0] <= vect2[0]) {
		combine[0] = vect1[0];
	}
	else combine[0] = vect2[0];

	if (vect1[1] >= vect2[1]) { // ensure that the max is return to combine[1]
		combine[1] = vect1[1];
	}
	else combine[1] = vect2[1];

	return combine;
}