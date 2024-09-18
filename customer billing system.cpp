#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;
class Item {
public:
    string id, name, cat;
    double price, disc, vat;
    Item(string id, string name, double price, double disc, double vat, string cat)
        : id(id), name(name), price(price), disc(disc), vat(vat), cat(cat) {}
    double calcPrice(int qty) const {
        double discPrice = price - (price * disc / 100);
        double finalPrice = discPrice + (discPrice * vat / 100);
        return finalPrice * qty;
    }
};
class Buyer {
public:
    string name, phone, email;
    Buyer(string name, string phone, string email) : name(name), phone(phone), email(email) {}
};

class Bill {
private:
    Buyer buyer;
    vector<Item> items;
    vector<pair<Item, int>> cart;
    double total = 0;
    int itemCount = 0;
public:
    Bill(Buyer b) : buyer(b) {
        loadItems();
    }
    void loadItems()
    {
        items.push_back(Item("1","Sunsilk Shampoo(375ml)",290.00,25,2.5,"Grocery"));
        items.push_back(Item("2","Tata Salt(1kg)",20.00,5,1.0,"Grocery"));
        items.push_back(Item("3","Aashirvaad Atta(5kg)",300.00,15,5.0,"Grocery"));
        items.push_back(Item("4","Colgate Toothpaste(200g)",90.00,10,2.0,"Grocery"));
        items.push_back(Item("5","Lifebuoy Soap(4x125g)",120.00,20,3.0,"Grocery"));
        items.push_back(Item("6","Dettol Handwash(500ml)",180.00,10,2.5,"Grocery"));
        items.push_back(Item("7","Nescafe Coffee(200g)",350.00,25,7.0,"Grocery"));
        items.push_back(Item("8","Amul Butter(500g)",210.00,10,3.0,"Grocery"));
        items.push_back(Item("9","Maggi Noodles(12 Pack)",144.00,10,2.5,"Grocery"));
        items.push_back(Item("10","Dove Conditioner(340ml)",330.00,20,5.5,"Grocery"));
        
        items.push_back(Item("11","Sony 4K TV(55 inches)",74990.00,20,18.5,"Electronics"));
        items.push_back(Item("12","Apple iPhone 14 Pro(256GB)",129900.00,15,20.0,"Electronics"));
        items.push_back(Item("13","Dell XPS 13 Laptop",99990.00,20,18.5,"Electronics"));
        items.push_back(Item("14","Samsung Galaxy Tab S7",49999.00,18,12.5,"Electronics"));
        items.push_back(Item("15","Boat Airdopes 441",2499.00,25,5.0,"Electronics"));
        items.push_back(Item("16","Mi Smart Band 6",3499.00,20,7.0,"Electronics"));
        items.push_back(Item("17","Sony Headphones WH-1000XM4",24990.00,15,10.5,"Electronics"));
        items.push_back(Item("18","HP DeskJet 2331 Printer",4199.00,15,8.5,"Electronics"));
        items.push_back(Item("19","JBL Bluetooth Speaker",3999.00,18,6.5,"Electronics"));
        items.push_back(Item("20","Canon EOS 1500D DSLR",39999.00,20,12.0,"Electronics"));

        items.push_back(Item("21","Zara Men's Shirt",2999.00,30,10.5,"Fashion"));
        items.push_back(Item("22","Levi's Men's Jeans",3999.00,25,12.5,"Fashion"));
        items.push_back(Item("23","H&M Women's Top",1999.00,20,8.5,"Fashion"));
        items.push_back(Item("24","Ray-Ban Sunglasses",5999.00,15,15.0,"Fashion"));
        items.push_back(Item("25","Adidas Men's Shoes",4999.00,20,10.0,"Fashion"));
        items.push_back(Item("26","Nike Women's Running Shoes",5999.00,20,10.5,"Fashion"));
        items.push_back(Item("27","Zara Women's Skirt",2999.00,30,10.75,"Fashion"));
        items.push_back(Item("28","Levi's Denim Jacket",5999.00,25,12.5,"Fashion"));
        items.push_back(Item("29","H&M Men's Hoodie",2499.00,20,8.0,"Fashion"));
        items.push_back(Item("30","Woodland Leather Belt",1999.00,15,5.0,"Fashion"));

        items.push_back(Item("31","Ikea Dining Table",14999.00,20,10.0,"Home & Lifestyle"));
        items.push_back(Item("32","Sleepwell Mattress(Queen)",20999.00,25,15.5,"Home & Lifestyle"));
        items.push_back(Item("33","Philips LED Table Lamp",1999.00,20,5.5,"Home & Lifestyle"));
        items.push_back(Item("34","Urban Ladder Sofa",29999.00,30,12.5,"Home & Lifestyle"));
        items.push_back(Item("35","Godrej Almirah",19999.00,25,12.0,"Home & Lifestyle"));
        items.push_back(Item("36","Prestige Induction Cooktop",2999.00,20,8.5,"Home & Lifestyle"));
        items.push_back(Item("37","Borosil Glassware Set",1499.00,15,5.0,"Home & Lifestyle"));
        items.push_back(Item("38","Milton Thermosteel Bottle",899.00,10,2.0,"Home & Lifestyle"));
        items.push_back(Item("39","Usha Ceiling Fan",2499.00,18,6.0,"Home & Lifestyle"));
        items.push_back(Item("40","Godrej Security Safe",8999.00,25,10.0,"Home & Lifestyle"));

        items.push_back(Item("41","LG Washing Machine",24999.00,20,12.5,"Electronics"));
        items.push_back(Item("42","Whirlpool Refrigerator",32999.00,20,15.0,"Electronics"));
        items.push_back(Item("43","Panasonic Microwave Oven",9999.00,18,8.5,"Electronics"));
        items.push_back(Item("44","Bajaj Air Cooler",7999.00,15,6.0,"Electronics"));
        items.push_back(Item("45","Havells Water Purifier",12999.00,20,7.5,"Electronics"));
        items.push_back(Item("46","Sony Playstation 5",49990.00,10,15.0,"Electronics"));
        items.push_back(Item("47","Apple Watch Series 7",41990.00,10,12.5,"Electronics"));
        items.push_back(Item("48","Google Chromecast",3499.00,15,5.0,"Electronics"));
        items.push_back(Item("49","Amazon Echo Dot(4th Gen)",3499.00,20,5.5,"Electronics"));
        items.push_back(Item("50","Mi TV Stick",2799.00,18,4.0,"Electronics"));
    }
    void showCats() const {
        cout << "------------------- Categories -------------------\n";
        cout << "1. Grocery\n";
        cout << "2. Fashion\n";
        cout << "3. Personal Care\n";
        cout << "4. Home & Lifestyle\n";
        cout << "5. Sports\n";
        cout << "--------------------------------------------------\n";
    }
    string getCat(int choice) const {
        switch (choice) {
            case 1: return "Grocery";
            case 2: return "Fashion";
            case 3: return "Personal Care";
            case 4: return "Home & Lifestyle";
            case 5: return "Sports";
            default: return "Invalid";
        }
    }
    void showItemsByCat(const string& cat) const {
        cout << "----------------------------------------------------------------------------------------------------------------\n";
        cout << left << setw(8) << "CODE" << setw(40) << "ITEM" << setw(12) << "PRICE(Rs.)" << setw(10) << "DISC(%)" << setw(10) << "VAT(%)\n";
        cout << "----------------------------------------------------------------------------------------------------------------\n";
        for (const auto& i : items) {
            if (i.cat == cat) {
                cout << left << setw(8) << i.id << setw(40) << i.name << setw(12) << i.price << setw(10) << i.disc << setw(10) << i.vat << "\n";
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------\n";
    }
    void addToCart(const string& code, int qty) {
        for (const auto& i : items) {
            if (i.id == code) {
                cart.push_back(make_pair(i, qty));
                double itemAmt = i.calcPrice(qty);
                total += itemAmt;
                itemCount += qty;
                cout << "Added: " << i.name << " x" << qty << " -> Rs. " << fixed << setprecision(2) << itemAmt << "\n";
                return;
            }
        }
        cout << "Invalid Item Code!\n";
    }
    void showCart() const {
        cout << "\n------------------------- Cart -------------------------\n";
        cout << left << setw(40) << "Item" << setw(8) << "Qty" << setw(12) << "Price(Rs.)\n";
        cout << "-----------------------------------------------------------------------------------------------------------------\n";
        for (const auto& i : cart) {
            double itemAmt = i.first.calcPrice(i.second);
            cout << left << setw(40) << i.first.name << setw(8) << i.second << setw(12) << fixed << setprecision(2) << itemAmt << "\n";
        }
        cout << "--------------------------------------------------------\n";
        cout << "Total Items: " << itemCount << "\n";
        cout << "Total Amount: Rs. " << fixed << setprecision(2) << total << "\n";
    }
    void genReceipt() const {
        time_t now = time(0);
        char* dt = ctime(&now);
        ofstream receipt("receipt.txt");
        receipt << "==================================== BILL ====================================\n";
        receipt << "Date/Time: " << dt << "\n";
        receipt << "Buyer: " << buyer.name << "\n";
        receipt << "Phone: " << buyer.phone << "\n";
        receipt << "Email: " << buyer.email << "\n";
        receipt << "------------------------------------\n";
        receipt << left << setw(40) << "Item" << setw(8) << "Qty" << setw(12) << "Price(Rs.)\n";
        receipt << "------------------------------------\n";
        for (const auto& i : cart) {
            double itemAmt = i.first.calcPrice(i.second);
            receipt << left << setw(40) << i.first.name << setw(8) << i.second << setw(12) << fixed << setprecision(2) << itemAmt << "\n";
        }
        receipt << "------------------------------------\n";
        receipt << "Total Items: " << itemCount << "\n";
        receipt << "Total Amount: Rs. " << fixed << setprecision(2) << total << "\n";
        receipt << "Thank you for shopping with us!\n";
        receipt<< "==================================== END ====================================\n";
        receipt.close();
        cout << "Receipt generated successfully: receipt.txt\n";
    }
};
int main() {
    string name, phone, email;
    cout << "Enter Buyer Name: ";
    getline(cin, name);
    cout << "Enter Buyer Phone: ";
    getline(cin, phone);
    cout << "Enter Buyer Email: ";
    getline(cin, email);
    Buyer buyer(name, phone, email);
    Bill bill(buyer);
    int catChoice;
    while (true) {
        bill.showCats();
        cout << "Select a Category (1-5): ";
        cin >> catChoice;
        string cat = bill.getCat(catChoice);
        if (cat == "Invalid") {
            cout << "Invalid category selection! Please try again.\n";
            continue;
        }
        bill.showItemsByCat(cat);
        string itemCode;
        int qty;
        cout << "Enter Item Code (or 0 to finish): ";
        cin >> itemCode;
        if (itemCode == "0") {
            break;
        }
        cout << "Enter Quantity: ";
        cin >> qty;
        bill.addToCart(itemCode, qty);
    }
    bill.showCart();
    bill.genReceipt();
    return 0;
}
