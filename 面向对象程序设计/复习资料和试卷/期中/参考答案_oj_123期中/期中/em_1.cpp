#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		if (a == "Monday") {
			cout << 1 << endl;
		}
		else if (a == "Tuesday") {
			cout << 2 << endl;
		}
		else if (a == "Wednesday") {
			cout << 3 << endl;
		}
		else if (a == "Thursday") {
			cout << 4 << endl;
		}
		else if (a == "Friday") {
			cout << 5 << endl;
		}
		else if (a == "Saturday") {
			cout << 6 << endl;
		}
		else if (a == "Sunday") {
			cout << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}