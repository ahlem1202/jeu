#ifndef TEST_H_
#define TEST_H_

typedef struct
{ 
   float velocity,vitesse;//vitesse
   int moving,direction;//etat
   float   acceleration;
    SDL_Rect position ;
   SDL_Surface *image,*image2;//,image[6];
   SDL_Rect clips[6],clips2[6];
float frame;
}Personnage;


void perso_Init(Personnage *p);
void deplacer_perso(Personnage *p,SDL_Rect *camera,Uint32 dt);
//void blitBackground(SDL_Surface *Backg,SDL_Surface **screen,SDL_Rect position_Backg);
 void perso_Render(Personnage *p, SDL_Surface **screen);


#endif
