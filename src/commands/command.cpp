#include "commands/command.h"

static std::unordered_map<std::string, std::unique_ptr<Command>> g_commands;

void CommandRegistry::add(std::unique_ptr<Command> cmd) {
        auto name = cmd->info().name;

        g_commands[name] = std::move(cmd);
}

Command* CommandRegistry::find(const std::string& name) {
        auto it = g_commands.find(name);

        if (it == g_commands.end()) {
                return nullptr;
        }

        return it->second.get();
}

const std::unordered_map<std::string, std::unique_ptr<Command>>&
CommandRegistry::all() {
        return g_commands;
}
