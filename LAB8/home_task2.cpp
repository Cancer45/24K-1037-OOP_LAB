#include <iostream>
#include <string>

using namespace std;

class Product
{
protected:
    string productID;
    double price;

public:
    Product(string id, double p) : productID(id), price(p) {}

    virtual double calculatePrice() = 0;

    void applyDiscount(double discount)
    {
        price -= price * (discount / 100);
    }

    void applyDiscount(double discount, bool isFixed)
    {
        if (isFixed)
        {
            price -= discount;
        }
        else
        {
            applyDiscount(discount);
        }
    }

    double getPrice()
    {
        return price;
    }
};

class Electronics : public Product
{
public:
    Electronics(string id, double p) : Product(id, p) {}

    double calculatePrice() override
    {
        return price + (price * 0.15); // 15% tax
    }
};

class Clothing : public Product
{
public:
    Clothing(string id, double p) : Product(id, p) {}

    double calculatePrice() override
    {
        return price + (price * 0.05); // 5% tax
    }
};

class ShoppingCart
{
    Product* products[10];
    int count = 0;

public:
    void addProduct(Product* p)
    {
        if (count < 10)
        {
            products[count++] = p;
        }
    }

    double calculateTotal()
    {
        double total = 0;
        for (int i = 0; i < count; ++i)
        {
            total += products[i]->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator+(const ShoppingCart& other)
    {
        ShoppingCart combined;
        for (int i = 0; i < count; ++i)
        {
            combined.addProduct(products[i]);
        }
        for (int i = 0; i < other.count; ++i)
        {
            combined.addProduct(other.products[i]);
        }
        return combined;
    }

    ShoppingCart operator-(const Product* p)
    {
        ShoppingCart newCart;
        for (int i = 0; i < count; ++i)
        {
            if (products[i] != p)
            {
                newCart.addProduct(products[i]);
            }
        }
        return newCart;
    }

    ShoppingCart operator*(double discount)
    {
        ShoppingCart discountedCart;
        for (int i = 0; i < count; ++i)
        {
            products[i]->applyDiscount(discount);
            discountedCart.addProduct(products[i]);
        }
        return discountedCart;
    }

    ShoppingCart operator/(int users)
    {
        ShoppingCart splitCart;
        double total = calculateTotal();
        double splitAmount = total / users;
        for (int i = 0; i < count; ++i)
        {
            products[i]->applyDiscount(splitAmount);
            splitCart.addProduct(products[i]);
        }
        return splitCart;
    }
};

int main()
{
    Electronics e1("E001", 500);
    Clothing c1("C001", 100);
    ShoppingCart cart;

    cart.addProduct(&e1);
    cart.addProduct(&c1);

    e1.applyDiscount(10); // 10% discount on electronics
    c1.applyDiscount(20, true); // $20 off on clothing

    cout << "Total price after discounts: " << cart.calculateTotal() << endl;

    ShoppingCart newCart = cart * 5; // Bulk discount
    cout << "Price after bulk discount: " << newCart.calculateTotal() << endl;

    ShoppingCart combinedCart = cart + newCart; // Adding two carts
    cout << "Combined Cart Total: " << combinedCart.calculateTotal() << endl;

    ShoppingCart finalCart = combinedCart - &e1; // Remove one product (electronics)
    cout << "Final Cart Total: " << finalCart.calculateTotal() << endl;

    return 0;
}