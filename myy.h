/*
  Copyright (c) 2016 Miouyouyou <Myy>

  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files 
  (the "Software"), to deal in the Software without restriction, 
  including without limitation the rights to use, copy, modify, merge, 
  publish, distribute, sublicense, and/or sell copies of the Software, 
  and to permit persons to whom the Software is furnished to do so, 
  subject to the following conditions:

  The above copyright notice and this permission notice shall be 
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef MYY_INCLUDED
#define MYY_INCLUDED 1

#include <stdint.h>
#include <myy/helpers/fonts/packed_fonts_display.h>
#include <myy/helpers/hitbox_action.h>

struct myy_common_data {
	struct glyph_infos * __restrict fonts_glyphs;
	hitboxes_S_t * hitboxes;
};

struct myy_game_state {
  unsigned int saved;
  unsigned int size;
  uint8_t state[228];
};

struct myy_platform_handlers {
	void (*stop)();
	void * stop_data;
};

struct myy_platform_handlers * myy_get_platform_handlers();
void myy_display_initialised(unsigned int width, unsigned int height);
void myy_init();
void myy_init_drawing();
void myy_draw();
void myy_cleanup_drawing();
void myy_stop();
/* User quit is a "Quit" action performed by the user, using the program
 * UI. This is different from closing the window abruptly. */
void myy_user_quit();

void myy_generate_new_state();
void myy_save_state(struct myy_game_state *state);
void myy_resume_state(struct myy_game_state *state);

void myy_click(int x, int y, unsigned int button);
void myy_doubleclick(int x, int y, unsigned int button);
void myy_hover(int x, int y);
void myy_move(int x, int y, int start_x, int start_y);
void myy_key(unsigned int keycode);
void myy_key_release(unsigned int keycode);
void myy_after_draw();

/* Temporary changes */
enum mouse_action_type { myy_mouse_wheel_action };

void myy_rel_mouse_move(int x, int y);
void myy_mouse_action(enum mouse_action_type, int value);

#endif 
