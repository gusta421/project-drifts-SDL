#define altura 700
#define largura 1000
#define ERRO -1

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <stdlib.h>
#include "struct.h" // estruturas usadas no jogo
#include "funcoes.h" // funções do jogo.

SDL_Surface *cursor;
SDL_Surface *screen;

int xpos= (largura/2),ypos=(altura/2);

void DrawIMG(SDL_Surface *img, int x, int y);
void DrawScene();

int main (int argc, char** argv){
	SDL_Event event;
	Uint32 cor_fundo;
	Uint8* keys;
	int quit = 0;
	SDL_Rect rect;
	OBJETO b1;

	b1.image = IMG_Load("blue.png");


	if (!b1.image)	
	{
		printf("Nao consegui carregar imagem b1.png\n");  		exit(ERRO);
	}	

	atexit(SDL_Quit);

	SDL_Init(SDL_INIT_EVERYTHING);

	if( -1 == SDL_Init(SDL_INIT_EVERYTHING)){
		printf("ERRO MALIGNO! %s/n", SDL_GetError());
		return 666;
	}

	screen = SDL_SetVideoMode(largura, altura, 16, 0);

	if(!screen){
		printf("ERRO MALIGNO DA SCREEN! %s/n", SDL_GetError());
		return 666;
	}

	cursor = IMG_Load("yellow.png");
  
  if(!cursor){
      printf("ERRO MALIGNO! %s\n", SDL_GetError());
      return 666;
  }

  SDL_ShowCursor(1);
	
	cor_fundo = SDL_MapRGB(screen->format, 100, 50, 180);
	
	srand(time(NULL));


	b1.px = 0; //destino do blit da superficie BMP (w, h sao ignorados)
	b1.py = offscreen;
	
	b1.incx = rand() %10; b1.incy = rand() %4;

	while(!quit){
		while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT) //fechou a janela(caixa alta no quit)?
			{
				quit = 1;
			}
		}

		SDL_FillRect(screen, NULL, cor_fundo);

		update_positions(&b1);
		rect.x = b1.px; rect.y = b1.py ; rect.w = rect.y;
		SDL_BlitSurface(b1.image,NULL,screen,&rect);
		keys = SDL_GetKeyState(NULL);
    	SDL_GetMouseState(&xpos, &ypos);
		
		DrawScene();
	
	}

	SDL_Quit();
	
	return 0;
}


void DrawIMG(SDL_Surface *img, int x, int y)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}

void DrawScene()
{
  //SDL_FillRect(screen,0,0);
  DrawIMG(cursor, xpos, ypos);
  SDL_Flip(screen);
}
