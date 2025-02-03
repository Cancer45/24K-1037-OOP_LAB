#include <iostream>

using namespace std;

#define MAX_ITEMS 100

class stationaryShop
{
	string items [MAX_ITEMS];
	float prices [MAX_ITEMS];

	int item_count = 0;

	public:
	//method 1
	void addProduct ()
	{
		if (item_count == MAX_ITEMS)
		{
			cout << "MAX CAPACITY. CANNOT ADD ADDITIONAL ITEMS";
			return;
		}

		cout << "PRODUCT NAME: ";
		cin >> items[item_count];
		cout << "PRICE: ";
		cin >> prices[item_count];
		item_count++;
	}

	//method 2
	void printItems ()
	{
		for (int i = 0; i < item_count; i++)
			cout << i + 1 << items[i] << endl;
	}

	//method 3
	void editItems ()
	{
		int index;
		float newPrice;
		
		printItems();

		do
		{
			cout << "Item to Edit: ";
			cin >> index;
		} while (index < 0 || index > item_count);

		cout << "New Price: ";
		cin >> newPrice;

		prices [index] = newPrice;		
	}

	//method 4
	void displayAll ()
	{
		for (int i = 0; i < item_count; i++)
			cout << i + 1 << ". " << items[i] << "    :    " << prices[i];
	}	

	//method 5
	string* getItems ()
	{
		return items;
	}

	//method 6
	void createReceipt ()
	{
		int numPurchased, index;

		printItems();

		cout << "Number of Items Purchased: ";
		cin >> numPurchased; 

		int quantity[numPurchased];
		int itemsIndex[numPurchased];

		for (int i = 0; i < numPurchased; i++)
		{
			do
			{
				cout << "Item " << i + 1 << ": ";
				cin >> index;
			} while (index < 0 || index > item_count);

			itemsIndex[i] = index;
			
			cout << "Quantity: "; 
			cin >> quantity[i];
		}

		cout << items[itemsIndex[i]] << "    :    " << prices[itemsIndex[i]] << "    :    " << quantity[i] << endl;

		for (int i = 0; i < numPurchased; i++)
		{
			cout << items[itemsIndex[i]] << "    :    " << prices[itemsIndex[i]] << "    :    " << quantity[i] << endl;
		}
	}
};
