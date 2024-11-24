#include <ios>
#include <iostream>
#include <array>
#include <string>
#include <windows.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int quantity = 0;
class BST;
class User;
int generateBookID(string basicString);

int generateAlphabetID(char c);

int queue_array[20];

BST *rack[10][5];

User *start = nullptr;

class Queue
 {
public:
    int top;

    Queue() 
    {
        top = -1;
    }

    bool isFull()
	 {
        return top == 19;
    }

    bool isEmpty() 
	{
        return top == -1;
    }

    void enQueue(int value) 
    {
        if (!isFull())
         {
            top++;
            queue_array[top] = value;
        } else 
        {
            cout << "Queue is full!";
        }
    }

    int deQueue()
	 {
        int value = queue_array[0];
        for (int i = 0; i < top; ++i) 
		{
            queue_array[i] = queue_array[i + 1];
        }
        top--;
        return value;
    }

    void reset() 
	{
        top = -1;
    }

    int get_top() 
	{
        return top;
    }
};

class Book
 {
    public:
    string name;
    string author;
    int id, amount;
    int rack;
    Book *next;

    Book(string new_name, string new_author, int new_id, int new_rack) 
	{
        name = new_name;
        author = new_author;
        id = new_id;
        rack = new_rack;
        next = nullptr;
        amount = 1;
    }
};

class BST 
{
    public:
    int id;
    BST *left, *right;
    Book *next;

