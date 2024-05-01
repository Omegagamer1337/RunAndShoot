#include <iostream>
#include "engine/Engine.h"

int main(int argc, char** argv)
{
	Engine engine = Engine("RunAndShoot");
	int exitcode = engine.run();
	return exitcode;
}