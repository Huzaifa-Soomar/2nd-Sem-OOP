#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 5;
const int MAX_MENU_ITEMS = 10;
const int MAX_ORDER_ITEMS = 10;
const int MAX_FEEDBACK = 10;

class Menu {
public:
    string items[MAX_MENU_ITEMS] = {
        "Burger", "Pizza", "Pasta", "Salad", "Fries",
        "Soda", "Steak", "Soup", "Ice Cream", "Coffee"
    };
    float prices[MAX_MENU_ITEMS] = {
        5.99, 8.99, 6.49, 4.99, 2.99,
        1.99, 12.99, 3.99, 2.49, 1.49
    };

    void display() {
        cout << "\n--- Menu ---\n";
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    string getItem(int index) {
        if (index >= 0 && index < MAX_MENU_ITEMS)
            return items[index];
        return "";
    }
};

class Order {
public:
    string orderedItems[MAX_ORDER_ITEMS];
    int count = 0;

    void addItem(string item) {
        if (count < MAX_ORDER_ITEMS) {
            orderedItems[count++] = item;
            cout << "Added: " << item << endl;
        } else {
            cout << "Order is full.\n";
        }
    }

    void viewOrder() {
        cout << "\nYour Order:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << orderedItems[i] << endl;
        }
    }
};

class Feedback {
public:
    string entries[MAX_FEEDBACK];
    int count = 0;

    void addFeedback(string text) {
        if (count < MAX_FEEDBACK) {
            entries[count++] = text;
            cout << "Feedback submitted.\n";
        } else {
            cout << "Feedback list full.\n";
        }
    }

    void viewFeedbacks() {
        cout << "\n--- All Feedbacks ---\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << entries[i] << endl;
        }
    }
};

class LoyaltyProgram {
public:
    int points = 0;

    void earn(int p) {
        points += p;
        cout << "You earned " << p << " points.\n";
    }

    void redeem() {
        if (points >= 10) {
            points -= 10;
            cout << "You redeemed 10 points.\n";
        } else {
            cout << "Not enough points to redeem.\n";
        }
    }

    void showPoints() {
        cout << "You have " << points << " points.\n";
    }
};

class Payment {
public:
    float total = 0;

    void calculateTotal(Order order, Menu menu) {
        total = 0;
        for (int i = 0; i < order.count; i++) {
            for (int j = 0; j < MAX_MENU_ITEMS; j++) {
                if (order.orderedItems[i] == menu.items[j]) {
                    total += menu.prices[j];
                    break;
                }
            }
        }
    }

    void pay(string method) {
        if (method == "cash" || method == "card") {
            cout << "\n--- Receipt ---\n";
            cout << "Paid: $" << total << endl;
            cout << "Method: " << method << endl;
            cout << "Thank you for your payment!\n";
        } else {
            cout << "Invalid payment method.\n";
        }
    }
};

class User {
public:
    string name;
    virtual void showOptions() = 0;
};

class Client : public User {
    Menu* menu;
    Order order;
    Feedback* feedbackSystem;
    LoyaltyProgram loyalty;
    Payment payment;
public:
    Client(Menu* m, Feedback* fb, string clientName) {
        menu = m;
        feedbackSystem = fb;
        name = clientName;
    }

    void showOptions() override {
        int choice;
        do {
            cout << "\n--- Client Menu (" << name << ") ---\n";
            cout << "1. View Menu\n2. Place Order\n3. View Order\n4. Give Feedback\n";
            cout << "5. Earn Points\n6. Redeem Points\n7. Show Points\n8. Pay Bill\n0. Logout\nChoice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    menu->display();
                    break;
                case 2: {
                    menu->display();
                    int itemNo;
                    cout << "Enter item number to order: ";
                    cin >> itemNo;
                    order.addItem(menu->getItem(itemNo - 1));
                    loyalty.earn(5);
                    break;
                }
                case 3:
                    order.viewOrder();
                    break;
                case 4: {
                    string fb;
                    cin.ignore();
                    cout << "Enter your feedback: ";
                    getline(cin, fb);
                    feedbackSystem->addFeedback(fb);
                    break;
                }
                case 5:
                    loyalty.earn(5);
                    break;
                case 6:
                    loyalty.redeem();
                    break;
                case 7:
                    loyalty.showPoints();
                    break;
                case 8: {
                    payment.calculateTotal(order, *menu);
                    string method;
                    cout << "Enter payment method (cash/card): ";
                    cin >> method;
                    payment.pay(method);
                    break;
                }
                case 0:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    Menu menu;
    Feedback feedbackSystem;
    Client* clients[MAX_USERS];
    int clientCount = 0;

    int choice;
    do {
        cout << "\n--- Welcome to Restaurant System ---\n";
        cout << "1. Login as Client\n2. View Feedbacks (Owner View)\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            if (clientCount < MAX_USERS) {
                string cname;
                cout << "Enter your name: ";
                cin >> cname;
                clients[clientCount] = new Client(&menu, &feedbackSystem, cname);
                clients[clientCount]->showOptions();
                clientCount++;
            } else {
                cout << "Maximum clients reached.\n";
            }
        } else if (choice == 2) {
            feedbackSystem.viewFeedbacks();
        }

    } while (choice != 0);

    for (int i = 0; i < clientCount; i++) {
        delete clients[i];
    }

    return 0;
}
