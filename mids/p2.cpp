#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
protected:
    string name;
    double unitPrice;

public:
    // 🔹 Virtual Functions
    virtual void input() {
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, name);

        do {
            cout << "Enter unit price (>0): ";
            cin >> unitPrice;
        } while (unitPrice <= 0);
    }

    virtual double totalCost() const = 0;

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Unit Price: " << unitPrice << endl;
        cout << "Total Cost: " << totalCost() << endl;
    }

    virtual ~InventoryItem() {} // 🔥 virtual destructor
};

// 🔸 BulkItem
class BulkItem : public InventoryItem {
    int quantity;

public:
    void input() override {
        InventoryItem::input();

        do {
            cout << "Enter quantity (>0): ";
            cin >> quantity;
        } while (quantity <= 0);
    }

    double totalCost() const override {
        return unitPrice * quantity;
    }

    void display() const override {
        cout << "\n[Bulk Item]\n";
        InventoryItem::display();
        cout << "Quantity: " << quantity << endl;
    }
};

// 🔸 DiscountedItem
class DiscountedItem : public InventoryItem {
    double discountPercent;

public:
    void input() override {
        InventoryItem::input();

        do {
            cout << "Enter discount percent (0-100): ";
            cin >> discountPercent;
        } while (discountPercent < 0 || discountPercent > 100);
    }

    double totalCost() const override {
        return unitPrice * (1 - discountPercent / 100);
    }

    void display() const override {
        cout << "\n[Discounted Item]\n";
        InventoryItem::display();
        cout << "Discount: " << discountPercent << "%" << endl;
    }
};

// 🔸 ImportedItem
class ImportedItem : public InventoryItem {
    double importTaxPercent;

public:
    void input() override {
        InventoryItem::input();

        do {
            cout << "Enter import tax percent (0-100): ";
            cin >> importTaxPercent;
        } while (importTaxPercent < 0 || importTaxPercent > 100);
    }

    double totalCost() const override {
        return unitPrice * (1 + importTaxPercent / 100);
    }

    void display() const override {
        cout << "\n[Imported Item]\n";
        InventoryItem::display();
        cout << "Import Tax: " << importTaxPercent << "%" << endl;
    }
};

int main()
{
    int n;
    cout<<"ENTER NUMBER OF ITEMS:";
    cin>>n;

    InventoryItem **items=new InventoryItem*[n];

    for(int i=0;i<n;i++)
    {
        int choice;
        do{
               
            cout<<"1: BULK ITEMS"<<endl<<"2: DISCOUNTED ITEMS"<<endl<<"3:IMPORTED ITEMS"<<endl<<"4: EXIT"<<endl;
            cout<<"ENTER CHOICE";
            cin>>choice;
            switch (choice)
            {
                case 1: {items[i]=new BulkItem();} break;
                case 2: {items[i]=new DiscountedItem();} break;
                case 3: {items[i]=new ImportedItem();} break;
                case 4: {cout<<"EXITING....."<<endl;}  break;
                default: {cout<<"INCORRECT INPUT!"<<endl;}
            }
        }while(choice < 1 || choice >4);

        if(choice ==4)
        {
            break;
        }
    }

    cout<<"=====RECORD INFO OF INVENTORY ITEMS====="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER DATA OF ITEM:"<<i<<"="<<endl;
        items[i]->input();
    }
    cout<<"=====DISPLAYING INVENTORY ITEMS====="<<endl;
    for(int i=0;i<n;i++)
    {
        items[i]->display();
    }

 double grandtotal=0;

 for(int i=0;i<n;i++)
{
    grandtotal+=items[i]->totalCost();
}
cout<<"GRAND TOTAL IS:"<<grandtotal;

for(int i=0;i<n;i++)
{
    delete items[i];
}

delete[] items;
return 0;
}