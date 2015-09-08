/*******************

	Example program showcasing the appropriate usage
	sfw features. This library is SUPER TINY and 
	NOT featureful. It is intended for education
	use only.

	It attempts to provide the simplest openGL
	context and drawing options possible.

	author: Esmeralda Salamone, esmes@aie.edu.au

********************/



#include "sfwdraw.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void main()
{
	//first we need to initialize our graphics context- or window.
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Dinosaurs!");

	
	float xpos = 300, ypos = 400; // position
	float xacc = 0, yacc = 0;	  // acceleration
	float xvel = 0, yvel = 0;	  // velocity
	float speed = 100;

	// then we need to update our buffers, poll for input, etc.
	while (sfw::stepContext())
	{
		// we haven't covered frame independent movement yet,
			// but we'll use some euler integration
		// we also haven't gotten into vector math yet,
			// so we'll use cardinal speeds 
		xpos += xvel * sfw::getDeltaTime();
		ypos += yvel * sfw::getDeltaTime();

		// base acceleration on the keypress
		yacc = xacc = 0;
		if (sfw::getKey('a')) xacc = -speed;
		if (sfw::getKey('d')) xacc = speed;
		if (sfw::getKey('w')) yacc = -speed;
		if (sfw::getKey('s')) yacc = speed;
		
		// more euler integration
		xvel += xacc * sfw::getDeltaTime();
		yvel += yacc * sfw::getDeltaTime();

		sfw::drawCircle(xpos, ypos, 30);

		sfw::drawLine(5, 5, 5, SCREEN_HEIGHT-5);
		sfw::drawLine(5, 5, SCREEN_WIDTH-5, 5);
		
		sfw::drawLine(SCREEN_WIDTH-5, SCREEN_HEIGHT-5, 5, SCREEN_HEIGHT-5);
		sfw::drawLine(SCREEN_WIDTH - 5, SCREEN_HEIGHT - 5, SCREEN_WIDTH- 5, 5);
	}

	//finally, we need to properly shut stuff down.
	sfw::termContext();
}