#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    map<int, string> name;
    cout << "How many attendants will come to the next party?: ";
    int party = 0;
    cin >> party;

    string input;
    for (int i = 0; i < party; i++) {
        cout << "please: ";
        cin >> input;
        name[i] = input;
    }

    cout << "Please search you name: ";
    string your_name;
    cin >> your_name;

    auto it = find_if(name.begin(), name.end(), [your_name](const auto& pair) {
        return pair.second == your_name;
    });

    if (it != name.end()) {
        cout << "Your student number is " << it->first << endl;
    } else {
        cout << "There are no records of yor information on this page.\nDo you wanna sign up for this service?(1. Y, 2. N): ";
        char c;
        cin >> c;
        if (c == 'y' || c == 'Y') {
            name.insert(make_pair(name.size(), your_name));
            cout << "This is the current status of information\n";
            for (int i = 0, x = name.size(); i < x; i++) {
                   cout << name[i] << " ";
            }
            printf("\n");
        } 
        else if (c == 'n' || c == 'N') {
            cout << "Thank you!!\n";
        } 
        else {
            cout << "This is the current status of information\n";
            for (int i = 0, x = name.size(); i < x; i++) {
                   cout << name[i] << " ";
            }
            printf("\n");
        }
    }

    return 0;
}
