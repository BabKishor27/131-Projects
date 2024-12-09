// Name: Bobby Kishor
// CWID: 884491341

#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

template <typename T> class Item{ 
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
/* Item class template decides the properties of a particular item. It has four properties: name, expiration, category, quantity. 
Inventory - Inventory function will take care of all the operations. Inventory class will have one vector which will store objects of Item. */

template<typename T> class Inventory{ // class Inventory's type is the previous template above so we can have any type for the 3 parameters
    public:
        // Write Your code 
        std::vector<Item<T>> invent;
        /* TO DO: #1
        Add New Item: Write a function addNewItem() which will add a new Item in your vector. While adding a new element in the vector, check
        whether it already exists in the vector or not. If it exists in a vector, then display the message as “Item is already present in inventory”.*/
        void addNewItem(const Item<T>& item_){
            for(const Item<T>& present: invent) {
                if(present.name == item_.name) {
                    std::cout << "Item is already present in inventory." << '\n';
                }
            }
            invent.push_back(item_);
        }

        /* TO DO: #2
        Increase Quantity: Write a function increaseQuantity() to increase the quantity of the item by the newly provided quantity. It will 
        take two parameters: itemname and quantity.
        EXAMPLE: i1.increaseQuantity("Cerels",10);*/
        void increaseQuantity(const T item_name, int quantity){
            for(Item<T>& item : invent) {
                if(item.name == item_name) {
                    item.quantity = item.quantity + quantity;
                }
            }
        }

        /* TO DO: #3
        Update Item: Write a function updateItem() which will update the quantity, expiration and category. updateItem() will take
        four parameters: itemname, expiration, quantity and category. It should search the item from the name and update the item with 
        given parameters. We can only update the items that are already present in inventory. If time is not found throw an exception “Item not found”.*/
        void updateItem(const T& item_name, const T& expiration, const T& category,int quantity){
            for(Item<T>& item : invent){
                if(item.name == item_name) {
                    item.expiration = expiration;
                    item.quantity = quantity;
                    item.category = category;
                    return;
                }
            }
            throw "Item not found";
        }

        /* TO DO: #4
        Remove Item : Write a function removeItem() which will remove a particular item from the vector on the name of item. The function
        removeItem() takes a parameter as itemname. If an item is not in an inventory and you are trying to remove it from inventory,
        it will throw an exception “Item not found”.  
        EXAMPLE: i1.removeItem("Milk");*/
        void removeItem(const T& item_name){
            for(int i = 0; i < invent.size(); i++) {
                if(invent.at(i).name == item_name) {
                    invent.erase(invent.begin() + i);
                    return;
                }
            }
            throw "Item not found";
        }

        /* TO DO: #5
        Total: Write a function Total() to calculate the total number of items in inventory. */
        int Total()const {
            int total_quantity_items {0};
            for(const Item<T> item : invent) {
                total_quantity_items = total_quantity_items + item.quantity;
            }
            std::cout << "Total number of items in inventory = " << total_quantity_items << '\n';
            return total_quantity_items;
        }

        /* TO DO: #6
        Search Item: Write a function searchItem() to search a particular item in the inventory. The function searchItem() takes
        a parameter itemname and based on that it will find an item. If an item is not present it will throw an exception “Item not found!!”.
        */
        Item<T> searchItem(const T& item_name){
            for(const Item<T>& item : invent) {
                if(item.name == item_name) {
                    return item;
                }
            }
            throw "item not found!!";
        }

        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<invent.size();i++){
                std::cout<<std::left << std::setw(20)<<invent[i].name<<std::setw(15)<<invent[i].expiration<<std::setw(15)<<invent[i].quantity<<std::setw(15)<<invent[i].category<<std::endl;
            }
        }
};

/* Appointment- Appointment class template decides the properties of an appointment. It has four properties: name, ap_date, ap_time, CWID. 
AppointmentSystem - This class is responsible for all the operations. AppointmentSystem class will have one vector and it will store objects of Appointment. */
template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
        public:
        // Write Your code 
        std::vector<Appointment<T>> appointments;

        /* TO DO: #7
        Schedule: Write a function schedule() to schedule an appointment. It will store an appointment in a vector.
        If CWID is already present in a vector, then display the message that “You have already scheduled an appointment!!!”.
        It will store an object in a vector.
        */
        void schedule(const Appointment<T>& new_appoint) {
            for (const Appointment<T>& appointment : appointments) {
                if (appointment.CWID == new_appoint.CWID) {
                    std::cout << "You have already scheduled an appointment!!!" << '\n';
                    return; // Exit the function if duplicate CWID is found
                }
            }
            // Add the appointment only if no duplicates were found
            appointments.push_back(new_appoint);
        }


        /* TO DO: #8
        Total_appointments: Write a function Total_appointments() to calculate a total number appointments on a particular date and at
        a particular time. It will take two parameters: date and time.
        */
        int Total_appointments(const T& date, const T& time) {
            int total {0};
            for (const Appointment<T> appointment : appointments) {
                if (appointment.ap_date == date && appointment.ap_time == time) {
                    total++;
                }
            }
            std::cout << "Total appointments = " << total << '\n';
            return total;
        }

        /* TO DO: #9
        Remove recent:  Write a function removeRecent() to delete an appointment that is recently booked.  
        */
        void removeRecent(){
            if (appointments.size() > 0) {
                appointments.pop_back();
            } 
        }

        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<appointments.size();i++){
                std::cout<<std::left << std::setw(20)<<appointments[i].c_name<<std::setw(15)<<appointments[i].ap_date<<std::setw(15)<<appointments[i].ap_time<<std::setw(15)<<appointments[i].CWID<<std::endl;
            }
        }
};
int main(){
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
}