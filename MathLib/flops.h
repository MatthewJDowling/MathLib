#pragma once
#include "vec2.h"

bool fequals(float lhs, float rhs);

float deg2rad(float deg);

float rad2deg(float rad);

float linearHalf(float x);

float accelerate(float x);

float slow(float x);

float steady(float x);

float bounce(float x);

float bounceFlip(float x);

float parabFlip(float x);

float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float hermiteSpline(float start, float s_tan, float en, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float alpha);

float catRomSpline(float start, float mid, float end);