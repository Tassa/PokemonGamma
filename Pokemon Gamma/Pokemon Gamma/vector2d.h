//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														vecteur2d.h																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <SFML/System/Vector2.hpp>
#include "direction.h"
#include <utility>


class Vecteur2f: public sf::Vector2f
{
public:
    Vecteur2f(const float & X,const float & Y);
    float length()const;
    Vecteur2f normalize();
	Vecteur2f operator*(const float & f);
	bool operator<(Vecteur2f a);
};

class Point2d;

class Point2i: public sf::Vector2i
{
	public :

        Point2i();

        Point2i(const int x, const int y);

        Point2i(const Point2i & p);

		Point2i(const Point2d & p);

		Point2i & operator= (const Point2d& p);

        Point2d operator*(const float & facteur) const;

		Point2i operator*(const int & facteur) const;

		Point2i addDirection(const Direction & d)const;

		bool operator<(const Point2i  & a) const;
};

class Point2d: public sf::Vector2f
{
public:
        Point2d();
		Point2d(const Point2i& p);
		Point2d & operator= (const Point2i &);
		Point2d(const float X, const float Y);
		Point2d addDirection(const Direction & d);
};

std::pair<Direction,Direction> GetDirectionsFromVecteur2f(const Vecteur2f & v);

#endif //VECTOR3D_H
