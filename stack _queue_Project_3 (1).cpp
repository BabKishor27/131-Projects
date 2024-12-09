// Name: Bobby Kishor
// CWID: 884491341

#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include <algorithm>


// Add class Stack here
class Stack
{
    private:
        void push(std::vector<std::pair<char, int>>& a, std::pair<char, int> b)
        {
            a.push_back(b);
        }
        std::pair<char, int> top(std::vector<std::pair<char, int>>& a)
        {
            if (a.size() == 0)
            {
                return std::make_pair(NULL, NULL);
            }
            return a[a.size()-1];
        }
        void pop(std::vector<std::pair<char, int>>& a)
        {
            a.pop_back();
        }
        bool match(char a, char b)
        {
            if (a == '(' && b == ')')
            {
                return true;
            }
            else if (a == '[' && b == ']')
            {
                return true;
            }
            else if (a == '{' && b == '}')
            {
                return true;
            }
            return false;
        }
        bool isOpen(char a)
        {
            return a == '(' || a == '[' || a == '{';
        }
        bool isClose(char a)
        {
            return a == ')' || a == ']' || a == '}';
        }
    public:
    /* validPara() - It will determine whether all parenthesis are completed or something is missing. It will print valid if all are completed otherwise it will
                     print invalid. It will take one string parameter that is an expression.  
            Ex: 1) ‘(({}))’ -here all parenthesis are balanced so, its valid 
                2)’(({})’ - here a one parenthesis is missing so, it is invalid */

        void validPara(std::string pairs)
        {
            // Add your code here
            std::vector<std::pair<char, int>> stack;

            for (int i = 0; i < pairs.size(); i++) {
                char current = pairs[i];
                if (isOpen(current)) {
                    stack.push_back(std::make_pair(current, i)); // Corrected to push a pair (char, index)
                } else if (isClose(current)) {
                    if (stack.empty() || !match(stack.back().first, current)) {
                        std::cout << "invalid" << '\n';
                        return;
                    }
                    stack.pop_back();
                }
            }
            if (stack.empty()) {
                std::cout << "valid" << '\n';
            } else {
                std::cout << "invalid" << '\n';
            }
        }

        /* indexError() - It will find out the first index where the actual error occurred which is invalid parentheses. 
        It will take one string parameter that is an expression.  It will return the first index of unbalanced parenthesis. 
        It means you have to find out first opening parenthesis for which closing parenthesis is missing Return -1 if all parenthesis are completed.
            Ex: 1) ‘(({}))’- return -1 since all are balanced
                2) ‘(({})’ - return 5 since index at 5 for opening parenthesis closing parentheses is missing */
        int indexError(std::string pairs)
        {
            // Add your code here
            std::vector<std::pair<char, int>> stack;

            for (int i = 0; i < pairs.size(); i++){
                char current = pairs[i];
                if (isOpen(current)) {
                    stack.push_back(std::make_pair(current, i));
                } else if (isClose(current)) {
                    if (stack.empty() || !match(stack.back().first, current)) {
                        return i;
                    }
                    stack.pop_back();
                }
            }

            if (!stack.empty()) {
                return stack.back().second;
            }
            return -1;
        }

        /*minPara()- It will determine how many parenthesis are needed to make a string of code as a valid parenthesis string. 
        It will take one string parameter that is an expression. It will print how many minimum parentheses are required to make the string balanced. 
	        Ex: 1) ‘(({}))’- return -0 since all are balanced
                2) ‘(({})’ - return 1 since index at 5 closing parentheses is missing */
        void minPara(std::string pairs)
        {
            // Add your code here
            std::vector<char> stack;
            int total_needed = 0;

            for (char current:pairs) {
                if (isOpen(current)) {
                    stack.push_back(current);
                } else if (isClose(current)) {
                    if (stack.empty() || !match(stack.back(), current)){
                        total_needed++;
                    } else {
                        stack.pop_back();
                    }
                }
            }
            total_needed = total_needed + stack.size();
            std::cout << total_needed << '\n';
        }

