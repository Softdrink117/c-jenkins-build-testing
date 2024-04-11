#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window *w;
SDL_Surface *surf;

int _init()
{
    if(SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        w = SDL_CreateWindow("Jenkins SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
        if(w)
        {
            surf = SDL_GetWindowSurface(w);
        } 
        else
            return 0;
    }
    else
        return 0;

    return 1;
}

void _dispose()
{
    if(surf)
        SDL_FreeSurface(surf);
    surf = NULL;
    if(w)
        SDL_DestroyWindow(w);
    w = NULL;
    SDL_Quit();
}

int f_count = 0;
void loop()
{
    while(f_count < 10)
    {
        // This is just a dummy fn to validate that it compiled successfully
        printf("Hello World with SDL!\n");
        f_count++;
    }
}

int main()
{
    if(!_init)
    {
        _dispose();
        return -1;
    }

    loop();    
    
    // printf("Hello World!\n");
    _dispose();
    return 0;
}