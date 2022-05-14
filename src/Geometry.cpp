#include <cmath>
#include "../include/Geometry.h"

////////////////////////// Implementacoes de vec2

Vec2::Vec2() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

//soma de vetores
void Vec2::opPlus(const Vec2& point) {
    x = x + point.x;
    y = y + point.y;
}

//subtracao de vetores
void Vec2::opMinus (const Vec2& point) {
    x = x - point.x;
    y = y - point.y;
}

//produto escalar
Vec2 opMul (float value, const Vec2& point) {
    return Vec2(
        point.x * value,
        point.y * value
    );
}

//produto escalar
Vec2 opMul (const Vec2& point, float value) {
    return Vec2(
        point.x * value,
        point.y * value
    );
}

//igualdade de vetores
bool Vec2::opEq (const Vec2& point) {
    return (x == point.x && y == point.y);
}

//diferenca de vetores
bool Vec2::opDif (const Vec2& point) {
    return !(x == point.x && y == point.y);
}

//retorna o tamanho do vetor
float Vec2::size() {
    float size = sqrt((x*x)+(y*y));
    return size;
}

//retorna novo vetor na mesma direcao
Vec2 Vec2::newVec() {
    float mag = this->size();
    if(mag >= 0) {
        Vec2 result(x / mag, y / mag);
        return result;
    }
    return Vec2();
}

//normaliza o vetor
int Vec2::normalize() {
    float mag = this->size();
    if(mag >= 0) {
        x /= mag;
        y /= mag;
        return 1;
    }
    return 0;
}

//retorna o tamanho da distancia entre os vetores
float Vec2::distance(const Vec2& to) {
    Vec2 res(to.x - x, to.y - y);
    return res.size();
}

//Rotaciona o vetor pelo angulo em radianos
Vec2 Vec2::rotated(float angle) {
    float newx = x * cos(angle) - y * sin(angle);
    float newy = y * cos(angle) + x * sin(angle);
    return Vec2(newx, newy);
}


////////////////////////// Implementacoes de Rect

Rect::Rect() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rect::Rect(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

//Adiciona ao rect
Rect opPlus (const Rect& rec, const Vec2& point) {
    return Rect(rec.x + point.x, rec.y + point.y, rec.w, rec.h);
}

//Adiciona ao rect
Rect opPlus (const Vec2& point, const Rect& rec) {
    return Rect(
        rec.x + point.x,
        rec.y + point.y,
        rec.w,
        rec.h
    );
}

//Retorna o centro
Vec2 Rect::getCenter() const {
    return Vec2(
        x + (w / 2),
        y + (h / 2)
    );
}

//Funcao para pegar distancia entre o centro e o ponto
float Rect::getDistance(const Rect& to) {
    return this->getCenter().distance(to.getCenter());
}

//Funcao para checar se o ponto esta na area
bool Rect::isIn(const Vec2& point) {
    return (point.x >= x) && (point.y >= y) && (point.x <= x + w) && (point.y <= y + h);
}