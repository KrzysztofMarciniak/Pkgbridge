#pragma once

#include <string>

struct AppContext {
        bool verbose{false};
        std::string version{"0.0.1"};
        std::string log_file;

    bool has_log() const {
        return !log_file.empty();
    }
};
