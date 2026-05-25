#ifndef VEC2_H
#define VEC2_H
#include <math.h>

typedef struct Vec2 {
  float x, y;
} Vec2;

static inline void v2Adds(Vec2 *restrict a, const Vec2 *restrict b) {
  a->x += b->x;
  a->y += b->y;
}

static inline void v2Addb(Vec2 *restrict result, const Vec2 *restrict a,
            const Vec2 *restrict b) {
  result->x = a->x + b->x;
  result->y = a->y + b->y;
}

static inline void v2Subs(Vec2 *restrict a, const Vec2 *restrict b) {
  a->x -= b->x;
  a->y -= b->y;
}

static inline void v2Subb(Vec2 *restrict result, const Vec2 *restrict a,
            const Vec2 *restrict b) {
  result->x = a->x - b->x;
  result->y = a->y - b->y;
}

static inline void v2Muls(Vec2 *restrict a, const Vec2 *restrict b) {
  a->x *= b->x;
  a->y *= b->y;
}

static inline void v2Mulb(Vec2 *restrict result, const Vec2 *restrict a,
            const Vec2 *restrict b) {
  result->x = a->x * b->x;
  result->y = a->y * b->y;
}

static inline void v2Divs(Vec2 *restrict a, const Vec2 *restrict b) {
  a->x /= b->x;
  a->y /= b->y;
}

static inline void v2Divb(Vec2 *restrict result, const Vec2 *restrict a,
            const Vec2 *restrict b) {
  result->x = a->x / b->x;
  result->y = a->y / b->y;
}

static inline float v2Dot(const Vec2 *restrict a, const Vec2 *restrict b) {
  return a->x * b->x + a->y * b->y;
}

static inline float v2Dist2(const Vec2 *restrict a, const Vec2 *restrict b) {
  return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

static inline float v2Dist(const Vec2 *restrict a, const Vec2 *restrict b) {
  return sqrtf(v2Dist2(a,b));
}

static inline float v2Mag2(const Vec2 *restrict a){
    return a->x*a->x + a->y*a->y;
}

static inline float v2Mag(const Vec2 *restrict a){
    return sqrtf(v2Mag2(a));
}

static inline void v2Norms(Vec2 *restrict a){
    float m = 1.0f/v2Mag(a);
    a->x *= m;
    a->y *= m;
}

static inline void v2Normb(Vec2 *restrict result, const Vec2 *restrict a){
    float m = 1.0f/v2Mag(a);
    result->x = a->x*m;
    result->y = a->y*m;
}

static inline void v2Scales(Vec2 *restrict a, float s){
    a->x *= s;
    a->y *= s;
}

static inline void v2Scaleb(Vec2 *restrict result, const Vec2 *restrict a, float s) {
    result->x = a->x*s;
    result->y = a->y*s;
}

static inline void v2Zeros(Vec2 *restrict a){
    a->x = 0;
    a->y = 0;
}

#endif