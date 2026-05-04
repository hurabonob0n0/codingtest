#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int rec_fibo(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return rec_fibo(n - 1) + rec_fibo(n - 2);
}

int dyn_fibo(int n)
{
	int d[100];
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];
	return d[n];
}

int main()
{
	auto start = high_resolution_clock::now();
	cout << rec_fibo(40) << endl;
	auto stop = high_resolution_clock::now();
	auto elapsed = stop - start;
	cout << "Recursive Fibonacci(10) elapsed time: " << duration_cast<microseconds>(elapsed).count() << " microseconds" << endl;

	start = high_resolution_clock::now();
	cout << dyn_fibo(40) << endl;
	stop = high_resolution_clock::now();
	elapsed = stop - start;
	cout << "Dynamic Programming Fibonacci(10) elapsed time: " << duration_cast<microseconds>(elapsed).count() << " microseconds" << endl;
}