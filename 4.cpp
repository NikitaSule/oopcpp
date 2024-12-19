#include <iostream>
#include <string>
#include <vector>

class Item {
public:
    std::string title;
    std::string author;
    bool is_available;
};

class Book : public Item {
public:
    std::string isbn;
    int publication_year;
};

class Member {
public:
    std::string name;
    int membership_id;
    std::vector<Book> borrowed_items;
    std::vector<Reservation> reservations;
};

class Reservation {
public:
    Book item;
    Member member;
    std::string reservation_date;
    std::string expiration_date;
};

class Fine {
public:
    double amount;
    std::string reason;
    std::string due_date;
};

class Library {
public:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Reservation> reservations;

    void addBook(Book newBook) {
        books.push_back(newBook);
    }

    void registerMember(Member newMember) {
        members.push_back(newMember);
    }

    void reserveBook(Book book, Member member, std::string res_date, std::string exp_date) {
        Reservation newReservation;
        newReservation.item = book;
        newReservation.member = member;
        newReservation.reservation_date = res_date;
        newReservation.expiration_date = exp_date;

        reservations.push_back(newReservation);
    }

    double calculateFine(Fine fine) {
        return fine.amount;
    }
};

int main() {
 
    Library library;

    Book book1;
    book1.title = "Sample Book";
    book1.author = "Sample Author";
    book1.isbn = "1234567890";
    book1.publication_year = 2021;

    Member member1;
    member1.name = "John Doe";
    member1.membership_id = 1001;

    library.addBook(book1);
    library.registerMember(member1);


    return 0;
}