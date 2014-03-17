//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Autotiles																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "autotiles.h"
#include "vector2d.h"
#include <SFML/graphics.hpp>
#include <iostream>
#include <cstring>
#include "usefullSFMLThings.h"

/*
	Autotiles works like in RPGMaker XP
*/
namespace MapEngine
{

	Autotile::Autotile()
	{

	}

	void Autotile::init(const std::string & fileName)
	{
		if (!_image->loadFromFile("Graphics/Autotiles/" + fileName))
		{
			std::cout << "ERROR WITH : Autotile Graphics/Autotiles/" << fileName << " Not Found" << std::endl;
		}

		_resolution = _image->getSize().x / 3;
		_scale = 64.f / _resolution;
		_semiResolution = _resolution / 2;
		for (unsigned int s = 0; s < 4; s++)
		{
			_sprite[s].setTexture(*_image);
			_sprite[s].setScale(_scale, _scale);
		}

	}

	sf::Texture* Autotile::GetTexture()
	{
		return _image;
	}

	void Autotile::GetSprites(const bool & c00, const bool & c10, const bool & c20,
		const bool & c01, const bool & c21,
		const bool & c02, const bool & c12, const bool & c22, const Point2i & position, sf::VertexArray & final)
	{
		Point2i ps1, ps2, ps3, ps4;
		/*
		---------
		| 1 | 2 |
		---------
		| 3 | 4 |
		---------

		Chaque minicase a un côté egale à la moitié de le resolution
		et la partie de l'image pour chacune de ces minecases
		est déterminé suivant la presence ou l'absence de l'autotile
		sur les differentes cases adjacentes
		*/


		if (!c00&&c10&&c01){ ps1 = Point2i(2, 0); }														//Inter coins
		else
		{
			if (c00&&c10&&c01&&c21&&c12){ ps1 = Point2i(1, 2); }											//Millieu
			else
			{
				if (!c01&&!c10){ ps1 = Point2i(0, 1); }													//Haut-Gauche
				else
				{
					if (!c10&&c01&&c21){ ps1 = Point2i(1, 1); }											//Haut
					else
					{
						if (c01&&!c10&&!c21){ ps1 = Point2i(2, 1); }										//Haut-Droite
						else
						{
							if (!c01&&c10&&c12){ ps1 = Point2i(0, 2); }									//Gauche
							else
							{
								if (c00&&c10&&c01&&!c21&&c12){ ps1 = Point2i(2, 2); }						//Droite
								else
								{
									if (c10&&!c01&&!c12){ ps1 = Point2i(0, 3); }							//Bas-Gauche
									else
									{
										if (c00&&c10&&c01&&c21&&!c12){ ps1 = Point2i(1, 3); }				//Bas
										else
										{
											ps1 = Point2i(2, 3);										//Bas-Droite

										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (c10&&c21&&!c20){ ps2 = Point2i(2, 0); }
		else
		{
			if (c10&&c20&&c01&&c21&&c12){ ps2 = Point2i(1, 2); }
			else
			{
				if (!c01&&!c10&&c21){ ps2 = Point2i(0, 1); }
				else
				{
					if (!c10&&c01&&c21){ ps2 = Point2i(1, 1); }
					else
					{
						if (!c10&&!c21){ ps2 = Point2i(2, 1); }
						else
						{
							if (!c01&&c10&&c12&&c21&&c20){ ps2 = Point2i(0, 2); }
							else
							{
								if (c10&&!c21&&c12){ ps2 = Point2i(2, 2); }
								else
								{
									if (c10&&!c01&&!c12){ ps2 = Point2i(0, 3); }
									else
									{
										if (c20&&c10&&c01&&c21&&!c12){ ps2 = Point2i(1, 3); }
										else
										{
											ps2 = Point2i(2, 3);

										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (c01&&c12&&!c02){ ps3 = Point2i(2, 0); }
		else
		{
			if (c10&&c01&&c21&&c02&&c12){ ps3 = Point2i(1, 2); }
			else
			{
				if (!c01&&!c10&&c12){ ps3 = Point2i(0, 1); }
				else
				{
					if (!c10&&c01&&c21&&c02&&c12){ ps3 = Point2i(1, 1); }
					else
					{
						if (c01&&!c10&&!c21&&c02&&c12){ ps3 = Point2i(2, 1); }
						else
						{
							if (!c01&&c10&&c12){ ps3 = Point2i(0, 2); }
							else
							{
								if (c02&&c10&&c01&&!c21&&c12){ ps3 = Point2i(2, 2); }
								else
								{
									if (!c01&&!c12){ ps3 = Point2i(0, 3); }
									else
									{
										if (c01&&c21&&!c12){ ps3 = Point2i(1, 3); }
										else
										{
											ps3 = Point2i(2, 3);

										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (!c22&&c12&&c21){ ps4 = Point2i(2, 0); }
		else
		{
			if (c22&&c10&&c01&&c21&&c12){ ps4 = Point2i(1, 2); }
			else
			{
				if (!c01&&!c10&&c21&&c22&&c12){ ps4 = Point2i(0, 1); }
				else
				{
					if (!c10&&c01&&c21&&c12&&c22){ ps4 = Point2i(1, 1); }
					else
					{
						if (!c10&&!c21&&c12){ ps4 = Point2i(2, 1); }
						else
						{
							if (!c01&&c10&&c12&&c21&&c22){ ps4 = Point2i(0, 2); }
							else
							{
								if (c10&&!c21&&c12){ ps4 = Point2i(2, 2); }
								else
								{
									if (!c01&&!c12&&c21){ ps4 = Point2i(0, 3); }
									else
									{
										if (c01&&c21&&!c12){ ps4 = Point2i(1, 3); }
										else
										{
											ps4 = Point2i(2, 3);
										}
									}
								}
							}
						}
					}
				}
			}
		}

		_sprite[0].setTextureRect(sf::IntRect(ps1.x*_resolution, ps1.y*_resolution, _semiResolution, _semiResolution));
		_sprite[0].setPosition(position*((float)(_resolution)*_scale));
		_sprite[1].setTextureRect(sf::IntRect(ps2.x*_resolution + _semiResolution, ps2.y*_resolution, _semiResolution, _semiResolution));
		_sprite[1].setPosition(Vecteur2f((float)(position.x) + 0.5f, (float)(position.y))*((float)(_resolution)*_scale));
		_sprite[2].setTextureRect(sf::IntRect(ps3.x*_resolution, ps3.y*_resolution + _semiResolution, _semiResolution, _semiResolution));
		_sprite[2].setPosition(Vecteur2f((float)(position.x), (float)(position.y) + 0.5f)*((float)(_resolution)*_scale));
		_sprite[3].setTextureRect(sf::IntRect(ps4.x*_resolution + _semiResolution, ps4.y*_resolution + _semiResolution, _semiResolution, _semiResolution));
		_sprite[3].setPosition(Vecteur2f((float)(position.x) + 0.5f, (float)(position.y) + 0.5f)*((float)(_resolution)*_scale));

		for (unsigned int s = 0; s < 4; s++)
		{
			sfUse::Sprite2VertexArray(_sprite[s], final);
		}
	}

}