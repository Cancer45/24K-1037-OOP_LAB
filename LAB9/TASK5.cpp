#include <iostream>

class Activity
{
	public:
	virtual void calculateCaloriesBurned () = 0;
};

class Running : public Activity
{
	double distance, time;

	public:
	Running (double distance, double time) : distance(distance), time(time) {}

	void calculateCaloriesBurned () override
	{
		std::cout << "Calories Burned: " << 60 * distance << " kcal\n";
	}
};

class Cycling : public Activity
{
	double speed, time;

	public:
	Cycling (double speed, double time) : speed(speed), time(time) {}
	
	void calculateCaloriesBurned () override
	{
		std::cout << "Calories Burned: " << 30 * speed * time << " kcal\n";
	}

};

int main ()
{
	Running r_obj(4.5, 30);
	Cycling c_obj(21.3, 0.88);

	Activity* a_ptr = &r_obj;
	a_ptr->calculateCaloriesBurned();

	a_ptr = &c_obj;
	a_ptr->calculateCaloriesBurned();
}

