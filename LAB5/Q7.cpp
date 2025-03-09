#include <iostream>

class MenuItem
{
	std::string itemName;
	float itemPrice;

	public:
	//para constructor
	MenuItem (std::string itemName, float itemPrice) : itemName(itemName), itemPrice(itemPrice) {}

	//default constructor
	MenuItem () {}

	//setters
	void setName (std::string name)
	{
		itemName = name;
	}

	void setPrice (float price)
	{
		itemPrice = price;
	}

	//getters
	std::string getName ()
	{
		return itemName;
	}

	float getPrice ()
	{
		return itemPrice;
	}
};

class Menu
{
	MenuItem* items = nullptr;
	int numItems;

	public:
	Menu () : numItems(0) {}

	//methods
	void addItem (MenuItem newItem)
	{
		MenuItem* tmpArray = new MenuItem [numItems + 1];

		for (int i = 0; i < numItems; i++)
			tmpArray[i] = items[i];

		tmpArray[numItems] = newItem;

		delete [] items;

		items = tmpArray;
		numItems++;

		std::cout << newItem.getName() << " ADDED" << std::endl;
	}	

	void removeItem (MenuItem toRemove)
	{
		MenuItem* tmpArray = new MenuItem [numItems - 1];

		int flag = 0;

		for (int i = 0; i < numItems; i++)
		{
			if (!flag && items[i].getName() == toRemove.getName())
			{
				flag = 1;
			}

			if (!flag && i == numItems - 1)
			{
				std::cout << "NO SUCH ITEM" << std::endl;
				return;
			}

			tmpArray[i] = items[i + flag];
		}

		delete [] items;

		items = tmpArray;
		numItems--;

		std::cout << toRemove.getName() << "REMOVED" << std::endl;
	}

	void displayAll ()
	{
		for (int i = 0; i < numItems; i++)
		{
			std::cout << items[i].getName() << "    :    " << items[i].getPrice() << std::endl;
		}
	}

	MenuItem* getList ()
	{
		return items;
	}
};

class Payment
{
	float amount;

	public:
	Payment (float amount) : amount(amount) {}

	Payment () {}

	float getAmount ()
	{
		return amount;
	}
};

class Order
{
	Payment total; 
	MenuItem* ordered = nullptr;
	int numItems;

	public:
	Order (float total, Menu menu, int menuItems, MenuItem* ordered, int numItems)
	{
		this -> total = Payment(total);
		this -> ordered = new MenuItem [numItems];
		this -> numItems = numItems;

		for (int i = 0; i < numItems; i++)
		{
			for (int j = 0; j < menuItems; i++)
			{
				if (ordered[i].getName() == menu.getList()[j].getName())
					this -> ordered[i] = ordered[i];
			}
		}
	}

	void displayAll ()
	{
		for (int i = 0; i < numItems; i++)
			std::cout << "Item " << i + 1 << ": " << ordered[i].getName() << std::endl;

		std::cout << "Total: " << total.getAmount() << std::endl;
	}
};

int main ()
{
	Menu myMenu;

	int numItems = 10, numOrdered = 3;
	MenuItem items [numItems];

	items[0] = MenuItem("Roast Beef", 10.50);
	items[1] = MenuItem("lamb Chops", 6.90);
	items[2] = MenuItem("Morrocan Chicken", 5.60);
	items[3] = MenuItem("French Onion Soup" , 4.30);
	items[4] = MenuItem("Italian Carbonarra", 2.65);
	items[5] = MenuItem("Berlin Doner", 1.50);
	items[6] = MenuItem("Tomato Soup", 2.00);
	items[7] = MenuItem("Chauterie", 7.30);
	items[8] = MenuItem("Spicy Fried Chicken", 3.90);
	items[9] = MenuItem("Lotus Cheesecake", 5.10);
	
	for (int i = 0; i < numItems; i++)
		myMenu.addItem(items[i]);

	myMenu.displayAll();

	float total = 0;

	MenuItem orderedItems [numOrdered];
	orderedItems[0] = MenuItem("Italian Carbonarra", 2.65);
	orderedItems[1] = MenuItem("French Onion Soup" , 4.30);
	orderedItems[2] = MenuItem("Lotus Cheesecake", 5.10);

	for (int i = 0; i < numOrdered; i++)
		total += orderedItems[i].getPrice();

	Order myOrder (total, myMenu, numItems, orderedItems, numOrdered);
	myOrder.displayAll();
}


