#ifndef _TCHIP8_PLATFORM_H_
#define _TCHIP8_PLATFORM_H_

#include <SDL2/SDL.h>

class Platform {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
public:
	Platform(const char* title, int width, int height, int textureScale);
	~Platform();
	bool input(uint8_t* keys);
	void update(const void* buffer, int pitch);

};

#endif // !_TCHIP8_PLATFORM_H_
