/*
character.h

Aron Lebani
29 March 2016
*/

#ifndef CHARACTER_H

#define CHARACTER_H

class character
{
public:
	character();
	//

	int getX();
	// Return x coord of left

	void setX(int x);
	// Set x coord of left

	int getY();
	// Return y coord of top

	void setY(int y);
	// Set y coord of top

	int getXc();
	// Return x coord of centre

	void setXc(int x);
	// Set x coord of centre

	int getYc();
	// Return y coord of centre

	void setYc(int y);
	// Set y coord of centre

	int getWidth();
	// Returns width in number of characters

	int getHeight();
	// Returns height in number of characters

private:
	int _x;
	// x coord

	int _y;
	// y coord

protected:
	int width;
	// Width in number of characters

	int height;
	// Height in number of characters
};

#endif