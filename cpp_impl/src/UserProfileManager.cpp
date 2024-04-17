#include "../include/UserProfileManager.h"
#include <algorithm>

void UserProfileManager::addUser(const std::string& name, const std::string& email) {
    int id = users.empty() ? 1 : users.back().id + 1;
    users.push_back({ id, name, email });
}

void UserProfileManager::removeUser(int userId) {
    users.erase(std::remove_if(users.begin(), users.end(), [userId](const UserInfo& user) {
        return user.id == userId;
    }), users.end());
}

void UserProfileManager::updateUser(int userId, const std::string& newName, const std::string& newEmail) {
    for (auto& user : users) {
        if (user.id == userId) {
            if (!newName.empty()) {
                user.name = newName;
            }
            if (!newEmail.empty()) {
                user.email = newEmail;
            }
            break; // No need to continue searching
        }
    }
}

std::vector<UserInfo> UserProfileManager::findUserByName(const std::string& name) {
    std::vector<UserInfo> foundUsers;
    for (const auto& user : users) {
        if (user.name.find(name) != std::string::npos) {
            foundUsers.push_back(user);
        }
    }
    return foundUsers;
}

std::vector<UserInfo> UserProfileManager::getAllUsers() {
    return users;
}

