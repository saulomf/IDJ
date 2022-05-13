#ifndef GEOMETRY_H
#define GEOMETRY_H

class Vec2 {
    public:
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);

        Vec2 opPlus (const Vec2& point);
        Vec2 opMinus (const Vec2& point);
        friend Vec2 opMul (float value, const Vec2& point);
        friend Vec2 opMul (const Vec2& point, float value);
        bool opEq (const Vec2& point);
        bool opDif (const Vec2& point);
        float size();
        Vec2 newVec();
        int normalize();
        float distance(const Vec2& to);
        Vec2 rotated(float angle);
        void rotate(float angle);
        float dot(const Vec2& point);
};

class Rect {
    public:
        float x;
        float y;
        float w;
        float h;

        Rect();
        Rect(float x, float y, float w, float h);
        friend Rect opPlus (const Rect& rec, const Vec2& point);
        friend Rect opPlus (const Vec2& point, const Rect& rec);
        Vec2 getCenter() const;
        float getDistance(const Rect& to);
        bool isIn(const Vec2& point);
};

#endif