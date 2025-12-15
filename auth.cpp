#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

string hashPassword(const string &password) {
    string hash = "";
    for (char c : password) hash += (c + 3);
    return hash;
}

class SecureAuthSystem {
private:
    map<string, string> users;

public:
    SecureAuthSystem() {
        users["admin"] = hashPassword("Admin@123");
        users["user"]  = hashPassword("User@123");
    }

    bool authenticateUser() {
        string username, password;

        cout << "Enter Username: ";
        cin >> username;

        if (username.length() > 20) {
            cout << "Buffer overflow attempt detected\n";
            return false;
        }

        cout << "Enter Password: ";
        cin >> password;

        if (users.find(username) == users.end())
            return false;

        if (users[username] != hashPassword(password))
            return false;

        srand(time(0));
        int otp = rand() % 9000 + 1000;
        cout << "OTP Generated: " << otp << endl;

        int userOTP;
        cout << "Enter OTP: ";
        cin >> userOTP;

        return otp == userOTP;
    }
};

int main() {
    SecureAuthSystem auth;

    if (auth.authenticateUser())
        cout << "Authentication Successful. Access Granted.\n";
    else
        cout << "Authentication Failed. Access Denied.\n";

    return 0;
}