    BST(int new_id) 
	{
        id = new_id;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

class User
 {
    public:  
    string name;
    Book *book;
    User *next;

    User(string new_name)
	 {
        name = new_name;
        next = nullptr;
        book = nullptr;
    }
};

class member
{
	public:
     char membername[20];
     int memberid;
     char cnic[13];
     const int memberfee= 500;

     
     void insert();
     void display();
     void searchn();
     void searchid();
        
};


BST *searchBST(BST *root, int id);

void displayIssuedBooks();

bool returnBook(string user_name, string book_name);

Book *searchBook(int rack_no, int shelve, string name, string author_name);

Book *searchPreviousBook(BST *root, string name, string author_name);

bool searchBookcheck(BST *root, string name, string author_name);

bool issueBook(string username, string bookname, string author_name);

bool deleteBook(string name, string author_name);

Book *searchBook(BST *bst, string name, string author_name);

bool SearchingsearchBook(BST *bst, string name, int rack, int shelve);

void generateLibraryData();

Book *searchBookmain(BST *root, string name, string author_name);

void addBook(int shelve, string book_name, string author_name);

BST *createBST(int id,BST *root);

void displayLibrary(BST *root);

void saveBooks();

void addToSave(ofstream* file, Book bookObj);

void inOrderSave(ofstream* file,BST *root);

int sortingbooks();

Queue queue;

int main() 
{
    generateLibraryData();

    int choise,option;

    cout <<endl<<"Developed By\n"<<endl<<"Name: Syed Abdul Hadi"<<endl<<"Roll No: 21K-3274"<<"\n\n"<<"Name: Anwer Saeed"<<endl<<"Roll No: 21K-3303"<<"\n\n";
    int y=1;
    while(y==1)
    {   
        member p;
        FILE *fp;
        int ch,x=1;
        cout<<"\n\n\n++++++++++WELCOME++++++++++++\n";
        cout<<"1. New Member\n";
        cout<<"2. Existing Records\n";
        cout<<"3. Continue To library menu\n";
        cin >> option;
        if(option==1)
        {
          p.insert();
        }
        else if (option==2)
        {
          while(x==1)
     {
          cout<<"\n 1. View all members of File";
          cout<<"\n 2. Search record by member name:";
          cout<<"\n 3. Search record by member id:";
          cout<<"\n 4. Exit";
          cout<<"\n\n Enter Your Choice : ";
          cin>>ch;
          switch(ch)
          {
               case 1:
                    p.display();
                    break;
                    
               case 2:
                	p.searchn();
                	break;
                	
               case 3:
               	    p.searchid();
               	    break;

               case 4:
                    x=0;
                    break; 
               default:
                    cout<<"\n Invalid Choice";
          }
     }
        }
        else if (option == 3)
         {
             y=0; 
         } 
    }
    while (true) 
	{
        cout << "\n\n\n++++++++++     M E N U     ++++++++++\n";
        cout << "0. Exit\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert a Book\n";
        cout << "3. Delete a Book\n";
        cout << "4. Search Book By Name\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Issuessed Books \n";
        cout<< "8. Sorting of Books in Library\n";
        cout << "Select an option : ";

        cin >> choise;
        switch (choise) {
            case 0: 
            {
                saveBooks();
                exit(0);
            }
            case 1: {
                cout << "\n\n\n++++++++++     D I S P L A Y     ++++++++++\n";
                // For each rack
                for (int c = 0; c < 5; ++c) {
                    cout << "\n+++++   R A C K - " << c + 1 << "   +++++\n";

                    // For each shelve
                    for (int r = 0; r < 10; ++r) {
                        cout << "\n+++ S H E L V E - " << r + 1 << " +++\n";
                        displayLibrary(rack[r][c]);
                    }
                }
                break;
            }
            case 2: 
            {
                string book_name;
                string author_name;

                cout << "\n\n\n++++++++++     I N S E R T     ++++++++++\n";
                cout << "0. Back\n";
                cout << "1. Fiction\n";
                cout << "2. Historical\n";
                cout << "3. Educational\n";
                cout << "4. Horror\n";
                cout << "5. Non-Fiction\n";
                cout << "\nSelect an option : ";
                cin >> choise;
                if (choise == 0) break;
                else {
                    cout << "\nBook Name : ";

                    cin.ignore();
                    getline(cin, book_name);

                    cout << "\nAuthor Name : ";
                    getline(cin, author_name);

                    addBook(choise - 1, book_name, author_name);
                }
                break;

            }
            case 3: 
            {
                string name, author_name;
                cout << "\n\n\n++++++++++     D E L E T E     ++++++++++\n";
                cout << "\nEnter Book Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "\nEnter Author Name : ";
                getline(cin, author_name);
                bool deleted = deleteBook(name, author_name);
                if (deleted) cout << "\n\nSuccessfully Deleted";
                else cout << "\n\nBook not found";
                break;
            }
            case 4: 
            {
                string name;
                bool found = false;
                cout << "\n\n\n++++++++++     S E A R C H     ++++++++++\n";
                cout << "\nEnter Book Name : ";
                cin.ignore();
                getline(cin, name);

                int id = generateBookID(name);
                
                for (int c = 0; c < 5; ++c) 
                {
                    int shelve = id % 10;

                    BST *bst = searchBST(rack[shelve][c], id);

                    if (bst != nullptr) {
                        found = SearchingsearchBook(bst, name, c, shelve);
                        break;
                    }
                }
                if (!found) {
                    cout << "\n\nBook not found";
                }
                break;
            }
            case 5: 
            {
                string book_name;
                string author_name;
                string username;
                cout << "\n\n\n++++++++++     I S S U E     ++++++++++\n";
                cout << "\nEnter User Name : ";
                cin.ignore();
                getline(cin, username);
                cout << "\nEnter Book Name : ";
                getline(cin, book_name);
                cout << "\nEnter Author Name : ";
                getline(cin, author_name);

                bool issue = issueBook(username, book_name, author_name);
                if (issue) cout << "\n\nBook issued successfully!\n";
                break;
            }
            case 6: 
            {
                string book_name;
                string username;
                cout << "\n\n\n++++++++++     R E T U R N     ++++++++++\n";
                cout << "\nEnter User Name : ";
                cin.ignore();
                getline(cin, username);
                cout << "\nEnter Book Name : ";
                getline(cin, book_name);


                bool issue = returnBook(username, book_name);
                if (issue) cout << "\n\nBook returned successfully!\n";
                break;
            }
            case 7: {
                cout << "\n\n\n++++++++++     I S S U E D   B O O K S     ++++++++++\n";
                displayIssuedBooks();
                break;
            }
            case 8:
            {
                sortingbooks();
                break;
            }

            default:
             {
                cout << "\nInvalid input!";
            }
        }
    }
}

int generateBookID(string str) 
{
    queue.reset();
    int value = 0;
    // Check for each character in str
    for (int i = 0; i < str.length(); ++i) 
    {
        // If str[i] is a space
        if (str[i] == ' ') 
        {
            queue.enQueue(value);
            value = 0;
        } else {
            value += generateAlphabetID(str[i]);
        }
    }
    queue.enQueue(value);
    value = 0;

    stringstream string_stream;

    while (!queue.isEmpty())
    {
        // Adding whole que values to string_stream
        string_stream << queue.deQueue();
    }

    // Combining different parts
    string combining_values = string_stream.str();

    istringstream integer_string_stream(combining_values);

    // Converting combining_values to int
    integer_string_stream >> value;
    return value;
}

void saveBooks()
 {
    ofstream file;
    file.open("D:\\Data Structures\\Project\\books.txt", ios::trunc);
    for (int c = 0; c < 5; ++c) 
    {
        // For each shelve
        for (int r = 0; r < 10; ++r) 
        {
            inOrderSave(&file, rack[r][c]);
        }
    }
}

void addToSave(ofstream* file, Book bookObj)
 {
    int shelve = bookObj.id % 10;
    string shelve_str = to_string(shelve);
    file->write(shelve_str.append("\r\n").data(), shelve_str.size())<<endl;
    file->write(bookObj.name.append("\r\n").data(), bookObj.name.size())<<endl;
    file->write(bookObj.author.append("\r\n").data(), bookObj.author.size())<<endl;
}

void inOrderSave(ofstream* file, BST *root)
 {
    if (root != nullptr)
     {
        inOrderSave(file, root->left);

        // Displaying book linked list
        Book *book = root->next;
        addToSave(file, *book);

        inOrderSave(file, root->right);
    }
}

int generateAlphabetID(char c) 
{

    char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                        't', 'u', 'v', 'w', 'x', 'y', 'z'};
    c = tolower(c);

    for (int i = 0; i < 26; ++i) 
    {
        if (c == alphabets[i])
            return ++i;
    }

    return -1;
}


BST *searchBST(BST *root, int id) 
{

    if (root == nullptr) {
        return nullptr;
    } else {
        while (root != nullptr) {
            if (root->id > id) root = root->left;
            else if (root->id < id) root = root->right;
            else return root;
        }
        return nullptr;
    }
}

void addBook(int shelve, string book_name, string author_name) 
{

    /*
      shelve = 0       Fiction
      shelve = 1       Historical
      shelve = 2       Educational
      shelve = 3       Horror
      shelve = 4       Non Fiction
     
     
     */

    int id = generateBookID(book_name);
    int row = id % 10;
    Book *new_book = new Book(book_name, author_name, id, row);

    // Checking if BST already exists then work on it
    if (rack[row][shelve] != nullptr) {

        // Create it root and search if any BST already exists
        BST *root = rack[row][shelve];
        BST *searched = searchBST(root, id);

        // If no BST with such ID exists
        if (searched == nullptr) {
            BST *new_BST = createBST(id, root);

            // Adding new_book book to BST
            new_BST->next = new_book;
        }

            // If BST exists with same ID
        else 
        {

            // Search if book with same name exists
            Book *searched_book = searchBook(searched, book_name, author_name);

            // If same book is alredy present
            if (searched_book != nullptr)
                searched_book->amount++;
            else 
            {
                new_book->next = searched->next;
                searched->next = new_book;
            }

        }
    }

        
    else 
    {
        rack[row][shelve] = new BST(id);
        rack[row][shelve]->next = new_book;
    }
    
}

BST *createBST(int id, BST *root)
 {
    BST *current = new BST(id);

    BST *p = root;
    BST *k = p;

    if (p == nullptr) 
    {
        root = current;
    } else {
        while (p != nullptr) 
        {
            k = p;
            if (p->id > id) p = p->left;
            else p = p->right;
        }

        if (k->id > id) k->left = current;
        else k->right = current;
    }
    return current;
}

void displayLibrary(BST *root)
 {
    if (root != nullptr)
     {
        displayLibrary(root->left);

        Book *book = root->next;
        while (book != nullptr)
         {

            printf("Book ID = %-10d Amount = %-10d Book Name = %-30s Author Name = %10s\n", book->id, book->amount,
                   book->name.c_str(),
                   book->author.c_str());
            book = book->next;

        }

        displayLibrary(root->right);
    }
}

Book *searchBook(BST *bst, string name, string author_name) 
{
    int id = generateBookID(name);
    Book *book = bst->next;

    while (book != nullptr) 
    {
        if (book->name == name && book->author == author_name)
            return book;
        book = book->next;
    }

    return nullptr;
}

bool SearchingsearchBook(BST *bst, string name, int rack, int shelve)
{
    int id = generateBookID(name);
    Book *book = bst->next;
    bool found = false;

    while (book != nullptr) 
    {
        if (book->name == name) 
        {
            found = true;
            cout << "\nBook name : " << book->name << "       ID : " << book->id << "   Rack: " << rack + 1
                 << "  Shelve: "
                 << shelve + 1 << "  Author Name: " << book->author;
        }
        book = book->next;
    }

    return found;
}

bool deleteBook(string name, string author_name)
 {
    int id = generateBookID(name);
    // For each rack
    for (int c = 0; c < 5; ++c) 
    {
        // For shelve
        int shelve = id % 10;

        
        BST *bst = searchBST(rack[shelve][c], id);

        if (bst != nullptr) 
        {
            if (searchBookcheck(bst, name, author_name)) 
            {
                Book *book = searchBookmain(bst, name, author_name);
                Book *prevbook = searchPreviousBook(bst, name, author_name);
                if (book->name == name && book->author == author_name) 
                {
                    Book *del_book = book;
                    if (book->amount > 1) {
                        book->amount--;
                    } else {
                        if (book->next == nullptr) 
                        {
                            bst->next = nullptr;
                        } else {
                            bst->next = book->next;
                        }
                    }
                    return true;
                } else if (prevbook != nullptr) {
                    Book *del_book = book->next;
                    if (book->next->name == name && book->next->author == author_name) {
                        if (book->next->amount > 1) {
                            book->next->amount--;
                            return true;
                        }
                        if (book->next->next != nullptr) {
                            book->next = book->next->next;
                        } else {
                            book->next = nullptr;
                        }
                        delete (del_book);
                        return true;
                    }

                }
            }

        }
    }

    return false;
}

Book *searchPreviousBook(BST *root, string name, string author_name)
 {
    int id = generateBookID(name);
    Book *book = root->next;
    Book *prev_book = book;

    while (book != nullptr) {
        if (book->name == name && book->author == author_name)
            return prev_book;
        prev_book = book;
        book = book->next;
    }
    return nullptr;
}

Book *searchBookmain(BST *root, string name, string author_name)
 {
    int id = generateBookID(name);
    Book *book = root->next;

    while (book != nullptr) {
        if (book->name == name && book->author == author_name)
            return root->next;

        book = book->next;
    }
    return nullptr;
}

bool searchBookcheck(BST *root, string name, string author_name)
 {
    int id = generateBookID(name);
    Book *book = root->next;

    while (book != nullptr) {
        if (book->name == name && book->author == author_name)
            return true;

        book = book->next;
    }
    return false;
}

void generateLibraryData()
 {
    ifstream inFile;
    stringstream ss;
    inFile.open("books.txt");
    if (!inFile) 
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);  
    }

    int shelve;
    string shelve_str;
    string book_name;
    string author_name;
    while (getline(inFile, shelve_str)) {
        // converting shelve_str to int
        ss << shelve_str;
        ss >> shelve;
        getline(inFile, book_name);
        getline(inFile, author_name);
        addBook(shelve, book_name, author_name);

    }
    inFile.close();
}

