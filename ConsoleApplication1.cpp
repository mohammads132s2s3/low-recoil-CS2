#include <windows.h>
#include <iostream>
#include <thread>

void noRecoil() {
	while (true) {
		if (GetAsyncKeyState(VK_LBUTTON)) {
			INPUT input = { 0 };
			input.type = INPUT_MOUSE;
			input.mi.dx = 0;
			input.mi.dy = 8;
			input.mi.dwFlags = MOUSEEVENTF_MOVE;
			SendInput(1, &input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
int main() {
	std::cout << "No Recoil Activated!" << std::endl;
	std::thread(noRecoil).detach();
	while (true) Sleep(1000);
}