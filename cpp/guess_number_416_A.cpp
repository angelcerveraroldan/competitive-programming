

#include <iostream>
#include <string>

using namespace std;

int queries;

string ineq, answer_str;
bool answer; 
int number;

int min_yet = - 2000000000; 
int max_yet =   2000000000;

int main()
{
	cin >> queries;

	for (int q = 0; q < queries; q ++)
	{
		cin >> ineq >> number >> answer_str;
		(answer_str == "Y") ? answer = true : answer = false;

		if (ineq == ">")       answer ? min_yet = max(min_yet, number+1) : max_yet = min(max_yet, number);
		else if (ineq == ">=") answer ? min_yet = max(min_yet, number)   : max_yet = min(max_yet, number-1);
		else if (ineq == "<")  answer ? max_yet = min(max_yet, number-1) : min_yet = max(min_yet, number);
		else if (ineq == "<=") answer ? max_yet = min(max_yet, number)   : min_yet = max(min_yet, number+1);
		else                   cout << "ERROR\n";

		// cout << "(" << min_yet << ", " << max_yet << ")\n";
	}

	(min_yet <= max_yet) ? cout << min_yet << "\n" : cout << "Impossible\n";
}
