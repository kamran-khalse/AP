#include <iostream>
#include <vector>

using namespace std;

struct Contact{
	string first_name;
	string last_name;
    vector<string> phone_numbers;
};

using ContactList = vector<Contact>;

Contact search_by_name(ContactList &contacts, string name);
Contact search_by_family(ContactList &contacts, const string family);
Contact search_by_phone(ContactList &contacts, const string phone_number);
int delete_contact(ContactList &contacts);
void add_contact(ContactList &contacts);
void print_contacts(const ContactList &contacts);
void print_menu();

int main(){
	ContactList contacts;
    // contacts.push_back(Contact{"ali", "reza", vector<string> {"123"} } );
    // Contact *con = search_by_name(contacts, "ali");
}

void print_menu(){
    // main menu
}

void add_contact(ContactList &contacts){
    Contact contact;
    // Get data
    // first letters should be upper case
    // check if phone numbers are less than 3 or not
    contacts.push_back(contact);
}

int delete_contact(ContactList &contacts){
    // get name or family or number
    // using one of the search functions
    // delete the contact
    // return 0 to invalid contact
    // return 1 to successful delete
}

void print_contacts(const ContactList &contacts){

}

Contact search_by_name(ContactList &contacts,const string name){
    // search for name
    // if many names are similar
    // ask user to select one of them with calling print_contacts and pass similar names data

    //return contacts[index];
}

Contact search_by_family(ContactList &contacts, const string family){
    // as well as previous
//    return contacts[index]
}

Contact search_by_phone(ContactList &contacts, const string phone_number){
    // as well as previous
//    return contacts[index]
}

void sort_by_family(ContactList &contacts){
    // using string.compare
    // all first letters should be upper case
}


