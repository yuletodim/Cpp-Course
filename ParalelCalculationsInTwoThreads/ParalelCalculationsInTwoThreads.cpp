#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <thread>
#include <mutex>
#include <limits>
#include <Windows.h>		// Only for Windows
// Beacause the program is to fast I will put a Sleep just to show the work ofthe 2 thraeds together

std::mutex globalMutex;

bool checkIfIsPrimeNumber(int num)
{
	bool isPrime = true;
	if (num != 1)
	{
		int limes = sqrt(num);
		for (int i = 2; i <= limes; ++i)
		{
			if (num % i == 0)
			{
				isPrime = false;
				break;
			}
		}
	}

	return isPrime;
}

// Method that calculates prime numbers
void printPrimeNumbers()
{
	unsigned long long  i = 1;
	unsigned long long startFindingNextPrimeNumber = clock();
	unsigned long long endFindingNextPrimeNumber;
	while (true)
	{
		if (checkIfIsPrimeNumber(i))
		{
			// Sleep thraed for 400 milisecs -> just to show the paralel work of the 2 threads
			Sleep(400);
			endFindingNextPrimeNumber = clock();

			// Calculate time in milisconds
			float timeForFindingPrimeNumber =
				(float)(1000 * (endFindingNextPrimeNumber - startFindingNextPrimeNumber) / CLOCKS_PER_SEC);

			// Lock shared resource -> console
			globalMutex.lock();

			// Use shared resource
			std::cout << "Prime " << i << " " << timeForFindingPrimeNumber << "ms" << std::endl;

			// Unlock it
			globalMutex.unlock();

			startFindingNextPrimeNumber = clock();
		}

		i++;

		// Check if number goes out of range -> bigger than unsigned long long
		if (i > ULLONG_MAX || i <= 0)
		{
			std::cout << "Error: Prime Number out of range." << std::endl;
			break;
		}
	}
}

// Method that calculates Fibonacci
void printFibonacciNumbers()
{
	unsigned long long prev = 1;
	unsigned long long prev_2 = 1;
	unsigned long long startFindingNextFibonacci = clock();
	unsigned long long fibonacciNum, endFindingNextFibonacci;

	while (true)
	{
		fibonacciNum = prev + prev_2;

		// Sleep thraed for 800 milisecs -> just to show the paralel work of the 2 threads
		Sleep(800);
		endFindingNextFibonacci = clock();

		// Check if number goes out of range -> bigger than unsigned long long
		if (fibonacciNum < prev)
		{
			std::cout << "Error: Fibonacci Number out of range." << std::endl;
			break;
		}

		// Calculate time in milisconds
		float timeForFindingFibonacci =
			(float)(1000 * (endFindingNextFibonacci - startFindingNextFibonacci) / CLOCKS_PER_SEC);

		// Lock shared resource -> console
		globalMutex.lock();

		// Use shared resource
		std::cout << "Fibonacci  " << fibonacciNum << " " << timeForFindingFibonacci << "ms" << std::endl;

		// Unlock it
		globalMutex.unlock();

		startFindingNextFibonacci = clock();
		// Swap previouse elements
		prev_2 = prev;
		prev = fibonacciNum;
	}
}

int main()
{
	// Spawn a new thread for calculation of prime numbers
	std::thread calculatePrimeNumbersThread(printPrimeNumbers);

	// Spawn a new thread for calculation of Fibonacci numbers
	std::thread calculateFibonacciNumbersThread(printFibonacciNumbers);

	// Syncronize threads with the main thread
	calculatePrimeNumbersThread.join();
	calculateFibonacciNumbersThread.join();

	return 0;
}