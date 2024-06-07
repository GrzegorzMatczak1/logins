#include <iostream>
#include <fstream>

using namespace std;

class Auth
{

public:

    virtual bool authorise() = 0;
};


class Password : public Auth
{
private:
    string correctPassword;
public:
    Password()
    {
        correctPassword = "Placki123";
    }

    bool authorise()
    {
        string given_password;

        cout << "Type the correct password: ";
        cin >> given_password;
        cout << endl;
        if(given_password == correctPassword)
        {
            return true;
        }
        else
        {
            cout << "Incorrect password" << endl;
            cout << "Do you wish to change your password?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Your input: ";

            int choice;

            cin >> choice;
            cout << endl;

            switch(choice)
            {
            case 1:
                cout << "Do you wish to change your password?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "Your input: ";

                int choice;

                cin >> choice;
                cout << endl;

                switch(choice)
                {
                case 1:
                    generate_password();
                    cout << "A new password has been made in a secret file" << endl;
                    break;
                case 2:
                    cout << "Canceling the creation of new file" << endl;
                    break;
                default:
                    cout << "Wrong input canceling the creation of new password" << endl;
                }

                break;
            case 2:
                break;
            case 3:
                cout << "Wrong input given. We won't change the password" << endl;
                break;
            }

            return false;
        }
    }

    void password_changer()
    {
        string new_password;

        for(int i = 0; i < 10; i++)
        {
            char random_number = arc4random() % 95;
            random_number += 32;
            string x{random_number};

            new_password += x;
        }
        correctPassword = new_password;
    }

    void generate_password()
    {
        password_changer();
        string userPassword;
        string desktopPath = getenv("HOME");
        desktopPath += "/Desktop/";
        string fileName = "important.txt";
        string filePath = desktopPath + fileName;
        ofstream outFile;
        outFile.open(filePath);
        if (!outFile)
        {
            cout << "Unable to open file: " << filePath << endl;
        }
        else
        {
            outFile << "Do not share your password with anyone!" << endl;
            outFile << "Your Skype login password is: " << correctPassword << endl;
            outFile.close();

        }
    }
};

class Sms : public Auth
{
private:
    string code;
public:
    void generate()
    {
        string generated_code;
        for(int i = 0; i < 7; i++)
        {
            int random_number = arc4random() % 10;

            code += to_string(random_number);
        }


    }
    bool authorise()
    {
        generate();
        string userCode;
        string desktopPath = getenv("HOME");
        desktopPath += "/Desktop/";
        string fileName = "output.txt";
        string filePath = desktopPath + fileName;
        ofstream outFile;
        outFile.open(filePath);
        if (!outFile)
        {
            cout << "Unable to open file: " << filePath << endl;
            return false;
        }

        outFile << "Do not share this code with anyone!" << endl;
        outFile << "Your Skype login code is: " << code << endl;
        outFile.close();

        cout << "Check desktop for the code!" << endl;
        cin >> userCode;

        if(code == userCode)
        {
            return true;
        }
        else
        {
            cout << "Wrong code!" << endl;
            return false;
        }
    }

    /*
    void send_code()
    {
        cout << endl;
        cout << "Please do not give anyone this code!" << endl;
        cout << "Your Skype login is: " << code << endl;
    }*/
};


class App
{
private:
    Auth* auth;
public:
    void setAuth()
    {
        cout << "Type the number of the option of your choice of login:" << endl;
        cout << "1. Password" << endl;
        cout << "2. SMS code" << endl;
        cout << "Your input: ";

        int choice;

        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 1:
            auth = new Password();
            break;
        case 2:
            auth = new Sms();
            break;
        default:
            auth = nullptr;
            break;
        }



    }

    void logIn()
    {
        bool logged_in = false;
        while(!logged_in)
        {
            bool checker = auth->authorise();

            if(checker == true)
            {
                cout << "loged in" << endl;
                logged_in = true;
            }

        }
    }
};

int main()
{
    App app;
    app.setAuth();
    app.logIn();
    return 0;
}
