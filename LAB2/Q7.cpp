#include <iostream>
#include <stdlib.h>

#define MAX_PRODUCTS 50

using namespace std;

typedef struct
{
	string name;
	float price;
	int ID, quantity;
} Product;

void addProduct (Product &product, int ID)
{
	cout << "Name: ";
	cin >> product.name;
	product.ID = ID;
	cout << "ID: " << product.ID << endl;
	cout << "Price: ";
	cin >> product.price;
	cout << "Quantity: ";
	cin >> product.quantity;
}

void displayByID (int ID, Product* productArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (ID == productArray[i].ID)
		{
			cout << endl << "Name: " << productArray[i].name << endl << "Price: " << productArray[i].price << endl << "Quantity: " << productArray[i].quantity << endl << endl;
			break;
		}

		if (i == arraySize - 1)
			cout << "NO SUCH PRODUCT" << endl;
	}
}

void updateByID (int ID, Product* productArray, int arraySize)
{
	cout << endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (ID == productArray[i].ID)
		{
			cout << "Name: ";
			cin >> productArray[i].name;
			cout << "ID: " << productArray[i].ID << endl;
			cout << "Price: ";
			cin >> productArray[i].price;
			cout << "Quantity: ";
			cin >> productArray[i].quantity;

			cout << "UPDATED" << endl;
			break;
		}
	}
}

void removeByID (int quantity, int ID, Product* productArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (ID == productArray[i].ID)
		{
			if (productArray[i].quantity < quantity)
			{
				cout << "NOT ENOUGH STOCK" << endl;
				break;
			}
			productArray[i].quantity -= quantity;
			cout << endl << quantity << " '" << productArray[i].name << "' " << "REMOVED FROM STOCK" << endl << endl;
		}
	}
}

int main ()
{
	int arraySize = 0, selection, quantity, ID;
	int flag = 0;

	Product* productArray = new Product [MAX_PRODUCTS];

	while (!flag)
	{
		cout << "1. Add Product" << endl << "2. Display Product" << endl << "3. Update Product" << endl << "4. Remove Product" << endl << "ANY OTHER KEY TO QUIT" << endl; 
		cin >> selection;
		
		switch (selection)
		{
			case 1:
				if (arraySize >= MAX_PRODUCTS)
				{
					cout << "LIMIT REACHED. CANNOT ADD MORE PRODUCTS";
					break;
				}
				++arraySize;
				addProduct(productArray[arraySize- 1], arraySize);
				break;
			case 2:
				if (arraySize == 0)
				{
					cout << "NO PRODUCTS IN INVENTORY" << endl;
					break;
				}
				cout << "ID: ";
				cin >> ID; 
				displayByID(ID, productArray, arraySize);
				break;
			case 3:
				cout << "ID: ";
				cin >> ID; 
				updateByID(ID, productArray, arraySize);
				break;
			case 4:
				cout << "ID: ";
				cin >> ID; 
				cout << "Quantity: ";
				cin >> quantity; 
				removeByID(quantity, ID, productArray, arraySize);
				break;
			default:
				flag = 1;
				break;
		}
	}
}
