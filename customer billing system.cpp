#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;
// Product class definition
class Product
{
public:
    string id,name,category;
    double price,discount,vat;
    Product(string id,string name,double price,double discount,double vat,string category)
        :id(id),name(name),price(price),discount(discount),vat(vat),category(category) {}
    double calculatePrice(int quantity) const
    {
        double discountedPrice=price-(price*discount/100);
        double finalPrice=discountedPrice+(discountedPrice*vat/100);
        return finalPrice*quantity;
    }
};
// Customer class definition
class Customer
{
public:
    string name,phone,email;
    Customer(string name,string phone,string email):name(name),phone(phone),email(email) {}
};
// Billing class definition
class Billing
{
private:
    Customer customer;
    vector<Product> products;
    vector<pair<Product,int>> cart;
    double totalAmount=0;
    int totalItems=0;
public:
    Billing(Customer cust):customer(cust)
    {
        loadProducts();
    }
    // Load all products
    void loadProducts()
    {
        // Grocery
        products.push_back(Product("1", "Sunsilk Shampoo (375ml)", 290.00, 25, 2.5, "Grocery"));
        products.push_back(Product("2", "Cadbury Silk Chocolates (60g)", 800.00, 20, 9, "Grocery"));
        products.push_back(Product("3", "Chings Instant Noodles (100gm)", 10.00, 0, 0.25, "Grocery"));
        products.push_back(Product("4", "Pillsbury Atta (5kg)", 249.00, 5, 1, "Grocery"));
        products.push_back(Product("5", "Tata Salt (1kg)", 25.00, 0, 0.5, "Grocery"));
        products.push_back(Product("6", "Nestle Maggi Noodles (Pack of 12)", 140.00, 2, 0.25, "Grocery"));
        products.push_back(Product("7", "Tropicana Orange Juice (1L)", 120.00, 10, 5.0, "Grocery"));
        products.push_back(Product("8", "Lays Classic Salted Chips (52g)", 20.00, 0, 0.75, "Grocery"));
        products.push_back(Product("9", "Amul Butter (500g)", 200.00, 5, 4.5, "Grocery"));
        products.push_back(Product("10", "Brooke Bond Red Label Tea (500g)", 150.00, 3, 2, "Grocery"));
        // Fashion
        products.push_back(Product("11", "V-Three Casual Bagpack", 745.00, 50, 10.5, "Fashion"));
        products.push_back(Product("12", "Adidas Men's T-Shirt", 275.00, 30, 7.25, "Fashion"));
        products.push_back(Product("13", "Sparx Men's Shoes", 8000.00, 18, 14, "Fashion"));
        products.push_back(Product("14", "Levi's Men's Jeans", 3299.00, 20, 12.5, "Fashion"));
        products.push_back(Product("15", "Allen Solly Women's Top", 1799.00, 25, 8.25, "Fashion"));
        products.push_back(Product("16", "Puma Sports Cap", 999.00, 15, 5.0, "Fashion"));
        products.push_back(Product("17", "Zara Women’s Skirt", 2999.00, 30, 10.75, "Fashion"));
        products.push_back(Product("18", "Nike Running Shoes", 6500.00, 20, 14.0, "Fashion"));
        products.push_back(Product("19", "Ray-Ban Sunglasses", 10999.00, 15, 12.25, "Fashion"));
        products.push_back(Product("20", "Fossil Leather Wallet", 3500.00, 10, 8.5, "Fashion"));
        // Personal Care
        products.push_back(Product("21", "Sensodyne Toothpaste (75ml)", 93.95, 2, 4.5, "Personal Care"));
        products.push_back(Product("22", "Pepsodent Toothbrush", 17.00, 4, 3, "Personal Care"));
        products.push_back(Product("23", "Nivea Body Lotion (400ml)", 349.00, 10, 6, "Personal Care"));
        products.push_back(Product("24", "Dettol Hand Wash (250ml)", 99.00, 5, 4, "Personal Care"));
        products.push_back(Product("25", "Garnier Face Wash (100ml)", 199.00, 8, 4.25, "Personal Care"));
        products.push_back(Product("26", "Dove Conditioner (180ml)", 299.00, 15, 6.75, "Personal Care"));
        products.push_back(Product("27", "L'Oréal Hair Serum (100ml)", 500.00, 12, 7, "Personal Care"));
        products.push_back(Product("28", "Vaseline Lip Therapy", 199.00, 5, 3.25, "Personal Care"));
        products.push_back(Product("29", "Himalaya Neem Face Wash (150ml)", 250.00, 10, 4.75, "Personal Care"));
        products.push_back(Product("30", "Old Spice Aftershave (100ml)", 150.00, 7, 5.5, "Personal Care"));
        // Home & Lifestyle
        products.push_back(Product("31", "Tupperware Bottle (750ml)", 999.00, 10, 9.3, "Home & Lifestyle"));
        products.push_back(Product("32", "Philips LED Bulb (Pack of 4)", 499.00, 12, 6.5, "Home & Lifestyle"));
        products.push_back(Product("33", "Pigeon Pressure Cooker (3L)", 1399.00, 20, 10.5, "Home & Lifestyle"));
        products.push_back(Product("34", "Borosil Glass Set (6 pieces)", 999.00, 15, 7.5, "Home & Lifestyle"));
        products.push_back(Product("35", "Nilkamal Plastic Chair", 499.00, 5, 4, "Home & Lifestyle"));
        products.push_back(Product("36", "Milton Thermosteel Flask (1L)", 699.00, 8, 7.25, "Home & Lifestyle"));
        products.push_back(Product("37", "Cello Non-Stick Frying Pan", 899.00, 15, 6.5, "Home & Lifestyle"));
        products.push_back(Product("38", "Puma Bedding Set (King Size)", 2499.00, 25, 11.75, "Home & Lifestyle"));
        products.push_back(Product("39", "Karcher Vacuum Cleaner", 9999.00, 18, 12.5, "Home & Lifestyle"));
        products.push_back(Product("40", "Godrej Wardrobe", 12500.00, 22, 15, "Home & Lifestyle"));
        // Sports
        products.push_back(Product("41", "Nivia Tennis Ball - Pack of 12", 810.00, 12, 8.75, "Sports"));
        products.push_back(Product("42", "Yonex Badminton Racket", 999.00, 15, 7.0, "Sports"));
        products.push_back(Product("43", "SG Cricket Bat", 4999.00, 20, 10.5, "Sports"));
        products.push_back(Product("44", "Adidas Football", 1499.00, 18, 12.25, "Sports"));
        products.push_back(Product("45", "Nike Basketball", 1399.00, 15, 9.5, "Sports"));
        products.push_back(Product("46", "Reebok Gym Gloves", 799.00, 10, 5.5, "Sports"));
        products.push_back(Product("47", "Cosco Volleyball", 999.00, 10, 7, "Sports"));
        products.push_back(Product("48", "SG Cricket Kit Bag", 2999.00, 15, 9.75, "Sports"));
        products.push_back(Product("49", "Puma Running Shoes", 5999.00, 20, 14.25, "Sports"));
        products.push_back(Product("50", "Spalding Tennis Racket", 799.00, 8, 6.0, "Sports"));
    }
    // Display categories
    void displayCategories() const
    {
        cout<<"------------------- Categories -------------------\n";
        cout<<"1. Grocery\n";
        cout<<"2. Fashion\n";
        cout<<"3. Personal Care\n";
        cout<<"4. Home & Lifestyle\n";
        cout<<"5. Sports\n";
        cout<<"--------------------------------------------------\n";
    }
    // Get category by choice
    string getCategoryByChoice(int choice) const
    {
        switch(choice)
        {
        case 1: return "Grocery";
        case 2: return "Fashion";
        case 3: return "Personal Care";
        case 4: return "Home & Lifestyle";
        case 5: return "Sports";
        default: return "Invalid";
        }
    }
    // Display products by category
    void displayProductsByCategory(const string& category) const {
        cout<<"----------------------------------------------------------------------------------------------------------------\n";
        cout<<"CODE\tPRODUCT\t\t\t\t\t\tPRICE(Rs.)\tDISCOUNT(%)\tVAT(%)\n";
        for(const auto& p:products)
        {
            if(p.category==category)
            {
                cout << p.id << "\t" << p.name << "\t\t" << p.price << "\t\t" << p.discount << "\t\t" << p.vat << "\n";
            }
        }
        cout << "----------------------------------------------------------------------------------------------------------------\n";
    }
    // Add product to cart
    void addToCart(const string& code,int quantity)
    {
        for(const auto& p:products)
        {
            if(p.id == code)
            {
                cart.push_back(make_pair(p,quantity));
                double itemAmount=p.calculatePrice(quantity);
                totalAmount+=itemAmount;
                totalItems+=quantity;
                cout<<"Added: "<<p.name<<" x"<<quantity<<" -> Rs. "<<fixed<<setprecision(2)<<itemAmount<<"\n";
                return;
            }
        }
        cout<<"Invalid Product Code!\n";
    }
    // Generate receipt and save to file
    void generateReceipt() const
    {
        time_t now=time(0);
        char* dt=ctime(&now);
        ofstream receiptFile("receipt.txt");
        receiptFile<<"\t\t\t\tSUPERMARKET\n";
        receiptFile<<"\t\t\t12-Padma Super Market\n";
        receiptFile<<"\t\t\tOld Necklace Road, Jubileehills - HYDERABAD\n";
        receiptFile<<"----------------------------------------------------------------------------------------------------------------\n";
        receiptFile<<"Date: " << dt;
        receiptFile<<"Customer: " << customer.name << "\tPhone: " << customer.phone << "\tEmail: " << customer.email << "\n";
        receiptFile<<"----------------------------------------------------------------------------------------------------------------\n";
        receiptFile<<"ITEM\t\tQUANTITY\tPRICE(Rs.)\n";
        receiptFile<<"----------------------------------------------------------------------------------------------------------------\n";
        for(const auto& item:cart)
        {
            receiptFile<<item.first.name<<"\t"<<item.second<<"\t"<<item.first.calculatePrice(item.second)<<"\n";
        }
        receiptFile << "----------------------------------------------------------------------------------------------------------------\n";
        receiptFile << "Total Items: " << totalItems << "\n";
        receiptFile << "Total Amount (Before Rounding): Rs. " << fixed << setprecision(2) << totalAmount << "\n";
        long roundedTotal = round(totalAmount);  // Ensure proper rounding with <cmath>
        receiptFile << "Total Amount (After Rounding): Rs. " << roundedTotal << "\n";
        receiptFile << "----------------------------------------------------------------------------------------------------------------\n";
        receiptFile << "\t** Thank you for shopping with us! **\n";
        receiptFile << "\tCustomer Care: 1800 133 6702\n";
        receiptFile << "----------------------------------------------------------------------------------------------------------------\n";
        receiptFile.close();
        cout << "\nReceipt generated and saved to 'receipt.txt'\n";
    }
    // Main billing process
    void billingProcess()
    {
        int categoryChoice;
        string category;
        while(true)
        {
            displayCategories();
            cout << "Enter category number (or '0' to finish): ";
            cin >> categoryChoice;
            if (categoryChoice == 0) break;
            category = getCategoryByChoice(categoryChoice);
            if (category == "Invalid")
            {
                cout << "Invalid category choice!\n";
                continue;
            }
            displayProductsByCategory(category);
            string code;
            int quantity;
            while(true)
            {
                cout << "Enter product code (or '#' to go back to categories): ";
                cin >> code;
                if (code == "#") break;
                cout << "Enter quantity: ";
                cin >> quantity;
                addToCart(code, quantity);
            }
        }
        generateReceipt();
    }
};
int main() {
    string customerName, customerPhone, customerEmail;
    cout << "Enter Customer Name: ";
    getline(cin, customerName);
    cout << "Enter Customer Phone: ";
    getline(cin, customerPhone);
    cout << "Enter Customer Email: ";
    getline(cin, customerEmail);
    Customer customer(customerName, customerPhone, customerEmail);
    Billing billing(customer);
    billing.billingProcess();
    return 0;
}
