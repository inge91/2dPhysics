#include "StaticElement.h"

StaticElement::StaticElement(std::string location, Vector2 pos, Vector2 size)
	: Sprite(location, pos, size)
{
	s = size;
}

StaticElement::StaticElement(Vector2 pos, Vector2 size)
	: Sprite("../Images/empty.png", pos, size)
{
	s = size;
}
