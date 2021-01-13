#include <iostream>
#include<iomanip>
#include<ios>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Order
{
public:
    static int cart_inc;
   static int Order_Number;
   static int total_amount;
   static void new_order();
   static void order_inc();
   static void confirm_order();
   static void output_data();


};
class food_item
{
    public:
    int quantity;
    int price;
    string type;
    food_item(string b, int a){
        type=b;
        price=a;
    }

    void add_item(int a){
        quantity = quantity+a;
        Order::total_amount += this->price*a;
        Order::cart_inc++;
        }

    void remove_item(int a){
        quantity -= a;
        Order::total_amount -= this->price*a;
        Order::cart_inc--;

    }
};

class customer
{
private:
    string name;
    string surname;

    long long int mob_no;

friend class Order;
};

int Order::cart_inc=0;
void cart();
void remove_item();
void post_order();
int Order::total_amount=0;
void view_cart();
void reset();
void view_menu();
void add_item();
void doubleline();
void previous_orders();
void home();
void post_order_err();
void thank_you();
void cart_empty_err();
int Order::Order_Number=0;
int sr_no = 0;


customer newcustomer;

food_item item1(" Veg Manchurian    ", 100);
food_item item2(" Veg Fried Rice    ", 200);
food_item item3(" Veg Noodles       ", 250);
food_item item4(" Chicken Manchurian", 165);
food_item item5(" Chicken Fried Rice", 235);
food_item item6(" Chicken Noodles   ", 305);
food_item coke(" coke              ", 30);
food_item sprite(" sprite            ", 30);
food_item fanta(" fanta             ", 30);


int main()

{
    home();
  return 0;
}

void Order::new_order()
{




    system("CLS");

    Order od;

    int option;

    doubleline();

   cout<<"New Order No: "<<od.Order_Number<<endl;

   doubleline();



    cout<<"1. Add Item"<<endl<<"2. Remove Item"<<endl<<"3. View Cart"<<endl<<"4. Confirm Order"<<endl<<"5. Cancel Order"<<endl<<endl<<"Your Option ==>";
    cin>>option;

    switch(option){
    case 1:
        add_item();
        break;

    case 2:
        remove_item();
        break;
    case 3:
        view_cart();
        break;

    case 4:
        Order::confirm_order();
        break;

    case 5 :
        Order::Order_Number--;
        ofstream od_n1("order.txt");
        od_n1 << Order::Order_Number;
        od_n1.close();

        home();
    break;
    }
}




void view_menu(){
    int option;

    system("CLS");

    doubleline();

   cout<<"MENU"<<endl;

   doubleline();

    string myText;
    ifstream menu("menu.txt");

    while(getline (menu, myText)){
        cout << myText<<endl;
    }
    menu.close();

    cout<<"Press 0 to exit"<<endl<<"Press 1 to Go back"<<endl<<"==>";
    cin>>option;

    switch(option){
    case 1:
        home();
        break;
    case 0:
        exit(0);
           }
}
void previous_orders(){
    int option;

    system("CLS");

    doubleline();

   cout<<"View Previous Orders"<<endl;

   doubleline();

    string myText;
    ifstream pre("previous.txt");

    while(getline (pre, myText)){
        cout << myText<<endl;
    }
    pre.close();

    cout<<"Press 0 to exit"<<endl<<"Press 1 to Go back"<<endl<<"==>";
    cin>>option;

    switch(option){
    case 1:
        home();
        break;
    case 0:
        exit(0);
           }
}

