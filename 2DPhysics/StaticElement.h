#ifndef STATICELEMENT
#define STATICELEMENT
#include "Sprite.h"
#include "Vector2.h"




// Class containing elements that are static, meaning
//  they can influence physics elements but not be influenced by them.
class StaticElement : public Sprite
{
	// A static element contains a position and has a size
	// possibly also sprite data
public:
	StaticElement(string location, Vector2 pos, Vector2 size);
	StaticElement(Vector2 pos, Vector2 size);

protected:
	Vector2 s;
};

#endif // STATICELEMENT