bool issueBook(string user_name, string book_name, string author_name) 
{

    bool user_exists = false;
    User *u = start;
    User *user1 = nullptr;
    User *user = nullptr;

    while (u != nullptr) 
	{
        if (u->name == user_name) {
            user_exists = true;
        }
        user1 = u;
        u= u->next;
    }
    if(!user_exists) {
        user = new User(user_name);

        int id = generateBookID(book_name);
        int shelve = id % 10;
        Book *book = nullptr;
        Book *temp_book = nullptr;
        BST *bst = nullptr;

        for (int i = 0; i < 5; ++i) {
            bst = searchBST(rack[shelve][i], id);
            if (bst != nullptr) {
                book = searchBook(bst, book_name, author_name);
                if (book != nullptr) {
                    temp_book = new Book(book_name, author_name, id, i);
                    temp_book->author = book->author;

                    
                    deleteBook(book_name, author_name);

                    
                        user->book = temp_book;
                    if(start== nullptr){
                        start = user;
                    }
                    else{
                        user1->next=user;
                    }

                    return true;
                }
            }
        }
        cout<<"Book Not Found";
    }
    else{
        cout<<"\n"<<"One User can Issue Only One Book";
    }
    return false;
}

bool returnBook(string user_name, string book_name) 
{
    User *user = start;
    User *prev_user = start;
    while (user != nullptr) 
    {
        prev_user = user;
        if (user->name == user_name) break;
        user = user->next;
    }

    // If user exists
    if (user != nullptr)
     {
        // Searching book
        Book *book = user->book;

        // If book exists
        if (book != nullptr&&book->name==book_name) 
        {

            // If there is only one book in user
            if (user->book == book) 
            {
                addBook(book->rack, book_name, book->author);
                user->book= nullptr;
                delete book;

                // If the user is the root
                if (user == start) {
                    if(start->next!= nullptr){
                    start = start->next;
                    }
                    else{
                        start = nullptr;
                    }
                }
                else {
                    prev_user->next= user->next;
                    delete user;
                }
                return true;
            }
        }
        else{
            cout<<"\nBook not Found";
        }
    }
    else{
        cout<<"User Doesn't Exist";
    }
    return false;

}

