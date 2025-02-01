#include <iostream>
#include <string>

using namespace std;

string swap_string (int n, string to_swap)
{
	int length = to_swap.length();
	char* start_shift = &to_swap[0] + (length - n);
	string shifted(length, '0');
	for (int i = 0; i < n; i++)
		shifted[i] = *(start_shift + i);

	for (int i = 0; i < (length - n); i++)
		shifted[i + n] = to_swap[i];

	return shifted;
}

int main ()
{
	int n;
	string input;
	cout << "Enter a String: ";
	cin >> input;

	cout << "Shift by: ";
	cin >> n;

	cout << "Shifted: " << swap_string(n, input) << endl;
}

