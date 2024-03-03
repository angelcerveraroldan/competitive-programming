/*
 * Title: IQ Test
 * Rating: 1300
 * Code: 25/A
 * URI: https://codeforces.com/problemset/problem/25/A
 **/

#include <iostream>

#define EVEN 0
#define ODD 1

using namespace std;

void find(int n, int f)
{	
	int tmp;
	for (int i = 3; i <= n; i ++)
	{
		cin >> tmp;
		if (tmp % 2 == f)
		{
			cout << i << "\n"; 
			break;
		}
	}
}

int main()
{
	int arr_size;
	cin >> arr_size;
	
	int first, second;
	cin >> first >> second;
	
	bool f_even = first  % 2 == 0;
	bool s_even = second % 2 == 0; 
	
	if (f_even && s_even)           find(arr_size, ODD);
	else if ( !(f_even || s_even) ) find(arr_size, EVEN);
	else 
	{
		int third; 
		cin >> third;

		if (third % 2 == 0)
			f_even ? cout << "2\n" : cout << "1\n";
		else 
			f_even ? cout << "1\n" : cout << "2\n";
	}

}
