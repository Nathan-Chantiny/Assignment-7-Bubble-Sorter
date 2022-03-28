#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool whileLoopV(vector<int> list) {
	for (int i = list.size() - 1; i > 0; i--) {
		if (list[i - 1] > list[i]) {
			return true;
		}
	}
	return false;
}

void outputV(string num, vector<int> list) {
	int& a = list.at(0);
	cout << "List " << num << " unsorted: ";
	cout << "(" << a << ", ";
	for (int i = 1; i < list.size() - 1; i++) {
		int& b = list.at(i);
		cout << b << ", ";
	}
	int& c = list.at(list.size() - 1);
	cout << c << ")" << endl;

	int opNum = 0;

	while (whileLoopV(list)) {
		for (int i = 0; i < list.size() - 1; i++) {
			for (int j = 0; j < (list.size() - 1) - i; j++) {
				int var1 = list[j];
				int var2 = list[j + 1];

				if (var1 > var2) {
					list[j] = var2;
					list[j + 1] = var1;

					opNum += 3;
				}
				else if (var1 < var2) {
					opNum += 1;
				}
			}
		}
	}

	int& x = list.at(0);
	cout << "List " << num << "   sorted: ";
	cout << "(" << x << ", ";
	for (int i = 1; i < list.size() - 1; i++) {
		int& y = list.at(i);
		cout << y << ", ";
	}
	int& z = list.at(list.size() - 1);
	cout << z << ")" << endl;
	cout << opNum << " actions performed" << "\n\n";
}

int main() {
	vector<int> l1 = { 1, 3, 7, 5, 2, 4, 6, 8, 9, 10 };
	vector<int> l2 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	vector<int> l3 = { 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };

	outputV("1", l1);
	outputV("2", l2);
	outputV("3", l3);

	string z = "Y";
	vector<int> funsies;
	while (z == "Y" || z == "y") {
		cout << "give me a list of numbers:" << "\n";
		for (int i = 1; true; i++) {
			cout << i << ": ";
			cin >> z;
			if (z == "stop") {
				break;
			}
			else {
				funsies.push_back(stoi(z));
			}
		}

		if (funsies.empty()) {}
		else {
			cout << endl;
			outputV("?", funsies);
			funsies.clear();
			cout << "want to go again (Y/N)? ";
			cin >> z;
			cout << "\n";
		}
	}
}