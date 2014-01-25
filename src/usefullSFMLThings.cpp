//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														UseFullSFMLThings																//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "usefullSFMLThings.h"

namespace sfUse
{

    void Sprite2VertexArray(const sf::Sprite & sprite,sf::VertexArray & vertices)
    {
        sf::IntRect texBox = sprite.getTextureRect();
        sf::FloatRect box = sprite.getGlobalBounds();

		vertices.append(sf::Vertex(sf::Vector2f(box.left, box.top), sf::Vector2f((float)texBox.left, (float)texBox.top)));
		vertices.append(sf::Vertex(sf::Vector2f(box.left, box.top + box.height), sf::Vector2f((float)texBox.left, (float)(texBox.top + texBox.height))));
		vertices.append(sf::Vertex(sf::Vector2f(box.left + box.width, box.top + box.height), sf::Vector2f((float)(texBox.left + texBox.width), (float)(texBox.top + texBox.height))));
		vertices.append(sf::Vertex(sf::Vector2f(box.left + box.width, box.top), sf::Vector2f((float)(texBox.left + texBox.width), (float)texBox.top)));
    }

}
