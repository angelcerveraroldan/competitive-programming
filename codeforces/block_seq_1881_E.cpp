#include <iostream>
#include <vector>

using namespace std;

int len, tests;
int main()
{
	cin >> tests;
	for (int test = 0; test < tests; test ++)
	{
		cin >> len;
		int arr[len];

		for (int i = 0; i < len; i ++) cin >> arr[i];

		int payment[len+1];
		payment[len-1] = 1;
		payment[len] = 0;
		
		for (int i = len - 2; i >= 0; i--)
		{	
			int num = arr[i];
			if (i + num + 1 <= len) 
				payment[i] = min(payment[i+1] + 1, payment[i + num + 1]);
			else 	payment[i] = payment[i+1] + 1;
		}

		//for (int i = 0; i < len; i ++)
		//{
		//	cout << "(" << i << " " << payment[i] << ") "; 
		//}

		cout << payment[0] << "\n";
	}
}
