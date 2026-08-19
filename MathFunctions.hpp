#pragma once
#include <future>
#include <vector>

long double Leibniz(long long first_iteration, long long last_iteration) {
	switch (first_iteration)
	{
	case 0:
		first_iteration++;
		break;
	default:
		break;
	}
	long double pi = 0;
	for (long double i = first_iteration; i < last_iteration; i += 4) {
		pi += (1 / i);
		pi -= (1 / (i + 2));
	}
	return pi;
}

long double LeibnizAsyncManager(long long iterations, int threads) {
	long long chunk = iterations / threads;
	long long remaining_iterations = iterations % threads;
	long double pi = 0;

	std::vector<std::future<long double>> futures;

	for (int i = 0; i < threads; i++) {
		futures.push_back(std::async(std::launch::async, Leibniz, i * chunk, i * chunk + chunk));
	}

	for (int i = 0; i < threads; i++) {
		pi += futures[i].get();
	}

	return pi * 4;
}