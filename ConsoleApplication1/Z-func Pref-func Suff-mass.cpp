#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> prefix_function(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 0; i < n; ++i) {// n = 12
		for (int k = 0; k <= i; ++k) {
			string aa = s.substr(0, k);
			string bb = s.substr(i - k + 1, k);
			if (aa == bb)
				pi[i] = k;


		}
		///cout << pi[i] << " ";
	}
	//cout << endl;
	return pi;						
}

vector<int> z_function_trivial(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1; i < n; ++i)
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
	return z;
}






int main()
{
	vector<int> a = z_function_trivial("aaabbbabacd");
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	vector<int> b = prefix_function("abracadabra");
	for (size_t i = 0; i < b.size(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;


	string s = "abracadabra";
	int n = s.length();
	map<string, int> Map;
	int* suffix = new int[n];

	// Maping string with its index of
	// it's last letter.
	string sub = "";
	for (int i = n - 1; i >= 0; i--) {
		sub = s[i] + sub;
		Map[sub] = i;
	}

	// Storing all values of map
	// in suffix array.
	int j = 0;
	for (auto x : Map) {
		suffix[j] = x.second;
		j++;
	}

	// printing suffix array.
	cout << "Suffix array for banana is" << endl;
	for (int i = 0; i < n; i++) {
		cout << suffix[i] << " ";
	}
	cout << endl;
}

