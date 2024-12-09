// Name: Bobby Kishor
// CWID: 884491341

#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
/*Create a class Tab which represents the node and has three values: url, name, and memory. 
url (string) - represents url of website
Name (string) - represents name of a site
memory(Generalised type) - represents memory consumed by site
Also, it has two pointers next and prev. Create another class Browser which contains all the necessary functions in order to implement specified functions. 
You need to declare two more pointers head and tail to represent Browser as a doubly linked list. You can add additional pointers to implement the following functions
*/
template <typename T>
class Tab {
public:
    std::string url;
    std::string name;
    T memory;
    Tab *prev = nullptr;
    Tab *next = nullptr;
    Tab(const std::string& url_, const std::string& name_, const T& memory_)
        : url (url_), name (name_), memory (memory_) {} 
};

// Write template class Browser here
/*Create another class Browser which contains all the necessary functions in order to implement specified functions. 
You need to declare two more pointers head and tail to represent Browser as a doubly linked list. You can add additional pointers to implement the following functions
*/
template <typename T>
class Browser {
    Tab<T> *head;
    Tab<T> *tail;
    Tab<T> *current;

public:
    Browser() : head(nullptr), tail(nullptr), current(nullptr) {}
    std::vector<std::pair<std::string, std::string>> bookmark_;
//1. addNewTab() - This function takes three parameters- url, name and memory and creates a new tab. It will assign values to tab values and add it at the 
                    //last position of a linked list. Always remember the last tab will be the current tab.
    void addNewTab (const std::string& url, const std::string& name, const T& memory) {
        Tab<T> *NewTab = new Tab<T>(url, name, memory);
        if (!head) { //if list is empty
            head = NewTab;
            tail = NewTab;
        } else {
            tail->next = NewTab;
            NewTab->prev = tail;
            tail = NewTab;
        }
        current = NewTab;
    }
/*
2. switchToPrevTab() - This function switches the cursor from current tab to previous tab. If there is a previous tab, print the details of the tab like url,
                          name and memory. If there is no previous tab it should print a message that says  “No previous tab”. */
    void switchToPrevTab() {
        if (current && current->prev) {
            current = current->prev;
            std::cout << "Current Tab:" << '\n';
            std::cout << "Url: " << current->url << '\n';
            std::cout << "Name: " << current->name << '\n';
            std::cout << "Memory: " << current->memory << '\n';
        } else {
            std::cout << "No previous tab" <<'\n';
        }
    }

/*3. switchToNextTab() - This function switches the cursor from the current tab to the next tab. If the next tab is present then print details of the tab. 
                          If there is no previous tab it should print a message that says  “No next tab”. */ 
    void switchToNextTab() {
        if (current && current->next) {
            current = current->next;
            std::cout << "Current Tab:" << '\n';
            std::cout << "Url: " << current->url << '\n';
            std::cout << "Name: " << current->name << '\n';
            std::cout << "Memory: " << current->memory << '\n';
        } else {
            std::cout << "No next tab" << '\n';
        }
    }

/*4. closeCurrentTab()- It deletes the current tab from the browser. When you close the current tab the new current tab will be the next tab. 
                         Print the new current tab which is the next tab with a message “Now the current tab  = “ and current tab name.  */
    void closeCurrentTab() {
        if (current == nullptr) {
            std::cout << "No tab is open" << '\n';
            return;
        }
        Tab<T>* NewCurr = current->next;

        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }

        if (current == head) {
            head = current->next;
        } else if (current == tail) {
            tail = current->prev;
        }

        delete current;
        current = NewCurr;

        if (current) {
            std::cout << "Now the current tab = " << current->name << '\n';
        } else { //list is empty
            std::cout << "No more tabs" << '\n';
        }
    }

/*5. bookmarkCurrent()- It bookmarks the current tab and saves the pair(name,url) in the vector of pairs if the current tab is still present in Browser. 
                         Use std::pair to store pairs in the vector. Vector can be defined as -  "std::vector<std::pair<data types of elements>>" vector name
                         The repetition of bookmarks is not allowed, if a repetitive tab is trying to insert inside a vector it should give a message 
                         “The bookmark is already added!!” */
    void bookmarkCurrent() {
        if (current == nullptr) {
            std::cout << "No tab to bookmark" << '\n';
            return;
        }

        for (const auto& bookmark : bookmark_) {
            if (bookmark.first == current->name && bookmark.second == current->url) {
                std::cout << "The bookmark is already added!!" << '\n';
                return;
            }
        }

        bookmark_.push_back(std::make_pair(current->name, current->url));
    }

/*6. showBookmarkTab() - It will print all the bookmarks as follows: */ 
    void showBookmarkTab() {
        std::cout << "Bookmarks : " << '\n';
        for (const auto& bookmark : bookmark_) {
            std::cout << bookmark.first << "(" << bookmark.second << ")" << '\n';
        }
    }

/*7. moveCurrentToFirst() - If the current tab is still present in the browser, move it to first position.
                             Before function executed: */
    void moveCurrentToFirst() {
        if (current->next) {
            current->next->prev = current->prev;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }

        current->prev = nullptr;
        current->next = head;
        head->prev = current;
        head = current;

        if (current->next == nullptr) {
            tail = current;
        }
    }
 
/*8. total_memory() - It calculates the total memory consumed by the browser in total. It will return the memory consumption. */
    T total_memory() {
        T total {0};
        Tab<T> *temp = head;
        while (temp != nullptr) {
            total += temp->memory;
            temp = temp->next;
        }
        std::cout << "Total Memory Consumption = " << total << "MB" << '\n';
        return total;
    }

/*9. deleteTab() - It will delete the tab which is consuming the highest memory out of all the tabs. After deletion it will print the message and tab which is deleted
                with memory consumption. */
    void deleteTab() {
        Tab<T> *temp = head;
        Tab<T> *MaxTab = head;

        while (temp != nullptr) {
            if (temp->memory > MaxTab->memory) {
                MaxTab = temp;
            }
            temp = temp->next;
        }

        std::cout << "Deleted element = " << MaxTab->name << "with memory size = " << MaxTab->memory << '\n';

        if (MaxTab == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else if (MaxTab == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            MaxTab->prev->next = MaxTab->next;
            MaxTab->next->prev = MaxTab->prev;
        }

        delete MaxTab;
    }


//Add display method in Browser template class 
    void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    
    };
int main(){
    
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    b1.total_memory();
    b1.deleteTab();
    b1.display();
    return 0;
}