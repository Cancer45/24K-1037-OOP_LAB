#include <iostream>
#include <cmath>

class Position
{
    public:
    float X, Y;
};

class Shape
{
    protected:
    Position position;
    std::string color;
    float borderThickness;

    public:
    Shape () {}
    Shape (float X, float Y, std::string color, float borderThickness) : color(color), borderThickness(borderThickness) 
    {
        position.X = X;
        position.Y = Y;
    }    

    virtual void draw ()
    {
        std::cout << "drawing shape" << std::endl;
    }

    virtual void calculateArea ()
    {
        std::cout << "calculating shape area" << std::endl;
    }

    virtual void calculatePerimeter ()
    {
        std::cout << "calculating perimeter" << std::endl;
    }
};

class Circle : public Shape
{
    float radius;
	
	public:
	Circle () {}
	Circle (float X, float Y, std::string color, float borderThickness, float radius) : Shape(X, Y, color, borderThickness), radius(radius) {}

    void draw ()
    {
        std::cout << "drawing circle" << std::endl;
    }

    void calculateArea ()
    {
		std::cout << "Area: " << 3.14 * radius * radius << std::endl;
    }

    void calculatePerimeter ()
    {
        std::cout << "Perimeter: " << 2 * 3.14 * radius << std::endl;
    }
};

class Rectangle : public Shape
{
    float width;
    float height;
	
	public:
	Rectangle () {}
	Rectangle (float X, float Y, std::string color, float borderThickness, float width, float height) : Shape(X, Y, color, borderThickness), width(width), height(height) {}

    void draw ()
    {
        std::cout << "drawing rectangle" << std::endl;
    }

    void calculateArea ()
    {
		std::cout << "Area: " << width * height << std::endl;
    }

    void calculatePerimeter ()
    {
        std::cout << "Perimeter: " << 2 * (width + height) << std::endl;
    }
};

class Triangle : public Shape
{
    float lengthA, lengthB, lengthC, angleC;
	
	public:
	Triangle () {}
	Triangle (float X, float Y, std::string color, float borderThickness, float lengthA, float lengthB, float lengthC, float angleC) : Shape(X, Y, color, borderThickness), lengthA(lengthA), lengthB(lengthB), lengthC(lengthC), angleC(angleC) {}

    void draw ()
    {
        std::cout << "drawing triangle" << std::endl;
    }

    void calculateArea ()
    {
		std::cout << "Area: " << 0.5 * lengthA * lengthB * sin(angleC * (3.14 / 180)) << std::endl;
    }

    void calculatePerimeter ()
    {
        std::cout << "Perimeter: " << lengthA + lengthB + lengthC << std::endl;
    }

};

class Polygon : public Shape
{
	Position* points;
	int numPoints;

	float calcLength (Position p1, Position p2)
	{
		return sqrt(pow(double(p2.X - p1.X), 2) + pow(double(p2.Y - p1.Y), 2));
	}
	
	public:
	Polygon () {}
	Polygon (float X, float Y, std::string color, float borderThickness, int numPoints, Position* points) : Shape(X, Y, color, borderThickness), numPoints(numPoints)
	{
		this -> points = new Position [numPoints];

		for (int i = 0; i < numPoints; i++)
			this -> points[i] = points[i];
	}

	~Polygon ()
	{
		delete [] points;
	}

    void draw ()
    {
        std::cout << "drawing polygon" << std::endl;
    }

    void calculateArea ()
    {
		//area calculated using shoelace algorithm

		float S1 = 0, S2 = 0;
		int i = 1;

		for ( ; i < numPoints; i++)
		{
			S1 += points[i - 1].X * points[i].Y;
			S2 += points[i - 1].Y * points[i].X;
		}

		S1 += points[i - 1].X * points[0].Y;
		S2 += points[i - 1].Y * points[0].X;

		float area = 0.5 * (fabs(S1 - S2)); 
		
		std::cout << "Area: " << area << std::endl;
    }

    void calculatePerimeter ()
    {
    	float perimeter = 0;
		int i = 1;

		for ( ; i < numPoints; i++)
			perimeter += calcLength(points[i - 1], points[i]);

		perimeter += calcLength(points[i - 1], points[0]);

		std::cout << "Perimeter: " << perimeter << std::endl;
    }
};

int main() 
{
    // Test Circle
	std::cout << std::endl;
    Circle circle(0, 0, "red", 1.0, 5);
    circle.draw();
    circle.calculateArea();
    circle.calculatePerimeter();

    // Test Rectangle
	std::cout << std::endl;
    Rectangle rectangle(0, 0, "blue", 2.0, 4, 6);
    rectangle.draw();
    rectangle.calculateArea();
    rectangle.calculatePerimeter();

    // Test Triangle
	std::cout << std::endl;
    Triangle triangle(0, 0, "green", 1.5, 3, 4, 5, 90);
    triangle.draw();
    triangle.calculateArea();
    triangle.calculatePerimeter();

    // Test Polygon (Quadrilateral)
	std::cout << std::endl;
    Position points[4] = {{0, 0}, {4, 0}, {4, 3}, {0, 3}};
    Polygon polygon(0, 0, "yellow", 1.0, 4, points);
    polygon.draw();
    polygon.calculateArea();
    polygon.calculatePerimeter();

    return 0;
}
