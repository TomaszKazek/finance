#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class Users
{

    vector<User> usersList;
    int userID, lastUserID;

public:
    Users();
    int getUserID();
    int getLastUserID();
    void setUserID(int u);
    int logging();
    User addUser();
    string changePassword();
    vector<User> getUsersList();
};
