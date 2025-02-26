//#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char* argv[]) {
//	SDL_Init(SDL_INIT_VIDEO);
//
//	SDL_Window* window = nullptr;
//	SDL_Renderer* render = nullptr;
//
//	window = SDL_CreateWindow("Drag Cube", 800, 700, 0);
//
//	render = SDL_CreateRenderer(window, 0);
//
//	SDL_Event event;
//
//	SDL_FRect rect;
//	rect.w = 100;
//	rect.h = 100;
//	rect.x = 0;
//	rect.y = 0;
//
//
//	bool running = true;
//	while (running) {
//		while (SDL_PollEvent(&event)) {
//			switch (event.type) {
//				//case SDL_EVENT_MOUSE_BUTTON_DOWN:
//				//	cout << "Mouse presed " << endl;
//				//	rect.x = event.motion.x;
//				//	rect.y = event.motion.y;
//
//			case SDL_EVENT_MOUSE_MOTION:
//				cout << "Mouse motion: " << event.motion.x << event.motion.y << endl;
//				rect.x = event.motion.x;
//				rect.y = event.motion.y;
//			}
//		}
//		SDL_SetRenderDrawColor(render, 155, 55, 25, 1);
//		SDL_RenderClear(render);
//
//		SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
//		SDL_RenderFillRect(render, &rect);
//
//		SDL_RenderPresent(render);
//		SDL_Delay(16);
//	}
//
//	SDL_DestroyWindow(window);
//	SDL_DestroyRenderer(render);
//	SDL_Quit();
//
//	return 1;
//}