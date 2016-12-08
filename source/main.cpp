#include <sf2d.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

#include "game_entity.hpp"
#include "Vector2d.h"
#include "Square.hpp"
#include "screen.hpp"

u32 kDownOld = 0, kHeldOld = 0, kUpOld = 0;
u32 kDown = 0, kHeld = 0, kUp = 0;

int main()
{

    sf2d_init();
    sf2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0x00));

    auto screen = new Screen();

    while (aptMainLoop()) {

      //check for key input
      hidScanInput();
       kDown = hidKeysDown();
       kHeld = hidKeysHeld();
       kUp = hidKeysUp();
      //terminates when start is pressed
      if(kDown & KEY_START){
	break;
      }
      // draws the next frame 
      sf2d_start_frame(GFX_TOP, GFX_LEFT);
      sf2d_draw_fill_circle(100, 100, 50
      			    , RGBA8(0xAA, 0x00, 0xFF, 0xFF));
      screen->draw();
      sf2d_end_frame();

      sf2d_swapbuffers();
      //reset keys
      kDownOld = kDown;
      kHeldOld = kHeld;
      kUpOld = kUp;// Flush and swap framebuffers
    }
    //terminates the sf2d stuff
     sf2d_fini();
    return 0;
}

