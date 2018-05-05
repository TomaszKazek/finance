#include <iostream>
#include <fstream>
#include "User.h"

using namespace std;

class FileUsers
{

public:
    void addUser(User newUser);
    void changePassword (string newPassword, int userID);
};
