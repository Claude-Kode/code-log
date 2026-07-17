#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "duipai START !!! \n";
	
	for (int T = 1; T <= 10; T++) {
		system("generator.exe > in.txt");
		

		double mb = clock();
		system("..\\2222C.exe < in.txt > my.out");
		double me = clock();
		double tim = double(me - mb) / CLOCKS_PER_SEC;
		
		system("brute.exe < in.txt > std.out");
		
		if (tim > 2.0) {
			ifstream in("in.txt"), my("my.out"), std("std.out");
			cout << "TLE on testcase " << T << " || " << " time: " << tim << "s\n"; 
			cout << "TEST INFOR : \n" << string(istreambuf_iterator<char>(in), {}) << endl;
			cout << "MY OUTPUT:\n" << string(istreambuf_iterator<char>(my), {}) << endl;
			cout << "STD OUTPUT:\n" << string(istreambuf_iterator<char>(std), {}) << endl;
			cout << endl << endl; 
			continue; 
		} else if (system("fc my.out std.out > nul")) {
			ifstream in("in.txt"), my("my.out"), std("std.out");
			cout << "WA on testcase: " << T << " || " << " time: " << tim << "s\n"; 
			cout << "TEST INFOR : \n" << string(istreambuf_iterator<char>(in), {}) << endl;
			cout << "MY OUTPUT:\n" << string(istreambuf_iterator<char>(my), {}) << endl;
			cout << "STD OUTPUT:\n" << string(istreambuf_iterator<char>(std), {}) << endl;
			cout << endl << endl; 
			continue; 
		}
		
		cout << "AC on testcase " << T << endl;
	}
	cout << "Done\n";
	int n; cin >> n;
	return 0;
}