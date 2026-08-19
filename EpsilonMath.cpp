#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include "MathFunctions.hpp"

int main()
{
	auto start = std::chrono::steady_clock::now();
	double pi = LeibnizAsyncManager(1'000'000'000, 4);
	auto end = std::chrono::steady_clock::now();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Time: " << ms << " ms, Pi = " << std::setprecision(18) << pi << std::endl;
}