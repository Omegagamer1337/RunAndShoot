#include <iostream>
#include "engine/Engine.h"
#include "app/GameInit.cpp"	

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	Engine engine = Engine("RunAndShoot", GameInit::drawStaticImages);
	GameInit::loadTextures(engine.getRenderer());
	engine.addGameObject(GameInit::getGameObjects());

	return engine.run();
}