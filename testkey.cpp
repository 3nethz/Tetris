#include <SDL.h>
#include <iostream>

class IO {
public:
    int pollKey();
};

int IO::pollKey() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_x:
                    return 1;
                case SDLK_z:
                    return 2;
                case SDLK_LEFT:
                    return 3;
                case SDLK_RIGHT:
                    return 4;
                case SDLK_DOWN:
                    return 5;
            }
        }
    }
    return 0;
}

void gameLoop(IO& io) {
    bool running = true;

    while (running) {
        int key = io.pollKey();

        if (key != 0) {
            switch (key) {
                case 1:
                    std::cout << "X key pressed!" << std::endl;
                    break;
                case 2:
                    std::cout << "Z key pressed!" << std::endl;
                    break;
                case 3:
                    std::cout << "Left arrow key pressed!" << std::endl;
                    break;
                case 4:
                    std::cout << "Right arrow key pressed!" << std::endl;
                    break;
                case 5:
                    std::cout << "Down arrow key pressed!" << std::endl;
                    break;
            }
        }

        // Check for quit event (optional, to exit the loop)
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_Delay(16); // Delay to control the loop speed (~60 FPS)
    }
}

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window (needed for SDL event handling)
    SDL_Window* window = SDL_CreateWindow("Poll Key Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    IO io;
    gameLoop(io);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
