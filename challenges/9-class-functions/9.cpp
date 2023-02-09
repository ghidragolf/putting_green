#include <iostream>

using namespace std;

class Book
{
private:
    string title;
    bool checkedOut;
 
public:
    Book(string title)
    {
        this->title = title;
        this->checkedOut = false;
    }
 
    string getTitle()
    {
        return title;
    }
 
    bool isCheckedOut()
    {
        return checkedOut;
    }
 
    void setCheckedOut(bool checkedOut)
    {
        this->checkedOut = checkedOut;
    }
};

class Person
{
private:
    string name;
    Book** books;
    int numBooks;
 
public:
    Person(string name)
    {
        this->name = name;
        this->books = NULL;
        this->numBooks = 0;
    }
 
    string getName()
    {
        return name;
    }
 
    void addBook(Book* book)
    {
        Book** tempBooks = new Book*[numBooks + 1];
        for(int i = 0; i < numBooks; i++)
        {
            tempBooks[i] = books[i];
        }
        tempBooks[numBooks] = book;
        books = tempBooks;
        numBooks++;
    }
 
    int removeBook(Book* book)
    {
        int index = -1;
        for(int i = 0; i < numBooks; i++)
        {
            if(book == books[i])
            {
                index = i;
                break;
            }
        }
        if(index != -1)
        {
            Book** tempBooks = new Book*[numBooks - 1];
            int j = 0;
            for(int i = 0; i < numBooks; i++)
            {
                if(i != index)
                {
                    tempBooks[j] = books[i];
                    j++;
                }
            }
            books = tempBooks;
            numBooks--;
            return 0;
        }
        else
        {
            cout << book->getTitle() << " not found in " << name << "'s collection" << endl;
            return 1;
        }
    }
};



class Library
{
private:
    string name;
    Book* books;
    int numBooks;
    Person* people;
    int numPeople;
 
public:
    Library(string name)
    {
        this->name = name;
        this->books = NULL;
        this->numBooks = 0;
        this->people = NULL;
        this->numPeople = 0;
    }
 
    string getName()
    {
        return name;
    }
 
    void addBook(Book* book)
    {
        Book** tempBooks = new Book*[numBooks + 1];
        for(int i = 0; i < numBooks; i++)
        {
            tempBooks[i] = &books[i];
        }
        tempBooks[numBooks] = book;
        books = *tempBooks;
        numBooks++;
    }
 
    void addPerson(Person* person)
    {
        Person** tempPeople = new Person*[numPeople + 1];
        for(int i = 0; i < numPeople; i++)
        {
            tempPeople[i] = &people[i];
        }
        tempPeople[numPeople] = person;
        people = *tempPeople;
        numPeople++;
    }
 
    void checkOut(Book* book, Person* person)
    {
        if(book->isCheckedOut())
        {
            cout << book->getTitle() << " is already checked out" << endl;
        }
        else
        {
            book->setCheckedOut(true);
            person->addBook(book);
            cout << book->getTitle() << " checked out to " << person->getName() << endl;
        }
    }
 
    void checkIn(Book* book, Person* person)
    {
        if(book->isCheckedOut())
        {
            book->setCheckedOut(false);
            if (person->removeBook(book) == 0)
            {
                cout << book->getTitle() << " checked in" << endl;
            }
        }
        else
        {
            cout << book->getTitle() << " is not checked out" << endl;
        }
    }
};

class Librarian
{
private:
    Person* person;
 
public:
    Librarian(Person* person)
    {
        this->person = person;
    }
 
    Person* getPerson()
    {
        return person;
    }
 
    void checkOutBook(Library* library, Book* book)
    {
        library->checkOut(book, person);
    }
 
    void checkInBook(Library* library, Book* book)
    {
        library->checkIn(book, person);
    }
};

class Patron
{
private:
    Person* person;
 
public:
    Patron(Person* person)
    {
        this->person = person;
    }
 
    Person* getPerson()
    {
        return person;
    }
 
    void checkOutBook(Library* library, Book* book)
    {
        library->checkOut(book, person);
    }
};

int main()
{
    Library library("Library");
    Book book1("Book 1");
    Book book2("Book 2");
    Book book3("Book 3");
    Person person1("Person 1");
    Person person2("Person 2");
    Librarian librarian(&person1);
    Patron patron(&person2);
 
    library.addBook(&book1);
    library.addBook(&book2);
    library.addPerson(&person1);
    library.addPerson(&person2);
 
    librarian.checkOutBook(&library, &book1);
    patron.checkOutBook(&library, &book2);
    patron.checkOutBook(&library, &book3);
    librarian.checkInBook(&library, &book1);
    librarian.checkInBook(&library, &book3);
 
    return 0;
}