        /*scorePara()- It will calculate how many valid parentheses are present in the given string. It will take one string parameter that is an expression. 
        It will print how many balanced parentheses are present in the string. 
            Ex: 1) ‘(({}))’- return -3 
                2) ‘(({})’ - return 2 since index at 5 closing parentheses is missing  */
        void scorePara(std::string pairs)
        {
            // Add your code here
            std::vector<char> stack;
            int valid_pairs = 0;
            for (char current:pairs) {
                if (isOpen(current)){
                    stack.push_back(current);
                } else if (isClose(current)) {
                    if (!stack.empty() && match(stack.back(), current)) {
                        valid_pairs++;
                        stack.pop_back();
                    }
                }
            }
            std::cout << valid_pairs << '\n';
}
};


// Add class Queue here
class Queue
{
    private:
        std::vector<std::string> queue;
        std::string pop()
        {
            auto a = queue[0];
            queue.erase(queue.begin());
            return a;
        }
        std::string reverse(std::string s)
        {
            std::string a = "";
            for (int i = s.size()-1; i >= 0; i--)
            {
                a += s[i];
            }//std::cout<<"DDDD"<<std::endl;
            return a;
        }
    public:
        /* enqueue() - It will divide the entire message into chunks (new string) of 8 characters and insert it into the queue. 
        Before insertion it will reverse the character of the chunk using the reverse function. It will take a string as a parameter.*/
        void enqueue(std::string s)
        {
            // Add your code here
            int chunks_size = 8;
            int z = s.length();

            for (int i = 0; i < z; i += chunks_size) {
                std::string chunk = s.substr(i, chunks_size);
                std::string reverse_chunk = reverse(chunk);
                queue.push_back(reverse_chunk);
            }
        }

        /*processMsg() - It will remove the chunk from the queue one by one until the queue is not empty.
         Then it will be reversed and the entire message will be formed. Display the entire message in this function. */
        void processMsg()
        {
            // Add your code here
            std::string entire_msg = "";
            while (!queue.empty()){
                std::string chunk = pop();
                entire_msg = entire_msg + reverse(chunk);
            }
            std::cout << entire_msg << '\n';
        }
};

// Remove comments before testing and do not change anything in main function
int main(){
    Stack s1;
    s1.validPara("(([]))");
    s1.minPara("(([]))");
    s1.scorePara("(([]))");
    s1.validPara("(([])");
    std::cout<<s1.indexError("(([))")<<std::endl;
    s1.minPara("(([])");
    s1.validPara("(([{}))");
    std::cout<<s1.indexError("(([[}])")<<std::endl; 
    s1.minPara("(([{}))");
    s1.scorePara("(([{}))");
    std::cout<<s1.indexError("({}[]()[)")<<std::endl;
    s1.validPara("(([))");
    s1.minPara("(([))");
    std::cout<<s1.indexError("[({)]")<<std::endl;
    s1.validPara("(([{[{({})}]}]))");
    s1.minPara("(([{[{({})}]}]))");
    s1.scorePara("(([{[{({})}]}]))");
    s1.validPara("(([[{[{({})}]))");
    s1.validPara("(([[{[{({})}]}])]))");
    s1.scorePara("(([[{[{({})}]}])]))");
    std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
    s1.validPara("(())");
    s1.validPara("(())");
    s1.validPara("void function(){}");
    s1.scorePara("void function(){}");
    s1.validPara("void function(");
    s1.minPara("void function(");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
    s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
    s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
    std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;
    Queue q1;
    q1.enqueue("This is a secure message.");
    q1.processMsg();
    q1.enqueue("The product I received is damaged. What should I do?");
    q1.processMsg();
    q1.enqueue("I need assistance with setting up my new device");
    q1.processMsg();
    q1.enqueue("The website is not loading properly on my browser.");
    q1.processMsg();
    q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
    q1.processMsg();
    q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
    q1.processMsg();
    q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
    q1.processMsg();
    q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
    q1.processMsg();
    return 0;
}