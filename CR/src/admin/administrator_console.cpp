#include "administrator_console.h"

AdministratorConsole::AdministratorConsole(DataBases *data_bases)
{

}

int AdministratorConsole::Run()
{
    _loadRealPassword();
    _inputPassword("Password: ");
    if(!_verifyPassword())
    {
        std::cout << "bad\n";
        return 1;
    }
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