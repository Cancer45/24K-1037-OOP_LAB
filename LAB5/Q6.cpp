#include <iostrem>

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
    GREngine renderer();
    InputHandler handler();
    PhysicsEngine simulator();

    //TO BE COMPLETED    
}