void reset(){
      ofstream od_n1("order.txt");
    od_n1 << 0;
    Order::Order_Number = 0;
    od_n1.close();

    ofstream pre("previous.txt");
    pre.clear();
    pre.close();

    home();
}
void add_item(){
    int option, qty;

     system("CLS");

    doubleline();

   cout<<"Add Items"<<endl;

   doubleline();

    string myText;
    ifstream menu("menu.txt");

    while(getline (menu, myText)){
        cout << myText<<endl;
    }
    menu.close();

    doubleline();
    cout<<"Press 0 to go back"<<endl;
    cout<<"Please Select One Of The Above Items ==>";
    cin>>option;


    switch(option){
    case 0:
        Order::new_order();
        break;

    case 1:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        item1.add_item(qty);
        post_order();
        break;
    case 2:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        item2.add_item(qty);
        post_order();
        break;
    case 3:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;

        item3.add_item(qty);
        post_order();
        break;
    case 4:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        item4.add_item(qty);
        post_order();
        break;
    case 5:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        item5.add_item(qty);
        post_order();
        break;
    case 6:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        item6.add_item(qty);
        post_order();
        break;
    case 7:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        coke.add_item(qty);
        post_order();
        break;
    case 8:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        sprite.add_item(qty);
        post_order();
        break;
    case 9:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
        fanta.add_item(qty);
        post_order();
        break;
    default :
        Order::new_order();
    }


}
void post_order(){
    int option;

     system("cls");
    doubleline();
    cout<<"Cart Successfully modified"<<endl;
    doubleline();

    cout<<"Press 1 to add more items, 0 to previous page ==>";
    cin>>option;

    switch(option){
    case 1:
        add_item();
        break;
    case 0:
        Order::new_order();
        break;

    default:
        Order::new_order();
        break;
    }
}
void view_cart(){
    int option;


    system("CLS");

    doubleline();

   cout<<"Your Cart"<<endl;

   doubleline();

   cart();

   cout<<"Press 1 to Confirm Order, 0 to go back==>";
   cin>>option;

   switch(option){
   case 1:
        Order::confirm_order();
   case 0:
       Order::new_order();
   }
}
void Order::order_inc(){
    ifstream od_n("order.txt");
    od_n>>Order::Order_Number;
    Order::Order_Number++;
    od_n.close();



}

void remove_item(){
    int option, qty;

     system("CLS");

    doubleline();

   cout<<"Remove Item"<<endl;

   doubleline();

    string myText;
    ifstream menu("menu.txt");

    while(getline (menu, myText)){
        cout << myText<<endl;
    }
    menu.close();

    doubleline();
    cout<<"Press 0 to go back"<<endl;
    cout<<"Please Select One Of The Above Items ==>";
    cin>>option;


    switch(option){
    case 0:
        Order::new_order();
        break;

    case 1:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item1.quantity){
        item1.remove_item(qty);
        post_order();}
    else
        post_order_err();
        break;

    case 2:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item2.quantity){
        item2.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;

    case 3:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item3.quantity){
        item3.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;
    case 4:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item4.quantity){
        item4.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;
    case 5:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item5.quantity){
        item5.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;
    case 6:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=item6.quantity){
        item6.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;
    case 7:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=coke.quantity){
        coke.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;

    case 8:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=sprite.quantity){
        sprite.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;

    case 9:
        cout<<endl<<"Please Enter The Quantity==>";
    cin>>qty;
    if(qty<=sprite.quantity){
        sprite.remove_item(qty);
        post_order();}
            else
        post_order_err();
        break;

    default :

        post_order_err();
        break;
    }

}
void Order::confirm_order()
{
    int op;


    system("cls");
    doubleline();
    cout<<"Confirm Your Order"<<endl;
    doubleline();

    if(cart_inc<=0)
        {
            cart_empty_err();
            Order::new_order();
        }
    else
        {
    cout<<endl<<"Enter Customer Name: ";
    cin>>newcustomer.name>>newcustomer.surname;


    cout<<endl<<"Enter Mobile No: ";
    cin>>newcustomer.mob_no;

    system("cls");

    doubleline();
    cout<<"Confirm Your Order"<<endl;
    doubleline();
    cout<<"You are about to purchase the following:"<<endl;
    doubleline();

    cart();
    cout<<endl<<"Press 1 to confirm, 0 to go back ==>";
    cin>>op;

    switch(op)
    {
    case 1:

    output_data();
    thank_you();

    break;

    case 2:

        Order::new_order();
        break;
    default:

    Order::new_order();
    }
        }
}


