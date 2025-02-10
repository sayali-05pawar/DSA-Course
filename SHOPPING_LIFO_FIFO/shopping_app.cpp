#include <iostream>
#include <string>
using namespace std;

// Constants for array limits
const int CART_LIMIT = 25;
const int QUEUE_LIMIT = 50;

// Class for Item details
class Item {
public:
    string itemName;
    int quantity;
    string type;
    float price;

    // Function to read item details
    void readItemDetails() {
        cout << "Enter type (e.g., Electronics, Grocery, etc.): ";
        cin >> type;
        cout << "Enter item name: ";
        cin >> itemName;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price per item: Rs.";
        cin >> price;
    }

    // Function to display item details
    void displayItemDetails() {
        cout << "Type: " << type << "\nItem: " << itemName << "\nQuantity: " << quantity
             << "\nPrice: Rs." << price << endl;
    }
};

// Stack for Shopping Cart
class ShoppingCart 
{
private:
    Item cart[CART_LIMIT];  // Array to hold Item objects
    int top;  // Index of the last item in the cart

public:
    ShoppingCart() {
        top = -1;  // Cart is initially empty
    }

    // Add item to cart (Push in Stack)
    void addItem() {
        if (top >= CART_LIMIT - 1) {
            cout << "Cart is full! Cannot add more items." << endl;
            return;
        }
        Item newItem;
        newItem.readItemDetails();
        cart[++top] = newItem;  // Add new item to cart
        cout << "Item added to cart!" << endl;
    }

    // Remove last item from cart (Pop in Stack)
    void removeLastItem() {
        if (top == -1) {
            cout << "Cart is empty, nothing to remove!" << endl;
        } else {
            cout << "Removed last item: " << cart[top].itemName << endl;
            top--;
        }
    }

    // View last added item (Peek in Stack)
    void displayLastItem() {
        if (top == -1) {
            cout << "Cart is empty!" << endl;
        } else {
            cout << "Last item in cart: " << endl;
            cart[top].displayItemDetails();
        }
    }

    // Check if cart is empty
    bool isCartEmpty() {
        return top == -1;
    }
};

// Queue for Order Delivery
class OrderQueue {
    Item queue[QUEUE_LIMIT];  // Change from string to Item array
    int front, rear;  // Front: dequeue, Rear: enqueue

public:
    OrderQueue() {
        front = rear = -1;  // Queue is initially empty
    }

    // Place an order (Enqueue in Queue)
    void placeOrder() {
        if (rear == QUEUE_LIMIT - 1) {
            cout << "Order queue is full! Cannot place more orders." << endl;
            return;
        }
        Item newOrder;
        newOrder.readItemDetails();
        if (front == -1) {
            front = 0;  // Queue was empty, reset front
        }
        queue[++rear] = newOrder;
        cout << "Order placed!" << endl;
    }

    // Process next order (Dequeue in Queue)
    void processOrder() {
        if (front == -1 || front > rear) {
            cout << "No orders to process!" << endl;
            front = rear = -1;  // Reset queue if it's empty
        } else {
            cout << "Processing order: " << endl;
            queue[front].displayItemDetails();
            front++;
        }
    }

    // View next order (Peek in Queue)
    void peekNextOrder() {
        if (front == -1 || front > rear) {
            cout << "No pending orders!" << endl;
        } else {
            cout << "Next order in queue: " << endl;
            queue[front].displayItemDetails();
        }
    }

    // Check if queue is empty
    bool isOrderQueueEmpty() {
        return front == -1 || front > rear;
    }

    // Display all orders in the queue
    void viewOrders() {
        if (front == -1 || front > rear) {
            cout << "No orders in the queue!" << endl;
        } else {
            cout << "Orders in queue:" << endl;
            for (int i = front; i <= rear; ++i) {
                queue[i].displayItemDetails();
                cout << "-----------------" << endl;
            }
        }
    }
};


int main() {
    ShoppingCart cart;
    OrderQueue orders;

    int choice;
    do {
        cout << "\n--- Shopping App Menu ---\n";
        cout << "1. Add Item to Cart\n";                       
        cout << "2. Remove Last Item from Cart\n";              
        cout << "3. View Last Item in Cart\n";                 
        cout << "4. Place Order\n";                             
        cout << "5. Process Next Order\n";                    
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
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}
