#ifndef VEC3_H
#define VEC3_H
#include <math.h>

typedef struct Vec3 {
  float x, y, z;
} Vec3;

static inline void v3Adds(Vec3 *restrict a, const Vec3 *restrict b) {
  a->x += b->x;
  a->y += b->y;
  a->z += b->z;
}

static inline void v3Addb(Vec3 *restrict result, const Vec3 *restrict a,
            const Vec3 *restrict b) {
  result->x = a->x + b->x;
  result->y = a->y + b->y;
  result->z = a->z + b->z;
}

static inline void v3Subs(Vec3 *restrict a, const Vec3 *restrict b) {
  a->x -= b->x;
  a->y -= b->y;
  a->z -= b->z;
}

static inline void v3Subb(Vec3 *restrict result, const Vec3 *restrict a,
            const Vec3 *restrict b) {
  result->x = a->x - b->x;
  result->y = a->y - b->y;
  result->z = a->z - b->z;
}

static inline void v3Muls(Vec3 *restrict a, const Vec3 *restrict b) {
  a->x *= b->x;
  a->y *= b->y;
  a->z *= b->z;
}

static inline void v3Mulb(Vec3 *restrict result, const Vec3 *restrict a,
            const Vec3 *restrict b) {
  result->x = a->x * b->x;
  result->y = a->y * b->y;
  result->z = a->z * b->z;
}

static inline void v3Divs(Vec3 *restrict a, const Vec3 *restrict b) {
  a->x /= b->x;
  a->y /= b->y;
  a->z /= b->z;
}

static inline void v3Divb(Vec3 *restrict result, const Vec3 *restrict a,
            const Vec3 *restrict b) {
  result->x = a->x / b->x;
  result->y = a->y / b->y;
  result->z = a->z / b->z;
}

static inline float v3Dot(const Vec3 *restrict a, const Vec3 *restrict b) {
  return a->x * b->x + a->y * b->y + a->z * b->z;
}

static inline float v3Dist2(const Vec3 *restrict a, const Vec3 *restrict b) {
  return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) +
         (a->z - b->z) * (a->z - b->z);
}

static inline float v3Dist(const Vec3 *restrict a, const Vec3 *restrict b) {
  return sqrtf(v3Dist2(a,b));
}

static inline float v3Mag2(const Vec3 *restrict a){
    return a->x*a->x + a->y*a->y + a->z*a->z;
}

static inline float v3Mag(const Vec3 *restrict a){
    return sqrtf(v3Mag2(a));
}

static inline void v3Norms(Vec3 *restrict a){
    float m = 1.0f/v3Mag(a);
    a->x *= m;
    a->y *= m;
    a->z *= m;
}

static inline void v3Normb(Vec3 *restrict result, const Vec3 *restrict a){
    float m = 1.0f/v3Mag(a);
    result->x = a->x*m;
    result->y = a->y*m;
    result->z = a->z*m;
}

static inline void v3Scales(Vec3 *restrict a, float s){
    a->x *= s;
    a->y *= s;
    a->z *= s;
}

static inline void v3Scaleb(Vec3 *restrict result, const Vec3 *restrict a, float s) {
    result->x = a->x*s;
    result->y = a->y*s;
    result->z = a->z*s;
}

static inline void v3Crossb(Vec3 *restrict result, const Vec3 *restrict a, const Vec3 *restrict b) {
    result->x = a->y*b->z - a->z*b->y;
    result->y = a->z*b->x - a->x*b->z;
    result->z = a->x*b->y - a->y*b->x;
}

static inline void v3Zeros(Vec3 *restrict a){
    a->x = 0;
    a->y = 0;
    a->z = 0;
}

#endif