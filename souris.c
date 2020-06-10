#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include<SDL/SDL_mixer.h>


int main (void){
  
        SDL_Surface *ecran=NULL;
       SDL_Surface *Fond=NULL, *perso=NULL;
        SDL_Rect positionecran, positionFond,camera,positionPerso;
        positionecran.x=0;
        positionecran.y=0; 

	positionFond.x=0;//NULL
	positionFond.y=0;
	positionFond.w=640;//NULL
	positionFond.h=480;


	positionPerso.x=0;
	positionPerso.y=350;
        camera.x=0;
        camera.y=0;
        camera.w=640;
        camera.h=480;

SDL_Event event;
 
int continuer = 1,direction=-1;

  
     SDL_Init(SDL_INIT_VIDEO);

                if(SDL_Init(SDL_INIT_VIDEO)!=0)
                   {printf("Error: %s\n",SDL_GetError());}


      ecran=SDL_SetVideoMode(750,820,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
         
       SDL_WM_SetCaption("ma superbe fenetre SDL ", NULL);
       

     Fond=IMG_Load("ground.jpg");
     perso = IMG_Load("detective.png");
   //SDL_Rect positionPerso={ ecran->w/2 - perso->w/2, ecran->h/2 - perso->w/2, perso->w, perso->h};
  
     SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */
      


     while (continuer)
      {
          SDL_WaitEvent(&event); 
             switch(event.type) 
              {
                 case SDL_QUIT: 
                 continuer = 0;
                   break;
                 case SDL_MOUSEBUTTONUP:
		 if (event.button.button==SDL_BUTTON_RIGHT)
			{continuer=0;
			}
		
			positionPerso.x=event.button.x;
		  	positionPerso.y=event.button.y;	

                       break;
		/*case SDL_MOUSEMOTION:
			positionPerso.x=event.motion.x;
		  	positionPerso.y=event.motion.y;	
			break;	
                case SDL_KEYDOWN:
                     switch(event.key.keysym.sym)
                      { 
                           case SDLK_UP:
                              positionPerso.y--;
                               break;
                           case SDLK_DOWN: 
                              positionPerso.y++;
               		       break;
                           case SDLK_RIGHT: 
                               direction=1; 
                               //perso->direction=1;
	                      if(positionPerso.x< ecran->w/2)
					positionPerso.x++;
                              else   camera.x++;
                                   break;
                           case SDLK_LEFT: 
                               direction=0; positionPerso.x--;
		               //perso->direction=0;
                                if(positionPerso.x> ecran->w/2)
		                 camera.x--;
                                    break;
			   }
		 
                          break;*/
               }
   
       SDL_BlitSurface( Fond, NULL, ecran, NULL);
       SDL_BlitSurface(perso, NULL, ecran, &positionPerso);
   SDL_Flip(ecran);
 }

   SDL_FreeSurface(perso);
   SDL_Quit(); 

return EXIT_SUCCESS;
}
