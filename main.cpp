#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

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
        //string desktopPath = "C:/Pobrane/"; //IF YOU WANT TO USE THE CODE IN WINDOWS REPLACE ALL DESKTOPPATHS WITH THIS nah c++ doesnt have a random number generator :|
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
            //string aaaa = "DELETE ME!!!";
        }


    }
    bool authorise()
    {
        generate();
        string userCode;
        string desktopPath = getenv("HOME");
        desktopPath += "/Desktop/";
        //string desktopPath = "C:/Pobrane/"; //IF YOU WANT TO USE THE CODE IN WINDOWS REPLACE ALL DESKTOPPATHS WITH THIS
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

class Captcha : public Auth
{
private:
    string picture;
    string main_ansfer;
public:
    void generate_captcha()
    {
        //cout << "Got here 1" << endl;
        string* generated_picture_list;
        string* ansfer;

        generated_picture_list = new string[11];
        ansfer = new string[11];

        //cout << "Got here 2" << endl;

        generated_picture_list[0] = R"(
      _ __/\
  /\_\      \
 |           \
 |             \           ___
  \             \        /  _ \
 _|              \      {  ( \^)
 \                \     \  \  \|
  \                \     \  \
  --                \ ____)  \
 \                            \
  |                           )
___\_________________________/____________
   ..........................             ~~~~
  ............................
  .............................
 ...............................
...............................
..............................
)";
        ansfer[0] = "swan";
        //cout << "Got here 6" << endl;

        generated_picture_list[1] = R"(
                T\ T\
                | \| \
                |  |  :
           _____I__I  |
         .'            '.
       .'                '
       |   ..             '
       |  /__.            |
       :.' -'             |
      /__.                |
     /__, \               |
        |__\        _|    |
        :  '\     .'|     |
        |___|_,,,/  |     |    _..--.
     ,--_-   |     /'      \../ /  /\\
    ,'|_ I---|    7    ,,,_/ / ,  / _\\
  ,-- 7 \|  / ___..,,/   /  ,  ,_/   '-----.
 /   ,   \  |/  ,____,,,__,,__/            '\
,   ,     \__,,/                             |
| '.       _..---.._                         !.
! |      .' z_M__s. '.                        |
.:'      | (-_ _--')  :          L            !
.'.       '.  Y    _.'             \,         :
 .          '-----'                 !          .
 .           /  \                   .          .
)";
        ansfer[1] = "bruce_wane";

        generated_picture_list[2] = R"(
                              _.-="_-         _
                         _.-="   _-          | ||"""""""---._______     __..
             ___.===""""-.______-,,,,,,,,,,,,`-''----" """""       """""  __'
      __.--""     __        ,'                   o \           __        [__|
 __-""=======.--""  ""--.=================================.--""  ""--.=======:
]       [w] : /        \ : |========================|    : /        \ :  [w] :
V___________:|          |: |========================|    :|          |:   _-"
 V__________: \        / :_|=======================/_____: \        / :__-"
 -----------'  "-____-"  `-------------------------------'  "-____-"
)";
        ansfer[2] = "car";

        generated_picture_list[3] = R"(
            ______
            _\ _~-\___
    =  = ==(____AA____D
                \_____\___________________,-~~~~~~~`-.._
                /     o O o o o o O O o o o o o o O o  |\_
                `~-.__        ___..----..                  )
                      `---~~\___________/------------`````
                      =  ===(_________D
)";
        ansfer[3] = "plane";

        generated_picture_list[4] = R"(
              _-o#&&*''''?d:>b\_
          _o/"`''  '',, dMF9MMMMMHo_
       .o&#'        `"MbHMMMMMMMMMMMHo.
     .o"" '         vodM*$&&HMMMMMMMMMM?.
    ,'              $M&ood,~'`(&##MMMMMMH\
   /               ,MMMMMMM#b?#bobMMMMHMMML
  &              ?MMMMMMMMMMMMMMMMM7MMM$R*Hk
 ?$.            :MMMMMMMMMMMMMMMMMMM/HMMM|`*L
|               |MMMMMMMMMMMMMMMMMMMMbMH'   T,
$H#:            `*MMMMMMMMMMMMMMMMMMMMb#}'  `?
]MMH#             ""*""""*#MMMMMMMMMMMMM'    -
MMMMMb_                   |MMMMMMMMMMMP'     :
HMMMMMMMHo                 `MMMMMMMMMT       .
?MMMMMMMMP                  9MMMMMMMM}       -
-?MMMMMMM                  |MMMMMMMMM?,d-    '
 :|MMMMMM-                 `MMMMMMMT .M|.   :
  .9MMM[                    &MMMMM*' `'    .
   :9MMk                    `MMM#"        -
     &M}                     `          .-
      `&.                             .
        `~,   .                     ./
            . _                  .-
              '`--._,dd###pp=""
)";
        ansfer[4] = "earth";

        generated_picture_list[5] = R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

)";
        ansfer[5] = "crewmate";

        generated_picture_list[6] = R"(
     ___ ___ ___
   /___/___/___/|
  /___/___/___/||
 /___/___/__ /|/|