void displayIssuedBooks() {
    User *user = start;
    while (user != nullptr) {
        Book *book = user->book;

        while (book != nullptr) {
            printf("Username : %-15sBook name : %-15s Author Name : %-15s \n", user->name.c_str(), book->name.c_str(),book->author.c_str());
            book = book->next;
        }

        user = user->next;
    }
}

void member::insert()
{
	member p;
	FILE *fp;
	char c;
	fp=fopen("member.txt","ab");
                    while (1)
                    {
                         cout<<"\n Enter Member Name   :  ";
                         cin>>p.membername;
                         fflush(stdin);
                         cout<<"\n Enter Member ID.   :  ";
                         cin>>p.memberid;
                         fflush(stdin);
                     
                         cout<<"\n Enter Cnic:  ";
                         cin>>p.cnic;
                         fflush(stdin);
                         
                         fwrite(&p,sizeof(p),1,fp);
                         fflush(stdin);
                         cout<<"\n\n Do You Want to Continue?(Y/N) : ";
                         cin>>c;
                         if(c=='n' || c=='N')
                              break;
                    }
                    fclose(fp);
                    
}
void member::display()
{
	FILE *fp;
	member p;
	fp=fopen("member.txt","rb");
                    while (fread(&p,sizeof(p),1,fp))
                    {
                         while(1)
                         {
                              cout<<"\n Member ID : "<<p.memberid;
                              cout<<"\n Member Name : "<<p.membername;
                              cout<<"\n Cnic : "<<p.cnic<<endl;
                              cout<<"Total Fee: "<<memberfee;
                              break;

                         }
                    }
                    fclose(fp);
                    
}
void member::searchn()
{
	FILE *fp;
	member e;
	fp=fopen("member.txt","rb");
                    cout<<"\n Enter Member Name  : ";
                    cin>>membername;
                    while(fread(&e,sizeof(e),1,fp))
                    {
                         if(strcmp(membername,e.membername)==0)
                         {
                              while(1)
                              {
                                   cout<<"\n\t"<<e.memberid<<" : "<<e.membername;
                                   break;
                              }
                         }
                    }
                    fclose(fp);
                    
}
void member::searchid()
{
	FILE *fp;
	member e;
	fp=fopen("member.txt","rb");
                    cout<<"\n Enter Member ID.  : ";
                    cin>>memberid;
                   
                    while(fread(&e,sizeof(e),1,fp))
                    {
                         if(memberid == e.memberid)
                         {
                              cout<<"\n\t"<<e.memberid<<" : "<<e.membername;                            
                              break;
                         }
                    }
                    fclose(fp);                
}

int sortingbooks()
{
  vector <string> array;

  std::ostream_iterator< string > output ( cout, "\n" );

  ifstream read ( "books.txt" );
  string line,line1,line2;
  getline(read,line1);
  cout<<"Books In Library: "<<endl;
  while ( getline ( read, line, '\n' ) )
  {
    cout << line << endl;
    array.push_back ( line );
    for(int i=0;i<2;i++)
    {
        getline(read,line2);
    }
  }
  read.close(); 
  sort ( array.begin(), array.end() ); 

  std::vector< string >::iterator endLocation;
  endLocation = std::unique ( array.begin(), array.end() );

  cout << "\n\n\nSorted Books names:\n";
  std::copy ( array.begin(), endLocation, output ); 

  cin.get();
  return 0;
}

