#include <iostream>
#include <stdint.h>

using namespace std;

int l;
void solve()
{
	cin >> l;
	long long int arr[l];
	for (int i = 0; i < l; i ++) cin >> arr[i];

	long long int sums[l+1];
	long long int sum = 0;
	for (int i = l-1; i >= 0; i --) 
	{
		sum += arr[i];
		sums[i] = sum;
	}
	sums[l] = 0;
	
	long long int ci = 1;
	long long int max_sum = arr[0];
	for (int i = 1; i < l; i ++)
	{
		// Check if it should be combined with the last one
		long long int A_succ_i = sums[i+1];
		int a_i = arr[i];
	
		// If this is the case, that means that we dont
		// want to join a_i with the last array, we want 
		// it to be in its own new array. Thus we will 
		// increament the index by one.
		if (-a_i <= A_succ_i) 
			ci++;
		
		// Add to the final sum the number times the number 
		// of times the index of the array its in
		max_sum += a_i * ci;
	}
	
	// SOURCE OF HALF AN HOUR OF DEBUGGING!!!!
	//
	// When printing a long long, you must use ll!
	//
	// Otherwise stack overflow will happen when printing
	printf("%lli\n", max_sum);
}

int tests;
int main()
{
	cin >> tests;
	for (int t = 0; t < tests; t++) solve();
}	