|   |   |   | /||
|___|___|___|/|/|
|   |   |   | /||
|___|___|___|/|/
|   |   |   | /
|___|___|___|/
)";
        ansfer[6] = "rubik's_cube";

        generated_picture_list[7] = R"(
                                 <\              _
                                  \\          _/{
                           _       \\       _-   -_
                         /{        / `\   _-     - -_
                       _~  =      ( @  \ -        -  -_
                     _- -   ~-_   \( =\ \           -  -_
                   _~  -       ~_ | 1 :\ \      _-~-_ -  -_
                 _-   -          ~  |V: \ \  _-~     ~-_-  -_
              _-~   -            /  | :  \ \            ~-_- -_
           _-~    -   _.._      {   | : _-``               ~- _-_
        _-~   -__..--~    ~-_  {   : \:}
      =~__.--~~              ~-_\  :  /
                                 \ : /__
                                //`Y'--\\
                               <+       \\
                                \\      WWW
)";
        ansfer[7] = "pterodactyl";

        generated_picture_list[8] = R"(
                 CH3
                  |
                  N
                 / \
            N---C   C==O
           ||  ||   |
           ||  ||   |
           CH   C   N--CH3
             \ / \ /            -Stuart Yeates-
              N   C
              |  ||
             CH3  O
)";
        ansfer[8] = "caffeine"; //https://www.youtube.com/watch?v=OhQfgwv7uEs // reccomend to watch it :) //Pros of having ADHD. Yea I just thought about that video and BAAM its in the code :)

        generated_picture_list[9] = R"(
                          .,aad888PPPPP888baa,.
                     ,ad88P""Y8P'         `"""Y88ba,
                 ,ad8P"'    ,8P'                 `"Y8ba,
              ,ad88P'      ,8P'                      ""Yba,
            a8P"Y8P        d8'                          `"Y8a
          a8P'  d8'        88,,,aaaaaaddd888888888bbaa,,   `Y8a
        a8P'   ,8P         8888PPP"""""""''       ``""YY88daadY8a
      ,88"     d8'         88                             ``"Y8888,
     d88"      88          88                                  `"Y8b
    888P       8I          Y8,                                    `88
   8888'       8I          `8b     ,,aaaaaaaaaaaaaaa,,             `88
  d8'88        8I           Y8badd88PP""""""""""YY88888bbaa,,,      `8b
 d8' 88        Y8,          `Y8Y""                     ``""Y888ba,   `8b
