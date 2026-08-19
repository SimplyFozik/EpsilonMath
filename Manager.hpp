#pragma once
#include <iostream>
#include <future>
#include <vector>

class Manager {
private:
public:

	Manager() {
		std::cout << LeibnizAsyncManager(1'000'000'000, 16);
	}

	long double Leibniz(long long first_iteration, long long last_iteration);
	long double LeibnizAsyncManager(long long iterations, int threads);
};