#include <iostream>

using namespace std;

class SShop
{
	string* items = new string [0];
	float* prices = new float [0];

	int item_count = 0;

	public:
	//method 1
	void addProduct ()
	{
		int n;
		cout << "No. Items to Add: ";
		cin >> n;
		
		string* tmp_items = new string [item_count + n];
		float* tmp_prices = new float [item_count + n];

		for (int i = 0; i < item_count; i++)
		{
			tmp_items[i] = items[i];
			tmp_prices[i] = prices[i];
		}

		delete [] items;
		delete [] prices;

		items = tmp_items;
		prices = tmp_prices;

		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "PRODUCT NAME: ";
			cin >> items[item_count + i];
			cout << "PRICE: ";
			cin >> prices[item_count + i];
		}
		cout << endl;

		item_count += n;
	}

	//method 2
	void printItems ()
	{
		cout << endl << "ITEMS" << endl;
		for (int i = 0; i < item_count; i++)
			cout << i + 1 << ". " << items[i] << endl;
		cout << endl;
	}

	//method 3
	void changePrice ()
	{
		int index;
		float newPrice;
		
		printItems();

		do
		{
			cout << "Item to Edit: ";
			cin >> index;
		} while (index < 1 || index > item_count);

		cout << "New Price: ";
		cin >> newPrice;

		prices [index - 1] = newPrice;		
		cout << endl << items[index - 1] << " now cost/s " << prices[index - 1] << endl << endl;
	}

	//method 4
	void displayAll ()
	{
		cout << endl;

		for (int i = 0; i < item_count; i++)
			cout << i + 1 << ". " << items[i] << "    :    " << prices[i] << endl;

		cout << endl;
	}	

	//method 5
	string* getItems ()
	{
		return items;
	}

	//method 6
	void printReceipt ()
	{
		if (item_count == 0)
		{
			cout << "NO ITEMS IN STOCK" << endl;
			return;
		}

		int numPurchased, index;

		printItems();

		int quantity[item_count];

		do
		{
		cout << "No. Items Purchased: ";
		cin >> numPurchased;
		} while  (numPurchased < 1 || numPurchased > item_count);

		for (int i = 0; i < numPurchased; i++)
		{
			do
			{
				cout << "Item " << i + 1 << ": ";
				cin >> index;
			} while (index < 1 || index > item_count);

			cout << "Quantity: "; 
			cin >> quantity[index - 1];
		}

		cout << endl;
		cout << "RECEIPT" << endl;
		for (int i = 0; i < numPurchased; i++)
		{
			if (quantity[i] != 0)
			cout << items[i] << "        " << prices[i] << "        " << quantity[i] << "        " << quantity[i] * prices[i] << endl;
		}
		cout << endl;
	}
};

int main ()
{
	SShop sshop;
	char tmp;
	int flag = 0;

	cout << endl;
	while (1)
	{
		cout << "1. Add Items" << endl	<< "2. List Items" << endl << "3. Change Price" << endl << "4. View All" << endl << "5. Print Receipt" << endl << "press 'q' to quit" << endl;
		cin >> tmp;
		switch (tmp)
		{
			case '1':
				sshop.addProduct();
				break;
			case '2':
				sshop.printItems();
				break;
			case '3':
				sshop.changePrice();
				break;
			case '4':
				sshop.displayAll();
				break;
			case '5':
				sshop.printReceipt();
				break;
			case 'q':
				flag = 1;
				break;
			default:
				break;
		}

		if (flag)
			break;
	}
}
