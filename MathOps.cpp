#include <future>
#include <vector>
#include "Manager.hpp"

long double Manager::Leibniz(long long first_iteration, long long last_iteration) {
	if (first_iteration == 0) { first_iteration++; }
	long double pi = 0;
	for (long double i = first_iteration; i < last_iteration; i += 4) {
		pi += (1 / i);
		pi -= (1 / (i + 2));
	}
	return pi;
}

long double Manager::LeibnizAsyncManager(long long iterations, int threads) {
	long long chunk = iterations / threads;
	long long remaining_iterations = iterations % threads;
	long double pi = 0;

	std::vector<std::future<long double>> futures;

	for (int i = 0; i < threads; i++) {
		long long start = i * chunk;
		long long end = start + chunk;
		if (i == threads - 1) { end += remaining_iterations; }
		futures.push_back(std::async(std::launch::async, &Manager::Leibniz, this, start, end));
	}

	for (int i = 0; i < threads; i++) {
		pi += futures[i].get();
	}

	return pi * 4;
}