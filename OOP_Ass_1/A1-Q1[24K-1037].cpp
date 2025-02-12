#include <iostream>
#include <iterator>

class Student; //forward declaration

class Skill
{
	int skillID;
	std::string name, description;

	public:
	//constructor
	Skill (int skillID, std::string name, std::string description)
	{
		this -> skillID = skillID;
		this -> name = name;
		this -> description = description;
	}

	//method 1
	void showSkillDetails ()
	{
	}

	//method 2
	void updateSkillDescription (std::string newDescription)
	{
	}
};

class Sport
{
	int sportID;
	std::string name, description;
	Skill* requiredSkills = nullptr;

	public:
	//constructor
	Sport (int sportID, std::string name, std::string description)
	{
		this -> sportID = sportID;
		this -> name = name;
		this -> description = description;
	}

	//method 1
	void addSkill (Skill s)
	{
	}

	void removeSkill (Skill s)
	{
	}
};

class Mentor
{
	int mentorID, maxLearners, numLearners = 0;
	std::string name;
	Sport* sportsExpertise = nullptr; 
	Student* assignedLearners = nullptr;

	public:
	//constructor
	Mentor (int mentorID, int maxLearners, std::string name, Sport* sportsExpertise)
	{
		this -> mentorID = mentorID;
		this -> name = name;
		this -> maxLearners = maxLearners;
		this -> sportsExpertise = sportsExpertise;
	}

	//default constructor
	Mentor () {}
	
	//method 1
	int assignLearner (Student& s);

	//method 2
	void removeLearner (Student& s)
	{
	}
	
	//method 3
	void viewLearners ()
	{
	}

	//method 4
	void provideGuidance ()
	{
	}

	//getters
	std::string getName ()
	{
		return name;
	}

	int getID()
	{
		return mentorID;
	}

	Sport* getExpertise ()
	{
		return sportsExpertise;
	}
};

class Student
{
	int studentID, age;
	std::string name, *sportsInterest; 
	Mentor* mentorAssigned = nullptr;
	
	public:
	//constructor
	Student (int studentID, int age, std::string name, std::string *sportsInterest)
	{
		this -> studentID = studentID;
		this -> age = age;
		this -> name = name;
		this -> sportsInterest = sportsInterest;
	}
	
	//default constructor
	Student () {}

	//method 1
	int registerForMentorship (Mentor& m);

	//method 2
	int viewMentorDetails ()
	{
		if (mentorAssigned == nullptr)
		{
			std::cout << "NO MENTOR ASSIGNED" << std::endl;
			return 0;
		}

		std::cout << "Name: " << mentorAssigned->getName() << std::endl << "ID: " << mentorAssigned->getID() << std::endl;

		for (int i = 0; i < ; i++)
		{
		}
			
	}

	//method 3
	int updateSportsInterest (Sport s)
	{
		return 0;
	}
};

int Mentor::assignLearner (Student& s)
{
	if (numLearners == maxLearners)
		return 0;

	Student* tmpArray = new Student [numLearners + 1];

	for (int i = 0; i < numLearners; i++)
		tmpArray[i] = assignedLearners[i];

	tmpArray[numLearners] = s;

	delete [] assignedLearners;

	assignedLearners = tmpArray;
	numLearners++;
	return 1;
}

int Student::registerForMentorship (Mentor& m)
{
	if (!m.assignLearner(*this))
		return 0;	
			
	mentorAssigned = &m;
	return 1;
}
