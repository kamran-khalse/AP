#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Contact {
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

string standard_name(string name);

int main() {
    ContactList contacts;
    contacts.push_back(Contact{"Ali", "Reza", vector<string>{"123", "09121212121"}});
    contacts.push_back(Contact{"Gholi", "Faza", vector<string>{"567"}});
    contacts.push_back(Contact{"Ali", "Gholi", vector<string>{"12", "33", "23"}});
    contacts.push_back(Contact{"Soltan ali reza", "Gholi", vector<string>{"12", "33", "3213231312"}});
    search_by_name(contacts, "ali");
    // Contact *con = search_by_name(contacts, "ali");
}

void print_menu() {
    // main menu
}

void add_contact(ContactList &contacts) {
    Contact contact;
    // Get data
    // first letters should be upper case
    // check if phone numbers are less than 3 or not
    contacts.push_back(contact);
}

int delete_contact(ContactList &contacts) {
    // get name or family or number
    // using one of the search functions
    // delete the contact
    // return 0 to invalid contact
    // return 1 to successful delete
}

void print_contacts(const ContactList &contacts) {
    string line = "-----|------------------------|--------------------------|-------------------------------\n";
    cout << "  #  |                  Name  |                  Family  |          Phone numbers" << endl;
    cout << line;//16|18
    for (int i = 0; i < contacts.size(); ++i) {

        cout << setw(3) << i + 1 << "  |";
        cout << setw(22) << contacts[i].first_name << "  |";
        cout << setw(24) << contacts[i].last_name << "  |";
        cout << setw(22) << contacts[i].phone_numbers[0];
        
        if (contacts[i].phone_numbers.size() > 1) {
            cout << endl;
            for (int j = 0; j < contacts[i].phone_numbers.size() - 1; ++j) {
                cout << setw(6) << "  |" << setw(25) << "  |" << setw(27) << "  |";
                cout << setw(22) << contacts[i].phone_numbers[j + 1] << endl;
            }
        }else{
            cout << endl;
        }

        cout << line;
    }

}

Contact search_by_name(ContactList &contacts, string name) {
    ContactList same_name;
    name = standard_name(name);
    for (int i = 0; i < contacts.size(); ++i) {
        if (name == standard_name(contacts[i].first_name)) {
            same_name.push_back(contacts[i]);
        }
    }

    if (same_name.size() == 1) {
        return same_name[0];
    } else if (same_name.empty()) {
        cout << "There is no contact with this name" << endl;
        return Contact{string(""), string(""), vector<string>{}};
    } else {
        int position;
        cout << "There is several contact with this name, as shown below:" << endl;
        print_contacts(same_name);
        cout << "Which " << name << " do you mean?" << endl;
        cout << "Enter the number: ";
        cin >> position;
        return same_name[position - 1];
    }
}

string standard_name(string name) {
    string result = name;
    if (name[0] >= 'a' && name[0] <= 'z') {
        result[0] = result[0] - 32;
    }

    return result;
}

Contact search_by_family(ContactList &contacts, const string family) {
    // as well as previous
//    return contacts[index]
}

Contact search_by_phone(ContactList &contacts, const string phone_number) {
    // as well as previous
//    return contacts[index]
}

void sort_by_family(ContactList &contacts) {
    // using string.compare
    // all first letters should be upper case
}

