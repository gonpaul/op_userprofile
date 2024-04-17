#include <iostream>
#include "../include/UserProfileManager.h"

int main() {
    UserProfileManager profileManager;

    profileManager.addUser("Alice", "alice@example.com");
    profileManager.addUser("Bob", "bob@example.com");

    std::cout << "All Users:\n";
    for (const auto& user : profileManager.getAllUsers()) {
        std::cout << "ID: " << user.id << ", Name: " << user.name << ", Email: " << user.email << '\n';
    }

    profileManager.updateUser(1, "Alicia", ""); // Update Alice's name to Alicia
    profileManager.removeUser(2); // Remove Bob

    std::cout << "Users with 'Ali' in name:\n";
    for (const auto& user : profileManager.findUserByName("Ali")) {
        std::cout << "ID: " << user.id << ", Name: " << user.name << ", Email: " << user.email << '\n';
    }

    return 0;
}

