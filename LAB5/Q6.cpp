#include <iostream>

class GREngine
{
    public:
    void renderGraphics()
    {
        std::cout << "GRAPHICS RENDERED" << std::endl;
    }
};

class InputHandler
{
    public:
    void handleInputs()
    {
        std::cout << "INPUTS HANDELED" << std::endl;
    }
};

class PhysicsEngine
{
    public:
    void doPhysics()
    {
        std::cout << "SIMULATING PHYSICS" << std::endl;
    }
};

class GameEngine
{
    GREngine renderer;
    InputHandler handler;
    PhysicsEngine simulator;

	public:
	GameEngine ()
	{
		std::cout << "GAME ENGINE INIT" << std::endl;
	}

	~GameEngine ()
	{
		std::cout << "GAME ENGINE DESTROYED" << std::endl;
	}

	//getters
	GREngine getRenderer()
	{
		return renderer;
	}

	InputHandler getHandler()
	{
		return handler;
	}

	PhysicsEngine getSimulator ()
	{
		return simulator;
	}
};

int main ()
{
	GameEngine engine;
	engine.getRenderer().renderGraphics();
	engine.getHandler().handleInputs();
	engine.getSimulator().doPhysics();
}
