const generateId = () => {
    // Implementation of generateId function
    // For example, using a hash function and modulo operator
    for (let i = 1; i < 1000000; ++i) {
        if (!UserProfileManager.users[i - 1]) {
            return i;
        }
    }
    throw Error('No place left for you :(');
};

const UserProfileManager = {
    users: [], // Initialize users array
    addUser(userInfo) {
        const id = generateId(userInfo.email);
        this.users.push({ id, name: userInfo.name, email: userInfo.email });
    },
    removeUser(userId) {
        this.users = this.users.filter((user) => user.id !== userId);
        return this.users;
    },
    updateUser(userId, newInfo) {
        if (newInfo.name || newInfo.email) {
            this.users.forEach((user) => {
                if (user.id === userId) {
                    if (newInfo.name) {
                        user.name = newInfo.name;
                    }
                    if (newInfo.email) {
                        user.email = newInfo.email;
                    }
                    return user;
                }
            });
        }
        return this.users[userId];
    },
    findUserByName(name) {
        return this.users.filter((user) => user.name.includes(name));
    },
    getAllUsers() {
        return this.users;
    }
};

UserProfileManager.addUser({ name: "Alice", email: "alice@example.com" });
UserProfileManager.addUser({ name: "Bob", email: "bob@example.com" });

console.log(UserProfileManager.getAllUsers()); // Output information about Alice and Bob

UserProfileManager.updateUser(1, { name: "Alicia" }); // Update Alice's name to Alicia
UserProfileManager.removeUser(2); // Remove Bob

console.log(UserProfileManager.findUserByName("Ali")); // Find Alicia
