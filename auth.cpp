#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

// Password hashing (demo purpose)
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

        //  Buffer overflow protection
        if (username.length() > 20) {
            cout << "⚠ Buffer overflow attempt detected!\n";
            return false;
        }

        cout << "Enter Password: ";
        cin >> password;

        if (users.find(username) == users.end())
            return false;

        if (users[username] != hashPassword(password))
            return false;

        //  OTP-based MFA
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
    SecureAuth auth;

    if (auth.authenticate())
        cout << "Authentication Successful\n";
    else
        cout << "Authentication Failed\n";

    return 0;
}
