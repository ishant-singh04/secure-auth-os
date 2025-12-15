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

class SecureAuth {
private:
    map<string, string> users;

public:
    SecureAuth() {
        users["admin"] = hashPassword("Admin@123");
    }

    bool authenticate() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

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
    SecureAuth auth;
    if (auth.authenticate())
        cout << "Access Granted\n";
    else
        cout << "Access Denied\n";
}
