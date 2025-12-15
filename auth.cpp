#include <iostream>
#include <string>
#include <map>

using namespace std;

string hashPassword(const string &password) {
    string hash = "";
    for (char c : password) {
        hash += (c + 3);
    }
    return hash;
}

class SecureAuth {
private:
    map<string, string> users;

public:
    SecureAuth() {
        users["admin"] = hashPassword("Admin@123");
        users["user"]  = hashPassword("User@123");
    }

    bool authenticate() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        return users[username] == hashPassword(password);
    }
};

int main() {
    SecureAuth auth;
    if (auth.authenticate())
        cout << "Login successful\n";
    else
        cout << "Login failed\n";
}
