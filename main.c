#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL.h>
#include"test.h"
int main(){


 SDL_Surface *screen=NULL,*Backg=NULL;

   SDL_Rect position_Backg;
      
   SDL_Rect camera;
         camera.x=0;
         camera.y=0;
        camera.w=1200;
        camera.h=800;
     position_Backg.x=0;
  position_Backg.y=0;
  
SDL_Init(SDL_INIT_VIDEO);

                if(SDL_Init(SDL_INIT_VIDEO)!=0)
                   {printf("Error: %s\n",SDL_GetError());}


     screen=SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
         
       SDL_WM_SetCaption("ma superbe fenetre SDL ", NULL);

SDL_Event event ;
Backg=IMG_Load("ground.jpg");
position_Backg.w=1200;
	position_Backg.h=800;
Personnage Perso;

perso_Init(&Perso);
 
Uint32 t_prev,dt=1;
int keysHeld[323]={0};
int done=1,i,FPS=60;//frame  par seconde
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
while(done)
{  
    t_prev=SDL_GetTicks();//get the number of milliseconde since the SDL library initialization
	
      if(Perso.velocity>0)
	{
		Perso.acceleration=-0.002;
		i+=1;
		Perso.moving=1;
	}
      if(Perso.velocity<0)
            {
		Perso.acceleration=0;
		Perso.velocity=0;
		Perso.moving=0;
	    }
	while(SDL_PollEvent(&event))
	{
	      switch(event.type)
		{ case SDL_QUIT:
			done=0;
			break;
	       case SDL_KEYDOWN:
		     keysHeld[event.key.keysym.sym]=1;
		    Perso.moving=1;
		         break;
	       case SDL_KEYUP:
                   keysHeld[event.key.keysym.sym]=0;
			Perso.acceleration-=0.001;
			 break;
		}
	    	     if (keysHeld[SDLK_ESCAPE])
			done=0;
		     
		     if (keysHeld[SDLK_SPACE])//accelerate
		     Perso.acceleration+=0.005;
		  
		 if (keysHeld[SDLK_RETURN])/*&& Perso.vitesse>0 )*///decelerate
		     
                 	{Perso.acceleration-=0.01;}
                          
		   }
		 	
		//appeler la fonction de deplacement
		deplacer_perso(&Perso,&camera,dt);
			   i=i%4;
		if(!Perso.moving)
			{i=0;}
		//blitBackground(&Backg,screen,position_Backg);
        
  		/* SDL_BlitSurface(Backg,&camera,screen,&position_Backg);*/
//Blit the bachground to the backbuffer
	if(position_Backg.x>Backg->w-1200)
		position_Backg.x=0;
	if(position_Backg.x<0)
		position_Backg.x=Backg->w-1200;
	SDL_BlitSurface(Backg, &position_Backg, screen,NULL); //scrolling horizontal
			 perso_Render(&Perso,&screen);
       Perso.velocity+=0.5*Perso.acceleration*dt;
	position_Backg.x+=Perso.velocity*dt;
		//SDL_BlitSurface(Perso.image[i],NULL,screen,&Perso.position);
		//SDL_BlitSurface(Perso.sprite,&Perso.image[(int) Perso.frame],screen,&Perso.position);
		
		//displayText(police,&txt,screen,Perso,Backg,dt);
		SDL_Flip(screen);
	dt=SDL_GetTicks()-t_prev;
		if(1000/FPS > dt)
                 
			SDL_Delay(1000/FPS - dt);
              }
                 
/*SDL_FreeSurface(Perso);
SDL_FreeSurface(Backg);*/
SDL_Quit(); 

return (0) ;
}
