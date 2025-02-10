#include <iostream>
#include <string>
using namespace std;

// Node class for both Stack and Queue
class Node 
{
    private:
    string itemName;
    int quantity;
    string type;
    float price;
    
    public:
    Node* next;

    Node() {
        next = NULL;
    }

    // Method to read the order details
    void readData() {
        cout << "Enter type (e.g., Electronics, Grocery, etc.): ";
        cin >> type;
        cout << "Enter item name/order: ";
        cin >> itemName;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price per item: Rs.";
        cin >> price;
    }

    // Method to display the order details
    void displayData() {
        cout << "Type: " << type << "\nItem/Order: " << itemName << "\nQuantity: " << quantity
             << "\nPrice: Rs." << price << endl;
    }

    string get_item()
    {
        return itemName;
    }
};

// Stack for Shopping Cart
class ShoppingCart {
    Node* top;

public:
    ShoppingCart() {
        top = NULL;
    }

    ~ShoppingCart() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push (add item to cart)
    void addItem() {
        Node* newNode = new Node();
        newNode->readData();
        newNode->next = top;
        top = newNode;
        cout << "Item added to cart!" << endl;
    }

    // Pop (remove last added item from cart)
    void removeLastItem() {
        if (top == NULL) {
            cout << "Cart is empty, nothing to remove!" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            cout << "Removed last item: " << temp->get_item() << endl;
            delete temp;
        }
    }

    // Peek (view last added item in cart)
    void displayLastItem() {
        if (top == NULL) {
            cout << "Cart is empty!" << endl;
        } else {
            cout << "Last item in cart: " << endl;
            top->displayData();
        }
    }

    // Check if cart is empty
    bool isCartEmpty() {
        return top == NULL;
    }
};

// Queue for Order Delivery
class OrderQueue {
    Node* front;
    Node* rear;

public:
    OrderQueue() {
        front = rear = NULL;
    }

    ~OrderQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue (add order to queue)
    void placeOrder() {
        Node* newNode = new Node();
        newNode->readData();
        if (rear == NULL) { // Empty queue
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order placed!" << endl;
    }

    // Dequeue (process next order from queue)
    void processOrder() {
        if (front == NULL) {
            cout << "No orders to process!" << endl;
        } else {
            Node* temp = front;
            cout << "Processing order: " << endl;
            temp->displayData();
            front = front->next;
            if (front == NULL) { // Queue is now empty
                rear = NULL;
            }
            delete temp;
        }
    }

    // Peek (view next order in queue)
    void peekNextOrder() {
        if (front == NULL) {
            cout << "No pending orders!" << endl;
        } else {
            cout << "Next order in queue: " << endl;
            front->displayData();
        }
    }

    // Check if queue is empty
    bool isOrderQueueEmpty() {
        return front == NULL;
    }

    // Function to display all orders in the queue
    void viewOrders() {
        if (front == NULL) {
            cout << "No orders in the queue!" << endl;
        } else {
            Node* current = front;
            cout << "Orders in the queue:" << endl;
            while (current != NULL) {
                current->displayData();
                cout << "--------------------" << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    ShoppingCart cart;
    OrderQueue orders;

    int choice;
    while (1) {
        cout << "\n--- Shopping App Menu ---\n";
        cout << "1. Add Item to Cart\n";
        cout << "2. Remove Last Item from Cart\n";
        cout << "3. View Last Item in Cart\n";
        cout << "4. Place Order\n";
        cout << "5. Process Order\n";
        cout << "6. View Next Order\n";
        cout << "7. Check if Cart is Empty\n";
        cout << "8. Check if Orders are Pending\n";
        cout << "9. View All Orders in Queue\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cart.addItem();
                break;
            case 2:
                cart.removeLastItem();
                break;
            case 3:
                cart.displayLastItem();
                break;
            case 4:
                orders.placeOrder();
                break;
            case 5:
                orders.processOrder();
                break;
            case 6:
                orders.peekNextOrder();
                break;
            case 7:
                if (cart.isCartEmpty()) {
                    cout << "Cart is empty!" << endl;
                } else {
                    cout << "Cart is not empty!" << endl;
                }
                break;
            case 8:
                if (orders.isOrderQueueEmpty()) {
                    cout << "No pending orders!" << endl;
                } else {
                    cout << "Orders are pending!" << endl;
                }
                break;
            case 9:
                orders.viewOrders();
                break;
            case 10:
                cout << "Exiting app..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }

    return 0;
}
