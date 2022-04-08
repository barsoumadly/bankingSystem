#include <string>

#ifndef _APPLICATION_H
#define _APPLICATION_H
using namespace std;

class Application {
private:
    static void option_list();

    static void perform_command(string &command);

    static string choose_command();

public:
    static void start();
};


#endif //_APPLICATION_H