void cart(){
    sr_no =0;
    cout<<"Sr.no"<<"  Item Name       "<<"Qty"<<"  Price"<<endl;
    doubleline();
     if(item1.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item1.type<<" x"<<item1.quantity<< " Rs. "<<item1.quantity*item1.price<<endl;
   }
    if(item2.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item2.type<<" x"<<item2.quantity<< " Rs. "<<item2.quantity*item2.price<<endl;
   }
   if(item3.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item3.type<<" x"<<item3.quantity<< " Rs. "<<item3.quantity*item3.price<<endl;
   }
   if(item4.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item4.type<<" x"<<item4.quantity<< " Rs. "<<item4.quantity*item4.price<<endl;
   }
   if(item5.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item5.type<<" x"<<item5.quantity<< " Rs. "<<item5.quantity*item5.price<<endl;
   }
   if(item6.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< item6.type<<" x"<<item6.quantity<< " Rs. "<<item6.quantity*item6.price<<endl;
   }
    if(coke.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< coke.type<<" x"<<coke.quantity<< " Rs. "<<coke.quantity*coke.price<<endl;
   }
   if(sprite.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< sprite.type<<" x"<<sprite.quantity<< " Rs. "<<sprite.quantity*sprite.price<<endl;
   }
   if(fanta.quantity >0)
   {
       sr_no++;
    cout<<sr_no<<".  "<< fanta.type<<" x"<<fanta.quantity<< " Rs. "<<fanta.quantity*fanta.price<<endl;
   }
   doubleline();

   cout<<"              Total Amount: Rs "<< Order::total_amount<<endl;

   doubleline();

}
void doubleline(){
    int i;
    for(i=1; i<=80; i++){
        cout<<"=";
    }
    cout<<endl;
}
void home(){
    system("CLS");
   int option;

   doubleline();

   cout<<"Welcome to China House"<<endl;

   doubleline();

   cout<<"1. New Order"<<endl<<"2. View Menu"<<endl<<"3. View Previous Orders"<<endl<<"4. Exit"<<endl<<"5. Reset"<<endl<<"Your Option ==>";
   cin>>option;


    switch(option){
        case 1 :
            Order::order_inc();
            Order::new_order();
        break;

        case 2 :
            view_menu();
            break;
        case 3:
            previous_orders();
            break;

        case 4 :
            exit(0);
            break;
        case 5:
            reset();
    }
}
void post_order_err(){
    int option;

     system("cls");
    doubleline();
    cout<<"An Error has Occurred while modifying your Cart"<<endl;
    doubleline();

    cout<<"Press 1 to add more items, 0 to previous page ==>";
    cin>>option;

    switch(option){
    case 1:
        add_item();
        break;
    case 0:
        Order::new_order();
        break;
    }
}
void thank_you()
{
    system("cls");
    cout<<endl;
    doubleline();
    cout<<"Thank You For Ordering From Us "<<endl;
    doubleline();
    cout<<"Press any button to exit ==>"<<endl;

}

void Order::output_data()
{
    ofstream od_n1("order.txt");
    od_n1 << Order::Order_Number;
    od_n1.close();

    ofstream pre("previous.txt", ios::app);
    pre<<endl;

    pre<<"==============================================="<<endl;
    pre<<"Order Number: "<<Order::Order_Number<<endl;
    pre<<"Customer name: "<< newcustomer.name <<" "<<newcustomer.surname<<endl<< "Mobile no: "<< newcustomer.mob_no<<endl;

    pre<<"==============================================="<<endl;

    pre<<"Sr.no"<<"  Item Name       "<<"Qty"<<"  Price"<<endl;
     pre<<"==============================================="<<endl;
     sr_no = 0;
     if(item1.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item1.type<<" x"<<item1.quantity<< " Rs. "<<item1.quantity*item1.price<<endl;
   }
    if(item2.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item2.type<<" x"<<item2.quantity<< " Rs. "<<item2.quantity*item2.price<<endl;
   }
   if(item3.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item3.type<<" x"<<item3.quantity<< " Rs. "<<item3.quantity*item3.price<<endl;
   }
   if(item4.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item4.type<<" x"<<item4.quantity<< " Rs. "<<item4.quantity*item4.price<<endl;
   }
   if(item5.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item5.type<<" x"<<item5.quantity<< " Rs. "<<item5.quantity*item5.price<<endl;
   }
   if(item6.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< item6.type<<" x"<<item6.quantity<< " Rs. "<<item6.quantity*item6.price<<endl;
   }
    if(coke.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< coke.type<<" x"<<coke.quantity<< " Rs. "<<coke.quantity*coke.price<<endl;
   }
   if(sprite.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< sprite.type<<" x"<<sprite.quantity<< " Rs. "<<sprite.quantity*sprite.price<<endl;
   }
   if(fanta.quantity >0)
   {
       sr_no++;
    pre<<sr_no<<".  "<< fanta.type<<" x"<<fanta.quantity<< " Rs. "<<fanta.quantity*fanta.price<<endl;
   }
   pre<<"==============================================="<<endl;

    pre<<"              Total Amount: Rs "<< Order::total_amount<<endl;


     pre<<"==============================================="<<endl;

    pre.close();
}
void cart_empty_err()
{
    char a;
    cout<<"Error Your Cart is Empty"<<endl;
    doubleline();
    cout<<"Please press any key to go back"<<endl;
    cin>>a;
}
