#ifndef ENGINE_API_H
#define ENGINE_API_H
#ifdef _WIN32
#define GAME_EXPORT __declspec(dllexport)
#else
#define GAME_EXPORT __attribute__((visibility("default")))
#endif
#include "keyboard.h"
#include "mouse.h"
#include "vec3.h"
#include <stdarg.h>

typedef void (*EngineLogFunc)(const char *fmt, va_list ap);

#ifndef MAX_ENTITIES
#define MAX_ENTITIES 8192
#endif

typedef struct Engine Engine;

typedef struct EngineAPI {
  Engine *const engine;
  Engine *game;
  int (*const reportEntityCount)(Engine *, int);
  EngineLogFunc log;
  const struct {
    struct {
      void (*width)(Engine *, int);
      void (*height)(Engine *, int);
      void (*title)(Engine *, const char *);
    } window;
  } set;
  const struct {
    struct {
      int (*state)(Engine *, Key_ScanCode);
      int (*pressed)(Engine *, Key_ScanCode);
      int (*released)(Engine *, Key_ScanCode);
    } key;
    struct {
      float (*x)(Engine *);
      float (*y)(Engine *);
      struct {
        int (*state)(Engine *, MouseButton);
        int (*pressed)(Engine *, MouseButton);
        int (*released)(Engine *, MouseButton);
      } button;
      const MouseState *(*state)(Engine *);
    } mouse;
  } input;
  const struct {
    int (*spawn)(Engine *);
    void (*kill)(Engine *, int);
    struct {
      int* (*type)(Engine*, int);
      Vec3* (*pos)(Engine *, int);
    }get;
  } entity;
  float (*const dt)(Engine *);
} EngineAPI;

#define GAME_LOG(ctx, fmt, ...)                                                \
  do {                                                                         \
    va_list args;                                                              \
    va_start(args, fmt);                                                       \
    (ctx)->log(fmt, args);                                                     \
    va_end(args);                                                              \
  } while (0)

#define GAME_ENTRY(X)                                                          \
  GAME_EXPORT int _ENGINE_INIT_GAME(EngineAPI *api) {                          \
    if (!api->reportEntityCount(api, MAX_ENTITIES))                            \
      return 0;                                                                \
    X(api);                                                                    \
    return 1;                                                                  \
  }

#endif