#include <string>
#include <unordered_map>

#ifndef _APPLICATION_H
#define _APPLICATION_H
using namespace std;

class Application {
private:
    static void commands_list_header();

    static void commands_list();

    static string choose_command();

    static void perform_command(int command);

    static int command_string_to_integer(string &command_str);

    static void clear_console();

public:
    static void start();
};

#endif //_APPLICATION_H