,8P  8I        "8b           `8b                              `""Y8b, Y8,
d8'  8I         Y8,           `8b                                  "Y8a8b
88   Y8,        `8b            `8b,                                  `Y88
88   I8b         Y8,            `8ba,______________                    88
88   `88,        `8b,            `Y88888888888888888bbaa,.             88
88    I8b         `8b,             88"           88""""Y88bba,         88
88     88,         "Y8,            88            88       ""888ba,     88
Y8,    `Y8,         `Y8a          ,8P           ,8P         88""Y88b, ,8P
`8b     `8b,          "8b,       ,d8'          ,8P'        ,8P    "88bd8'
 88,     "8b,          `Y8a.    ,d8'          ,d8'        ,88'      `Y88
 `8b      `Y8,           "Y8b, ,d8'          ,d8'        ,88"        d8'
  Y8,      `Y8b            "Y888P'          ,8P'        ,88"        ,8P
   Y8,       "8b,           ,d8P'          ,8P'        ,88"        ,8P
    Y8,       `Y8b,       ,d8P"           d8"         a88'        ,8P
     Y8a        "Y8ba, ,ad8P"           ,8P'         d8P'        a8P
      "8b,        "Y8888P"'           ,dP"         ,88"        ,d8"
        Y8b,,,,aad88P""            ,a8P"         ,d8P'       ,d8P
         "Y888PP""'             ,a8P"          ,a8P"      ,ad8P"
            "Y8ba,          ,ad8P"           ,a8P"     ,ad8P"
               "Y88ba, ,,ad8P"'           ,adPI'   ,ad88P"
                   "Y8888P"           ,,adPI" ,aad88P"    Normand
                       ""Y88bbbaaaadd88888bad88P""        Veilleux
                             """""""""""""""
)";
        ansfer[9] = "volleyball";

        generated_picture_list[10] = R"(
                            aaaaaaaaaa,
                            8"b,    "Ya
                            8  "b,    "Ya
                     aaaaaaa8,   "b,    "Ya
                     8"b,    "Ya   "8""""""8
                     8  "b,    "Ya  8      8
              aaaaaaa8,   "b,    "Ya8      8
    A         8"b,    "Ya   "8"""""""      8
              8  "b,    "Ya  8             8
       aaaaaa88,   "b,    "Ya8         B   8
       8"b,    "Ya   "8"""""""             8
       8  "b,    "Ya  8                    8
 8aaaaaa8,   "b,    "Ya8                   8
 8"b,    "Ya   "8"""""""                   8
 8  "b,    "Ya  8                          8
 8,   "b,    "Ya8                          8
  "Ya   "8"""""""                          8
    "Ya  8                                 8
      "Ya8          Normand Veilleux       8
        """"""""""""""""""""""""""""""""""""
)";
        ansfer[10] = "waxed_weathered_cut_copper_stairs"; //this is a minecraft block with the longest name in the game//I HATE THE CIN IT RUINS THE JOKE :( wait... //fixed :3

        //loved searching for these ascii art. I saved the credits too :)

        //int generated_number = time(0) % 11;
        int generated_number = arc4random() % 11;
        //cout << "Got here 77" << endl;

        picture = generated_picture_list[generated_number];
        main_ansfer = ansfer[generated_number];
    }

    bool authorise() //time(0) for me to not forget about that
    {

        generate_captcha();
        string userInput;
        string desktopPath = getenv("HOME"); //was forced to add forcefuly it to downloads because downloads has better filtering and i got lazy so i just copied the downloads path XD
        desktopPath += "/Desktop/";
        string fileName = "captcha.txt";
        //string desktopPath = "C:/Pobrane/"; //IF YOU WANT TO USE THE CODE IN WINDOWS REPLACE ALL DESKTOPPATHS WITH THIS
        string filePath = desktopPath + fileName;
        ofstream outFile;
        outFile.open(filePath);
        //cout << "Got here 88" << endl;

        if (!outFile)
        {
            cout << "Unable to open file: " << filePath << endl; //checks if location exists
            return false;
        }

        outFile << "Captcha: " << endl;
        outFile << picture << endl;
        outFile.close();

        int tries = 3;
        while(tries > 0)
        {
            cout << "Check desktop for the captcha!" << endl;
            cout << "You have to type in lower case otherwise it won't work!" << endl;
            cout << "If you think the ansfer is made from more than 2 words please type with _ which is in between 0 and =/+ key not - this _" << endl; //Had to make sure you DONT USE SPACES BECAUSE CIN EATS EVERYTHING BEFORE SPACED OF FRI.. COURSE
            cout << "Type the answer: ";
            cin >> userInput;
            //cout << "hahsahahsahsahsahsahsahasahsashsa  " << userInput << endl; //apparently cin deletes everything before the space XD
            cout << endl;

            if(main_ansfer == userInput)
            {
                cout << "You ansfered correctly!" << endl;
                return true;
            }
            else
            {
                cout << "Wrong code!" << endl;
                cout << "Try again! You have: " << tries - 1 << " tries left" << endl; //tries i added if you make a typo because i made a LOT OF THEM but tries in password... why am I doing it to myself i just finished making the code compatable with apple os again (mac os)
            }

            tries--;
        }
        cout << "You ARE A ROBOT!" << endl; //BEEP BOOP :3
        return false;

    }
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
        cout << "3. Captcha" << endl;
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
        case 3:
            auth = new Captcha();
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
    /*cout << R"(

)";*/ //was used if ascii art displays correcly and it does eventough it does not display correcly in terminal is does in notepat and that counts!

    App app; //remember to remove the comments from the oder code so it works too! I REMIND YOU TO CHECK IF YOU DELETED THE COMMENTS //IF YOU WANT TO USE THE CODE IN WINDOWS PRESS CTRL + F// nah rand and time(0) just suck too much so only captcha works on window. I wish c++ would have had a random generator as in python
    app.setAuth();
    app.logIn();
    return 0;
}
