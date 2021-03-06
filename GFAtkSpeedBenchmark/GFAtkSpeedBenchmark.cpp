// GFAtkSpeedBenchmark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dependencies.h"

void screenshot(HWND);
std::chrono::time_point<std::chrono::steady_clock> done(HDC, HDC, HDC, HDC, HWND);
std::chrono::time_point<std::chrono::steady_clock> CaptureAnImage(HWND);

int main()
{
	bool x = false;
	while (!x) {
		if (GetKeyState(VK_CONTROL) && GetKeyState(VK_OEM_MINUS))
		{
			HWND activeWindow = GetDesktopWindow();
			std::thread worker(screenshot, activeWindow);
			worker.join();
			x = true;
		}
	}
}

void screenshot(HWND activeWindow) {
	using namespace std::literals::chrono_literals;

	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(1e+10ns);
	std::chrono::time_point<std::chrono::steady_clock> end = CaptureAnImage(activeWindow);

	std::chrono::duration<float> duration = end - start;
	LOG(duration.count());
}
