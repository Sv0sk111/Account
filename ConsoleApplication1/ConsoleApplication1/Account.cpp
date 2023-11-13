#include <iostream>
#include <string>
#include <fstream>

void afteracc()
{
    std::cout << "after acc";
}

void Login()
{
a:
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    std::ifstream file(username + ".txt");
    if (file.is_open()) {
        std::string storedPassword;
        file >> storedPassword;

        std::string enteredPassword;
        std::cout << "Enter the password for your account: ";
        std::cin >> enteredPassword;

        if (enteredPassword == storedPassword) {
            std::cout << "Password is correct. Access to account is granted" << '\n';
            afteracc();
        }
        else {
            std::cout << "Password is incorrect. Access to account is denied" << '\n';
            goto a;
        }

        file.close(); // Close the file when done
    }
    else {
        std::cout << "Error: User not found please check the username." << '\n';
        goto a;
    }
}

void Account()
{
name1:
    system("cls");
    std::cout << "Create a new account!" << '\n';
gg:
    std::string name1; // Name variable
    std::cout << "Enter a username (no spaces): ";
    std::cin >> name1;

    std::ifstream filename(name1 + ".txt");

    if (filename.is_open())
    {
        std::cout << "Error: Your username is already taken!" << '\n';
        goto gg;
    }
    else {
        std::cout << "This username is not taken!" << '\n';
        goto age1;
    }

    if (name1 == "") // Checking if the user wrote a name
    {
        std::cout << "Error: You can't leave the name empty" << '\n';
        goto name1; // Going to name input again
    }

age1:
    int age1; // Age variable
    std::cout << "Enter your real age: ";
    std::cin >> age1;
    if (age1 < 18) { // Checking if the user is under 18
        std::cout << "You can't be under 18" << '\n';
        system("pause");
        exit(0); // Exiting if the user is under 18
    }
    else if (age1 > 100) { // Checking if the user is too old
        std::cout << "Error: You can't be over 100" << '\n';
        system("pause");
        exit(0);
    }
    else {
    password:
        std::string password; // Password variable
        std::cout << "Enter a password for your account (no spaces): ";
        std::cin >> password;
        if (password == "") {
            std::cout << "Error: You can't leave the password empty";
            goto password;
        }
        else {
            std::cout << "Hello " << name1 << '\n'; // Showing the user their information to confirm
            std::cout << "Your age is " << age1 << '\n';
            std::cout << "Your password is " << password << '\n';
            std::string y;
            std::cout << "Is this information correct (y/n): "; // Asking the user if the information is correct
            std::cin >> y;

            if (y == "y") {
                name1 = name1 + ".txt";
                std::ofstream file(name1); // Use std::fstream to create the file
                if (file.is_open()) {
                    file << password << "\n";
                    file.close();
                    std::cout << "File created and information written successfully" << '\n';
                }
                else {
                    std::cout << "Error: Failed to open the file" << '\n';
                    system("pause");
                    goto name1;
                }
            }
            else if (y == "n") {
                goto name1;
            }
        }
    }
}

int main()
{
    int n;
    std::cout << "Written by Sv0sk111" << '\n';
    std::cout << "Do you have an account (1) or do you want to make a new one (2): ";
    std::cin >> n;
    switch (n) {
    case 1:
        Login();
        break;
    case 2:
        Account();
        break;
    }
    return 0;
}


