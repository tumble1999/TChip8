#include <chrono>
#include <iostream>

#include "platform.h"

#include "screen_size.h"
#include "chip8.h"

int main(int argc, char* args[]) {
	std::cout << "Starting TEmu Chip8 Emulator" << std::endl;

	if (argc == 0)
	{
		std::cerr << "Usage: " << args[0] << " <ROM>\n";
		std::exit(EXIT_FAILURE);
	}


	int delay = 1;
	int scale = 10;

	Platform platform("TChip8", VIDEO_WIDTH, VIDEO_HEIGHT,scale);
	Chip8 chip8;
	const char* ROM = args[1];
	chip8.loadGame(ROM);

	int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;
	auto lastCycleTime = std::chrono::high_resolution_clock::now();
	bool quit = false;

	while (!quit)
	{
		quit = platform.input(chip8.key);

		auto currentTime = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(currentTime - lastCycleTime).count();

		if (dt > delay)
		{
			lastCycleTime = currentTime;
			chip8.update();
			platform.update(chip8.video, videoPitch);
		}
	}
	system("pause");
	return 0;
}
