//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Map.h																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MAP_H
#define MAP_H

#include <cstring>

#include "tileset.h"
#include "vector2d.h"
#include "direction.h"
#include "evenement.h"

#define NB_CASE_X_VIEW 6
#define NB_CASE_Y_VIEW 4

#define NB_COUCHES 4


typedef struct
{
	sf::VertexArray vertices;
	sf::Texture* texture;
}VertexArrayOnTexture;

class Map;

class Case
{
public:

	//ctor
	Case();

	void init(const Point2i *p1,
		const bool & practic,
		const bool & gauche, const bool & droite, const bool & haut, const bool & bas,
		const unsigned int & autoEvenement);
	

	bool GetPracticable() const;

	bool canDirection(const Direction & d) const;

	Point2i GetTilesetPos(const unsigned int & couche) const;

	bool GetCoucheExist(const unsigned int & couche) const;

	VertexArrayOnTexture vertexArray[6];

private:

	Point2i couches[4];
	bool couchesExist[4];

	bool practicable;
	bool mvtDir[4];
};




class Map : sf::Drawable
{
public:

	Map(const std::string & filePath);

	~Map();

	bool CanMove(const Direction & d1, const Point2i & pos) const;

	void LoadFromFile(const std::string & filePath);

	void updateSprites();

	Case GetCase(const Point2i & p) const;

	Tileset * GetTileset();

	bool GetPracticable(const Point2i & p) const;

	sf::Sprite GetSprite(const unsigned int x, const unsigned int y, const unsigned int & couche);

	sf::Sprite GetSprite(const Point2i & p, const unsigned int & couche);



	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool setMainEvent(Evenement * event);

	bool addEvent(Evenement * event);

private:


	unsigned int _noMap;
	std::string _dateOfCreation;
	std::string _nameOfMap;
	std::string _madeBy;

	unsigned int _typeOf;
	std::string _tileSetName;
	Tileset _tileset;

	unsigned int _height;
	unsigned int _width;
	Case** _cases;

	sf::Vector2f _resolution;

	sf::Texture _backgroundTexture;
	sf::Sprite _emptySprite;
	sf::Sprite _sprite;

	std::vector<Evenement> eventsOnMap;
	std::vector<Evenement*> otherEvents;
	Evenement * mainEvent;
};

#endif