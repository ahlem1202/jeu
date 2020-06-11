#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL.h>
#include"test.h"

void perso_Init(Personnage *p){

	p->image = IMG_Load("1.png");
	p->image2 = IMG_Load("1.gif");
	p->position.x = 50;
	p->position.y = 500;//SCREEN_H - p->image[0]->h;
	//p->vx = 0; 
	p->direction=-1;
	//p->vitesse=5;
	p->velocity=2;
        p->acceleration=0;
        p->moving=0;
       // p->Mass=70;
	
	/*p>position.w=p->image[0]->w;
	p->position.h=p->image[0]->h;*/
	

	for (int i = 0; i < 5; i++ ){
		p->clips[i].x = i*250;
		p->clips[i].y = 0;
		p->clips[i].w = 250;
		p->clips[i].h = 250;
	}
	 for (int i = 0; i < 5; i++ ){
		p->clips2[i].x = 1536 -(i + 1) * 250;
		p->clips2[i].y = 0;
		p->clips2[i].w = 250;
		p->clips2[i].h = 250;
	}
	p->frame = 0;
 }
void deplacer_perso(Personnage *p,SDL_Rect *camera,Uint32 dt )
{ 

  
    p->vitesse+=p->acceleration*dt;
    p->position.x+=0.5*p->acceleration*dt*dt+p->vitesse*dt;

  if(p->position.x>950)
    {
      p->position.x-=0.5*p->acceleration*dt*dt+p->vitesse*dt;
      camera->x+=0.5*p->acceleration*dt*dt+p->vitesse*dt;

     }




   
 }


/*void blitBackground(SDL_Surface *Backg,SDL_Surface **screen,SDL_Rect position_Backg)
{ position_Backg.x=0;
  position_Backg.y=0;
   
SDL_BlitSurface(Backg,NULL,screen,&position_Backg);

  }*/


 void perso_Render(Personnage *p, SDL_Surface **screen){
   if(p->direction==-1||p->direction==1)
   	//SDL_BlitSurface(p->image,&p->clips[0],*screen,&p->positionPerso);*/
	/*if(p->direction==1){*/
		SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&p->position);
	 // }
         else//(p->direction==0)
	       // SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&p->positionPerso);
		{SDL_BlitSurface(p->image2,&p->clips2[(int) p->frame],*screen,&p->position);}

	         

	p->frame += 0.15;
	if(p->frame > 5) {
		 p->frame = 1;
		//p->vx *= 1;
	}
	//p->positionPerso.x += p->vx;
		
}
/*
int loadVoitureImages (Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/voiture";
	char bmp[]=".bmp";
	for(i=0; i<4; i++)
        {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) 
                {
			printf("Unable to load  Voiture bitmap: %s\n", SDL_GetError());
			return (-1);
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}
*/





















