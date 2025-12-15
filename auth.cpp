#include <iostream>
#include <string>
#include <map>

using namespace std;

class SecureAuth {
private:
    map<string, string> users;

public:
    SecureAuth() {
        users["admin"] = "Admin@123";
        users["user"]  = "User@123";
    }

    bool authenticate() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        return users[username] == password;
    }
};

int main() {
    SecureAuth auth;
    if (auth.authenticate())
        cout << "Login successful\n";
    else
        cout << "Login failed\n";
}
