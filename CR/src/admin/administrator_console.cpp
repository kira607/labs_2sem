#include "administrator_console.h"

AdministratorConsole::AdministratorConsole(DataBases *data_bases)
{
    dbs = data_bases;
}

int AdministratorConsole::Run()
{
    _loadRealPassword();
    _inputPassword("Password: ");
    if(!_verifyPassword())
    {
        std::cout << "Incorrect password!\n";
        return 1;
    }

    return _mainMenu();
}

void AdministratorConsole::_loadRealPassword()
{
    std::ifstream fin("../.pass");

    if(!fin)
    {
        std::cerr << ".pass does not exist!\n";
    }
    fin >> real_password;
}

int AdministratorConsole::_getch()
{
    int ch;
    termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);

    return ch;
}

void AdministratorConsole::_inputPassword(const std::string &prompt, bool show_asterisk)
{
    std::cout << prompt;

    unsigned char ch=0;
    while((ch=_getch())!=RETURN)
    {
        if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                    std::cout << "\b \b";
                password.resize(password.length()-1);
            }
        }
        else
        {
            password += ch;
            if(show_asterisk)
                std::cout <<'*';
        }
    }
    std::cout << "\n";
}

bool AdministratorConsole::_verifyPassword() const
{
    std::string hashed_password = sha256(password);
    return hashed_password == real_password;
}

int AdministratorConsole::_mainMenu()
{
    while(true)
    {
        std::cout << "Choose Data Base" << "\n";
        std::cout << "1 Truck" << "\n";
        std::cout << "2 Driver" << "\n";
        std::cout << "3 Route" << "\n";
        std::cout << "0 Exit" << "\n";

        int option = Input("Input: ", 0, 3);
        switch (option)
        {
            case 1: _truckMenu(); break;
            case 2: _driverMenu(); break;
            case 3: _routeMenu(); break;
            case 0: return 0;
            default: std::cout << "\nIncorrect input\n\n";
        }
    }
}

void AdministratorConsole::_truckMenu()
{
    while(true)
    {
        std::cout << "Truck Data Base" << "\n";
        std::cout << "1 Print all" << "\n";
        std::cout << "2 Edit" << "\n";
        std::cout << "0 Exit" << "\n";

        int option = Input("Input: ", 0, 2);
        switch (option)
        {
            case 1: dbs->truck_db.PrintAll(); break;
            case 2:
            {
                int index = Input("Choose item by index: ", 1, dbs->truck_db.list.size);
                dbs->truck_db.Edit(index - 1);
                break;
            }
            case 0: return;
            default: std::cout << "\nIncorrect input\n\n";
        }
    }
}

void AdministratorConsole::_driverMenu()
{
    while(true)
    {
        std::cout << "Truck Data Base" << "\n";
        std::cout << "1 Print all" << "\n";
        std::cout << "2 Edit" << "\n";
        std::cout << "0 Exit" << "\n";

        int option = Input("Input: ", 0, 2);
        switch (option)
        {
            case 1: dbs->driver_db.PrintAll(); break;
            case 2:
            {
                int index = Input("Choose item by index: ", 1, dbs->driver_db.list.size);
                dbs->driver_db.Edit(index - 1);
                break;
            }
            case 0: return;
            default: std::cout << "\nIncorrect input\n\n";
        }
    }
}

void AdministratorConsole::_routeMenu()
{
    while(true)
    {
        std::cout << "Truck Data Base" << "\n";
        std::cout << "1 Print all" << "\n";
        std::cout << "2 Edit" << "\n";
        std::cout << "0 Exit" << "\n";

        int option = Input("Input: ", 0, 2);
        switch (option)
        {
            case 1: dbs->route_db.PrintAll(); break;
            case 2:
            {
                int index = Input("Choose item by index: ", 1, dbs->route_db.list.size);
                dbs->route_db.Edit(index - 1);
                break;
            }
            case 0: return;
            default: std::cout << "\nIncorrect input\n\n";
        }
    }
}
