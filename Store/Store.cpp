// Store.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>





using namespace std;

class Authorization {
    string userName;
    string password;

public:
    Authorization(string p, string u) {
        userName = u;
        password = p;
    };
    string getPassword() { return password; };
    string getUserName() { return userName; };
    bool checkLogIn(string username, string password) {

        if (username == "userAd" && password == "12345") {
            return true;
        }
        else
            return false;
    }
  

};


class Product {
protected:
    string name;
    double price;
    string description;
    string model;
public:
    Product(string name, double price, string description, string model) {
        this->name = name;
        this->price = price;
        this->description = description;
        this->model = model;
    }
    string getName() { return name; };
    string getDescription() { return description; };
    string getModel() { return model; };
    double getprice() { return price; };
    void setPrice(double price) {
        this->price = price;
    };
    void setName(string name) {
        this->name = name;
    };
    void setDescription(string description) {
        this->description = description;
    };
    void setModel(string model) {
        this->model = model;
    };
};

class Television : public Product {
private:
    string screenSize;
public:
    Television(string name, double price, string description, string model, string screenSize) : Product(name, price, description, model) {
        this->screenSize = screenSize;
    }
    string getScreenSize() { return screenSize; };
};

class StoreProducts {
    Product** products;
    int numberOfProd;
    int maxNumOfProd;
public:
    StoreProducts() {
        products = NULL;
        numberOfProd = 0;
        maxNumOfProd = 0;
    };
    ~StoreProducts() {
        for (int i = 0; i < numberOfProd; i++) {
            delete products[i];
        }
        delete[] products;
    };


    void addItem(const Product& product) {
        if(numberOfProd == maxNumOfProd){
            int newMax = 0;
            if (maxNumOfProd == 0) {
                newMax += 1;
            }
            else {
                newMax = maxNumOfProd * 2;
            }
            Product** newProducts = new Product * [newMax];
            for (int i = 0; i < numberOfProd; i++) {
                newProducts[i] = products[i];
            }
            delete[] products;
            products = newProducts;
            maxNumOfProd = newMax;
        }
        products[numberOfProd] = new Product(product);
        numberOfProd++;

    };
    void printProducts() const {
        for (int i = 0; i < numberOfProd; i++) {
            std::cout << products[i]-> getName() << " - $" << products[i]->getprice() << " - Quantity: " << products[i]->getDescription() << "\n";
        }
    }
    int getNumberOfProducts() const{
        return numberOfProd;
    }

    Product* getProduct(int index) const {
        if (index < 0 || index >= numberOfProd) {
            return NULL;
        }
        return products[index];
    }
};

bool saveProductsToFile(const StoreProducts& store) {
    ofstream file;
    file.open("storeItems.txt", ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in creating file.." << endl;
        return false;
    }
    int numOfProducts = store.getNumberOfProducts();
    for (int i = 0; i < numOfProducts; i++) {
        Product* temp = store.getProduct(i);
        file.write((char*)&temp, sizeof(temp));
    }
    file.close();
}


int main()
{
    string password, userName;
    cout << "User name:" << endl;
    cin >> userName;
    cout << "Password:" << endl;
    cin >> password;
    Authorization logIn(password, userName);

   /* if (logIn.checkLogIn(userName, password) == true) {
        cout << "Login was successful!";
    } else{
        cout << "Wrong password or username! Try again!";
    }*/

    Product first("TV", 12.50, "Good", "Samsung");
    first.setPrice(15);
    cout << "name: " << first.getName() << endl << "price: " << first.getprice() << endl << "Description: " << first.getDescription() << endl << "Model: " << first.getModel() << endl;
    Television TV("js", 17, "Amazing", "Samsung", "16x13");
    first.setPrice(20);
    cout << "name: " << TV.getScreenSize() << endl;
    first.getModel();
    first.getDescription();
    first.getName();
    first.getprice();
    //cout << "User name: " << logIn.getUserName() << endl << "Password: " << logIn.getPassword() << endl;

    StoreProducts store;
   /* std::cout << "How many products do you want to add? ";
    int numProducts;
    std::cin >> numProducts;

    for (int i = 0; i < numProducts; i++) {
        string name;
        double price;
        string description;
        string model;
        std::cout << "Enter the name of " << i+1 << " product " << ": ";
        std::cin >> name;

        std::cout << "Enter the price of " << i + 1 << " product " <<  ": ";
        std::cin >> price;

        std::cout << "Enter the quantity of " << i + 1 << " product " << ": ";
        std::cin >> description;
        first.setPrice(price);
        first.setDescription(description);
        first.setName(name);
        store.addItem(first);
    }
    store.printProducts();*/

    
}

