#include "BoardGenerator.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <functional>
#include <algorithm>


std::vector<std::vector<char>> generate_board(size_t size_x, size_t size_y) {
	std::vector<std::vector<char>> board(size_x, std::vector<char>(size_y, 0));
	const size_t nloop(size_x);
	const size_t nthreads = std::thread::hardware_concurrency();
	{
		//std::cout << "parallel (" << nthreads << " threads)" << std::endl;
		std::vector<std::thread> threads(nthreads);
		std::mutex critical;
		for (size_t t = 0; t < nthreads; t++)
		{
			threads[t] = std::thread(std::bind(
				[&](const int bi, const int ei, const int t)
				{
					srand(t);
					for (size_t i = bi; i < ei; i++)
					{
						for (size_t j = 0; j < size_y; j++)
						{
							std::lock_guard<std::mutex> lock(critical);
							board[i][j] = static_cast<char>((rand() % 26) + 'a');
						}
					}
				}, t * nloop / nthreads, (t + 1) == nthreads ? nloop : (t + 1) * nloop / nthreads, t));
		}
		std::for_each(threads.begin(), threads.end(), [](std::thread& x) {x.join(); });
		std::cout << std::endl;
	}
	return board;
}
