#include <spdlog/spdlog.h>

#include "commands/help/help.h"

CommandInfo HelpCommand::info() const {
    return {
        "help",
        "Show help menu",
        {"-h", "--help"},
        {"pkgbridge help"}
    };
}

int HelpCommand::run(const AppContext& ctx) {
    if (ctx.verbose) {
        spdlog::info("[HelpCommand::run]");
    }

    spdlog::info("pkgbridge help:");

    for (const auto& [name, cmd] : CommandRegistry::all()) {
        auto info = cmd->info();

        spdlog::info("  {} - {}", info.name, info.description);
    }

    return 0;
}

REGISTER_COMMAND(HelpCommand);
