#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	// Создать класс окна 
	SDL_Window* window = nullptr;

	// Создать рендер для передвижения
	SDL_Renderer* renderer = nullptr;

	// Создать окно
	window = SDL_CreateWindow("Game SDL", 800, 600, 0);

	// Поместить окно в рендер для передвижения.
	renderer = SDL_CreateRenderer(window, /*SDL_RENDERER_ACCELERATED*/ 0);

	SDL_Event event; // Работа с обработчиком событий

	// Вывести обьект
	SDL_FRect rect;
	rect.w = 100;
	rect.h = 100;
	rect.x = 0;
	rect.y = 0;




	bool running = true;
	while (running) {
		while (SDL_PollEvent(&event)) { // Отслеживание нажатий
			//switch (event.type) // Считывание действий
			//{
			//case SDL_EVENT_QUIT: // При нажатии на крестик
			//	running = false; // Закрыть окно
			//	break;

			//case SDL_EVENT_KEY_DOWN: // Нажатие клавиши

			//	/*
			//	scancode - считывает клавиши вне зависимости от раскладки
			//	sym - есть различие в раскладке - можно с одной кнопки считать символ ru/en.
			//	*/
			//	switch (event.key.scancode) { // Привязаться к нажатию опред. клавиши.
			//	case SDL_SCANCODE_A: // При нажатии на кнопку A.
			//		cout << "Pressed Key A" << endl;
			//		rect.x -= 10;
			//		break;

			//	case SDL_SCANCODE_W:
			//		cout << "Pressed Key W" << endl;
			//		rect.y -= 10;
			//		
			//		break;

			//	case SDL_SCANCODE_S:
			//		cout << "Pressed Key S" << endl;
			//		rect.y += 10;
			//		break;

			//	case SDL_SCANCODE_D:
			//		cout << "Pressed Key D" << endl;
			//		rect.x += 10;
			//		break;
			//	}

			//case SDL_EVENT_KEY_UP: // Отпустить клавишу
			//	cout << "Released" << endl;

			//case SDL_EVENT_MOUSE_BUTTON_DOWN: // Нажать кнопку мыши

			//	switch (event.button.button) { // Считать какая клавиша мыши была нажата.
			//	case SDL_BUTTON_LEFT:
			//		cout << "Pressed left button" << endl;
			//		break;
			//	case SDL_BUTTON_RIGHT:
			//		cout << "Pressed right button" << endl;
			//		break;
			//	}

			//	cout << "Pressed mouse" << endl;
			//	break;

			//case SDL_EVENT_MOUSE_BUTTON_UP: // Отпустить кнопку мыши
			//	cout << "Released mouse" << endl;
			//	break;

			//case SDL_EVENT_MOUSE_MOTION:
			//	cout << "Mouse position: " << event.motion.x << event.motion.y << endl;
			//	break;
			//default:
			//	break;

			//}
		}
		// Цвет фона.
		SDL_SetRenderDrawColor(renderer, 155, 55, 25, 1);
		SDL_RenderClear(renderer);

		const bool* state = SDL_GetKeyboardState(NULL); // Второй способ считать нажатия клавиш
		if (state[SDL_SCANCODE_W]) { // Этот способ лучше, т.к двигает сразу без остановки обьект.
			rect.y -= 10;
		}
		else if (state[SDL_SCANCODE_S]) {
			rect.y += 10;
		}
		else if (state[SDL_SCANCODE_A]) {
			rect.x -= 10;
		}
		else if (state[SDL_SCANCODE_D]) {
			rect.x += 10;
		}

		

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
