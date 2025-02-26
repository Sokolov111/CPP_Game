#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	// Создать класс окна 
	SDL_Window* window = nullptr ;

	// Создать рендер для передвижения
	SDL_Renderer* renderer = nullptr;

	// Создать окно
	window = SDL_CreateWindow("Game SDL", 800, 600, 0);

	// Поместить окно в рендер для передвижения.
	renderer = SDL_CreateRenderer(window, /*SDL_RENDERER_ACCELERATED*/ 0);
	

	
	SDL_Event event; // Работа с обработчиком событий


	
	bool running = true;
	while (running) {

		
		while (SDL_PollEvent(&event)) { // Отслеживание нажатий

			switch (event.type) // Считывание действий
			{
			case SDL_EVENT_QUIT: // При нажатии на крестик
				running = false; // Закрыть окно
				break;

			case SDL_EVENT_KEY_DOWN: // Нажатие клавиши

				/*
				scancode - считывает клавиши вне зависимости от раскладки
				sym - есть различие в раскладке - можно с одной кнопки считать символ ru/en.
				*/
				switch (event.key.scancode) { // Привязаться к нажатию опред. клавиши.
				case SDL_SCANCODE_A: // При нажатии на кнопку A.
					cout << "Pressed Key A" << endl;
					break;

				case SDL_SCANCODE_W:
					cout << "Pressed Key W" << endl;
					break;

				case SDL_SCANCODE_S:
					cout << "Pressed Key S" << endl;
					break;

				case SDL_SCANCODE_D:
					cout << "Pressed Key D" << endl;
					break;
				}
				
				//cout << "Pressed" << endl;
			
			case SDL_EVENT_KEY_UP: // Отпустить кдавишу
				cout << "Released" << endl;

			default:
				break;

			}
		}
		// Цвет фона.
		SDL_SetRenderDrawColor(renderer, 155, 55, 25, 1 );
		SDL_RenderClear(renderer);

		// Вывести обьект
		SDL_FRect rect;
		rect.w = 100;
		rect.h = 100;
		rect.x = 0;
		rect.y = 0;

		// Цвет квадрата
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
		// Вывести обьект на экран.
		SDL_RenderFillRect(renderer, &rect);

		// Вывести в приложение
		SDL_RenderPresent(renderer);

		// задержка между отрисовками.
		SDL_Delay(16);
	}
	
	
	SDL_DestroyWindow(window); // Удалить окно
	SDL_DestroyRenderer(renderer); // Удалить рендер и очистить память
	SDL_Quit(); // Закрыть класс SDL

	return 1;
}
