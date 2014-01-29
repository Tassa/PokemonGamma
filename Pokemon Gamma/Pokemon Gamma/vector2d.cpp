//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														vecteur2d																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "vector2d.h"
#include "direction.h"
#include "abs.h"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <utility>

Vecteur2f::Vecteur2f(const float & X, const float & Y) : sf::Vector2f(X,Y){}

float Vecteur2f::length()const
{
    return sqrt( x*x + y*y);
}

Vecteur2f Vecteur2f::normalize()
{
    Vecteur2f v = *this;
	v /= length();
    return v;
}

Vecteur2f Vecteur2f::operator*(const float & f)
{
	return Vecteur2f(x*f,y*f);
}

Point2i::Point2i() : sf::Vector2i(){}

Point2i::Point2i(const int X, const int Y)
{
    x = X;
    y = Y;
}

Point2i::Point2i(const Point2i & p)
{
	x = p.x;
	y = p.y;
}

Point2i::Point2i(const Point2d & p)
{
	x = static_cast<int>(p.x);
	y = static_cast<int>(p.y);
}

/*Point2i & Point2i::operator=(const Point2i & p)
{
	this->x=p.x;
	this->y=p.y;
	return *this;
}*/

Point2d::Point2d(const float X, const float Y)
{
    x = X;
    y = Y;
}

Point2d Point2i::operator*(const float & facteur) const
{
    return Point2d(x*facteur,y*facteur);
}

Point2i Point2i::operator*(const int & facteur) const
{
	return Point2i(x*facteur, y*facteur);
}

Point2i Point2i::addDirection(const Direction & d) const
{
	switch (d)
	{
		case Gauche:
			return Point2i((this->x)-1,(this->y));
		break;
		case Droite:
			return Point2i((this->x)+1,(this->y));
		break;
		case Haut:
			return Point2i((this->x),(this->y)-1);
		break;
		case Bas:
			return Point2i((this->x),(this->y)+1);
		break;
		default:
			return *this;
		break;
	}
}


Point2d::Point2d(): sf::Vector2f(){}


Point2d::Point2d(const Point2i & p)
{
	x = static_cast<float>(p.x);
	y = static_cast<float>(p.y);
}

Point2d& Point2d::operator=(const Point2i & p)
{
	*this = Point2d(p);
	return *this;
}

Point2d Point2d::addDirection(const Direction & d)
{
	switch (d)
	{
		case Gauche:
			return Point2d(x-1.f,y);
		break;
		case Droite:
			return Point2d(x+1.f,y);
		break;
		case Haut:
			return Point2d(x,y-1.f);
		break;
		case Bas:
			return Point2d(x,y+1.f);
		break;
		default:
			return *this;
		break;
	}
}

std::pair<Direction,Direction> GetDirectionsFromVecteur2f(const Vecteur2f & v)
{
	Direction first,second;
	if(v.x<0)
	{
		first =  Gauche;
	}
	else
	{ 	if(abs(v.x)<MIN_VAL_FOR_VECTORS_2D)
		{
			first = Aucune;
		}
		else
		{
			first = Droite;
		}
	}

	if(v.y<0)
	{
		second = Haut;
	}
	else
	{
		if(abs(v.y)<MIN_VAL_FOR_VECTORS_2D)
		{
			second=Aucune;
		}
		else
		{
			second = Bas;
		}
	}


	return std::make_pair(first,second);
}
