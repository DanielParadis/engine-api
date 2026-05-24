#ifndef MOUSE_H
#define MOUSE_H
// Mouse button mapping taken in reference to SDL_mouse.h
// They were hardcoded defined but I've converted them to an enum

typedef enum MouseButton {
  BUTTON_UNKNOWN,
  BUTTON_LEFT,
  BUTTON_MIDDLE,
  BUTTON_RIGHT,
  BUTTON_X1,
  BUTTON_X2,
  BUTTON_MAX
} MouseButton;

typedef struct MouseState {
  float x, y;
  int state[BUTTON_MAX];
  int pressed[BUTTON_MAX];
  int released[BUTTON_MAX];
} MouseState;

#endif