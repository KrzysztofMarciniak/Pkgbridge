#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "ctx.h"

struct CommandInfo {
        std::string name;
        std::string description;

        std::vector<std::string> aliases;
        std::vector<std::string> examples;
};

class Command {
       public:
        virtual ~Command() = default;

        virtual CommandInfo info() const       = 0;
        virtual int run(const AppContext& ctx) = 0;
};

class CommandRegistry {
       public:
        static void add(std::unique_ptr<Command> cmd);

        static Command* find(const std::string& name);

        static const std::unordered_map<std::string, std::unique_ptr<Command>>&
        all();
};

#define REGISTER_COMMAND(ClassName)                                  \
        static bool _reg_##ClassName = []() {                        \
                CommandRegistry::add(std::make_unique<ClassName>()); \
                return true;                                         \
        }()
