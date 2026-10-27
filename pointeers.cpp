#include <iostream>
#include <vector>
#include <string>
#include <limits>


class book {
private:
    std::string title;
    std::string author;
    double price;

    public:
    book (std::string t, std::string a, double p): title(t), author(a), price(p) {}

    void didplayInfo () const {
        std::cout << "title:" << title << "author:" << author << "price:" << price  << std::endl;
    }

    std::string getTitle() const{
        return title;
    }
};

class Inventory {
    private:
    std::vector<book*>books;

    public:
    ~Inventory(){
        for(book* bookPtr : books) {
            delete bookPtr;
        }
        books.clear();
    }

    void addbook(book* bookptr){
        if(bookptr != nullptr){
            books.push_back(bookptr);
            std::cout <<"book sucessfully added to Inventory!\n";
        }
    }

    void displayall() const {
        if(books.empty()){
            std::cout <<"The Inventory is empty.\n";
            return;
        }

        std::cout <<"\n__Current book Inventory___\n";
        for (size_t i = 0; i < books.size(); ++i){
            std::cout <<  "["<< i <<"}";
            books[i]->didplayInfo();
        }
    }
    void removebook (int index) {
        if (index < 0 || index >= static_cast<int>(books.size())) {
            std::cout << "invalid index.\n";
            return;
        }

        delete books[index];
        books.erase(books.begin() + index);
        std::cout <<"book at index"<<index<<"successfuly.\n";
    }

    
     bool isempty() const {
            return books.empty();
    }

};

int main () {
    Inventory story;
    int choice = 0;

    do{
        std::cout << "\n----\n";
        std::cout <<" book Inventory \n";
        std::cout << "\n-----\n";
        std::cout<<"1.add new book\n";
        std::cout<<"2.display all books\n";
        std::cout<<"3.remove book by index\n";
        std::cout <<"4. q\n";
        std::cout <<" enter your chose 1-4:\n";

        if (!(std::cin >> choice)) {
            std::cout <<"invalid input.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: {
                std::string title, author;
                double price;

                std::cout << "enter book title:";
                std::getline(std::cin, title);

                std::cout << "enter author:";
                std::getline(std::cin, author);

                std::cout << "enter book price:$";
                while(!(std::cin >> price)) {
                std::cout << "invalid price:";
                std::cin.clear();
                std::cin.ignore(std:: numeric_limits<std::streamsize>::max(),'\n');
                }

                book*newbook = new book(title , author, price);
                story.addbook(newbook);
                break;
            }
             case 2 :
                story.displayall();
                break;
            case 3 :{
                story.displayall();
                if (! story.isempty()) {
                    int index;
                    std::cout <<"enter the index input.\n";
                    if(std::cin >> index){
                        story.removebook(index);
                    }else {
                        std::cout <<"invalid index input.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    
                }
                break;
            
            }
            case 4:
              std::cout << "exiting program \n";
              break;
            default:
              std::cout <<"invalid choic 1 and 4 .\n";
        }
    } while (choice != 4 );

    return 0;
}

