#include <iostream>
using namespace std;

struct Pizza
{
    string name;
    string size;
    double price;
};

struct Order
{
    Pizza pizza[10];
    int numPizzas = 0;
};

void displayPizza(Pizza pizza){
    cout << pizza.size << " " << pizza.name << ": $" << to_string(pizza.price) << endl;
}

void addPizza(Order& order, Pizza pizza){
    if(order.numPizzas >= 10){
        cout << "Unable to add pizza as order is full." << endl;
    }else{
        order.pizza[order.numPizzas] = pizza;
        order.numPizzas = order.numPizzas + 1;
    }
}

double calculateTotal(Order order){
    double total = 0;
    for(int i = 0; i < order.numPizzas; i++){
        total += order.pizza[i].price;
    }
    return total;
}

void displayOrder(Order order){
    for(int i = 0; i < order.numPizzas; i++){
        displayPizza(order.pizza[i]);
    }
    cout << "The total for this order is: $" << calculateTotal(order) << endl;
}

int main(){
    Pizza pizza1;
    pizza1.name = "a pizza 1";
    pizza1.size = "medium";
    pizza1.price = 14.90;
    Pizza pizza2;
    pizza2.name = "a pizza 2";
    pizza2.size = "large";
    pizza2.price = 18.90;
    Pizza pizza3;
    pizza3.name = "a pizza 3";
    pizza3.size = "small";
    pizza3.price = 10.90;
    Order myOrder;
    addPizza(myOrder, pizza1);
    addPizza(myOrder, pizza2);
    addPizza(myOrder, pizza3);
    cout << myOrder.numPizzas << endl;;
    displayOrder(myOrder);
}