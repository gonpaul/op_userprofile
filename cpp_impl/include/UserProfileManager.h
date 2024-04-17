#ifndef USERPROFILEMANAGER_H
#define USERPROFILEMANAGER_H

#include "UserInfo.h"
#include <vector>
#include <string>

class UserProfileManager {
public:
    static std::vector<UserInfo> users;

    static void addUser(const std::string& name, const std::string& email);
    static void removeUser(int userId);
    static void updateUser(int userId, const std::string& newName, const std::string& newEmail);
    static std::vector<UserInfo> findUserByName(const std::string& name);
    static std::vector<UserInfo> getAllUsers();
};

#endif // USERPROFILEMANAGER_H

