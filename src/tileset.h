#include <SFML/Graphics.hpp>
#include <string>
#include "vector2d.h"
#include "autotiles.h"

#define MAX_AUTOTILES_PER_TILESET 7

class TilesetCase
{
public:

	TilesetCase();

	TilesetCase(const bool &practicable,
		const bool &mG, const bool &mD, const bool &mH, const bool &mB,
		const unsigned int &autoEvenement,
		const unsigned int &superposition);

	unsigned int autoEvent, superpositionPriority;
	bool practic, mvG, mvD, mvH, mvB;

};

class Tileset
{
public:

	void LoadTextureFromFile(const std::string & tilesetName);

	void LoadDataFromFile(const std::string & tilesetName);

	Tileset(const unsigned int & type, const std::string & name);

	~Tileset();

	sf::Sprite GetSprite(const unsigned int & x, const unsigned int & y);

	sf::Sprite GetSprite(const Point2i & p);

	Autotile* GetAutotile(const Point2i & p);

	bool GetAutotileExist(const Point2i & p) const;

	TilesetCase GetTilesetCase(const unsigned int & x, const unsigned int & y) const;

	TilesetCase GetTilesetCase(const Point2i & p) const;

	sf::Texture* GetTexture();


private:

	sf::Texture _TilesetTexture;
	sf::Sprite _sprite;
	TilesetCase** _cases;
	Autotile autotiles[MAX_AUTOTILES_PER_TILESET];
	bool autotilesExist[MAX_AUTOTILES_PER_TILESET];
	unsigned int _width;
	unsigned int _height;
	unsigned int _resolution;
	unsigned int _type;
	std::string _name;

};
