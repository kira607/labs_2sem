#ifndef COURSEWORK_ADMINISTRATOR_CONSOLE_H
#define COURSEWORK_ADMINISTRATOR_CONSOLE_H

#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

#include "sha256/sha256.h"
#include "../common/dbs.h"

struct AdministratorConsole
{
    std::string password;
    std::string real_password;

    const char BACKSPACE=127;
    const char RETURN=10;

    DataBases *dbs

    AdministratorConsole() = default;
    explicit AdministratorConsole(DataBases *data_bases);
    int Run();

    void _loadRealPassword();
    static int _getch();
    void _inputPassword(const std::string &prompt, bool show_asterisk=true);
    bool _verifyPassword() const;
};

#endif //COURSEWORK_ADMINISTRATOR_CONSOLE_H
