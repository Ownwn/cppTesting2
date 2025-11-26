#pragma once
#include <array>
#include <string_view>
#include <vector>

#include "user.h"

constexpr std::array<std::string_view, 4> dummy_names = {"frank ocean", "marco", "the pope", "settlers of catan enjoyer"};
const std::string_view dummy_password = "password";
constexpr std::array<std::string_view, 2> song_names = {"minions", "gangnam style"};

class DataManager {
public:
    static inline std::vector<User> users;

    User create_dummy_user() {
        int index = rand() % dummy_names.size();
        User user((dummy_names[index].data()));
        for (int i = 0; i < 5; ++i) {
            user.add_rating(create_dummy_rating());
        }
        return user;
    }

    Rating create_dummy_rating() const {
        Rating r(std::rand() % 10, create_random_media());
        return r;
    }

    std::shared_ptr<Media> create_random_media() const {
        return std::make_shared<Song>("random song name here", 120, std::vector<std::string>());
    }


    void setup_random_users() {
        for (int i = 0; i < 10; ++i) {
            users.push_back(create_dummy_user());
        }
        auto admin_user = User("admin",dummy_password);
        admin_user.add_rating(create_dummy_rating());
        admin_user.add_rating(create_dummy_rating());
        users.push_back(admin_user);
    }
};
