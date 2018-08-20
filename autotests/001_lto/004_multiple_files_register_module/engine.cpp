#include <iostream>

#include <tvm/engine.h>

#include "vm.h"

using namespace nVirtualMachine;

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "usage: " << argv[0] << " <program.tvm>" << std::endl;
		return 1;
	}

	cEngine engine;

	if (registerModules(engine) != eResult::success)
	{
		return 2;
	}

	if (engine.loadProjectFromFile(argv[1]) != eResult::success)
	{
		return 3;
	}

	const cRootStart1* rootStart1;
	const cRootStart2* rootStart2;
	if (engine.getRootModule(rootStart1) != eResult::success ||
	    engine.getRootModule(rootStart2) != eResult::success)
	{
		return 4;
	}

	engine.run();

	engine.rootSignal(rootStart1->rootSignalExit);
	*rootStart1->memoryExit = "_TEXT_ONLY_FOR_ENGINE_21_";

	rootStart2->functionOnlyForEngine(engine);
	rootStart2->functionOnlyForEngineMemory("_TEXT_ONLY_FOR_ENGINE_22_");

	return 0;
}
