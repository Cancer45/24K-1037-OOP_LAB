#include <iostream>
#include <string>
#include <cctype>

class Message
{
	std::string message;
	
	public:
	Message () : message("default") {}
	Message (std::string message) : message(message) {}
	
	std::string toString () const
	{
		return message;
	}

	void setMessage (std::string message)
	{
		this -> message = message;
	}
};

bool containsKeyword (const Message& messageObject, const std::string& keyword)
{
	int keyLength = keyword.length(), msgLength = messageObject.toString().length();
	char* tmp = new char [keyLength + 1];

	for (int i = 0; i <= msgLength - keyLength; i++)
	{
		for (int j = 0; j < keyLength; j++)
			tmp[j] = messageObject.toString()[i + j];	
		
		if (std::string(tmp) == keyword)
		{
			delete [] tmp;
			return true;
		}
	}

	delete [] tmp;
	return false;
}

std::string encodeMessage (const Message& messageObject)
{
	std::string toEncode = messageObject.toString();
	int msgLength = toEncode.length();

	for (int i = 0; i < msgLength; i++)
	{
		if (isalpha(toEncode[i])) 
		{
			if (toEncode[i] == 'z')
			{
				toEncode[i] = 'a';
				continue;
			}

			if (toEncode[i] == 'Z')
			{
				toEncode[i] = 'A';
				continue;
			}

			toEncode[i]++;
		}
	}	

	return toEncode;
}

class SMS : public Message
{
	std::string contactNo;

	public:
	SMS () : Message("default"), contactNo("0") {}
	SMS (std::string message, std::string contactNo) : Message(message), contactNo(contactNo) {}

	std::string getNo ()
	{
		return contactNo;
	}

	void setNo (std::string contactNo)
	{
		this -> contactNo = contactNo;
	}

	std::string toString ()
	{
		return contactNo + "	|	" + Message::toString();
	}
};

class Email : public Message
{
	std::string sender, receiver, subject;
	
	public:
	Email () : Message("default"), sender("default"), subject("default"), receiver("default") {}
	Email (std::string message, std::string sender, std::string receiver, std::string subject) : Message(message), sender(sender), receiver(receiver), subject(subject) {}

	std::string getSender ()
	{
		return sender;
	}

	void setSender (std::string sender)
	{
		this -> sender = sender;
	}

	std::string getReceiver ()
	{
		return receiver;
	}

	void setReceiver (std::string receiver)
	{
		this -> receiver = receiver;
	}

	std::string getSubject ()
	{
		return subject;
	}

	void setSubject (std::string subject)
	{
		this -> subject = subject;
	}

	std::string toString ()
	{
		return sender + "	|	" + receiver + "	|	 " + subject + "	|	" + Message::toString();
	}
};

int main ()
{
	SMS smsSample1;
	Email emailSample1;

	//get SMS and Email
	std::cout << std::endl << smsSample1.toString() << std::endl;
	std::cout << emailSample1.toString() << std::endl;

	//set SMS and Email
	smsSample1.setNo("03335779591");
	smsSample1.setMessage("Hey, this is Ali");
	
	emailSample1.setSender("HR");
	emailSample1.setReceiver("Malcom");
	emailSample1.setSubject("Seminar Invite");
	emailSample1.setMessage("Hope you are doing well. This is Ali from HR. You are invited to attend today's seminar on workplace ethics in conference hall 2.");

	//get SMS and Email
	std::cout << std::endl << smsSample1.toString() << std::endl;
	std::cout << std::endl << emailSample1.toString() << std::endl;

	//find keyword
	std::string keyword = "seminar";

	if (containsKeyword(emailSample1.Message::toString(), keyword))
		std::cout << std::endl << "Contains Keyword: " + keyword << std::endl;
	else
		std::cout << "Does not contain Keyword: " + keyword << std::endl;

	keyword = "meeting";

	if (containsKeyword(emailSample1.Message::toString(), keyword))
		std::cout << "Contains Keyword: " + keyword << std::endl;
	else
		std::cout << "Does not contain Keyword: " + keyword << std::endl;

	//encode message
	std::cout << std::endl << "Original: " + smsSample1.Message::toString() << std::endl;
	std::cout << "Encoded: " + encodeMessage(smsSample1.Message::toString()) << std::endl;
}
