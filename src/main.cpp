#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>
#include "commands/command.h"

int main(int argc, char** argv) {
    AppContext ctx;
    std::string CLI_APP = "pkgbridge: " + ctx.version;
    CLI::App app{CLI_APP};

    app.add_flag("-v,--verbose",
        ctx.verbose,
        "verbose mode");
    if (argc < 2){
      spdlog::error("No input. Try --help.");
    }
    for (const auto& [name, cmd] : CommandRegistry::all()) {
        auto info = cmd->info();

        auto* sub = app.add_subcommand(
            info.name,
            info.description
        );

        sub->callback([&ctx, name]() {
            auto* cmd = CommandRegistry::find(name);

            if (cmd) {
                cmd->run(ctx);
            }
        });
    }

    CLI11_PARSE(app, argc, argv);

    return 0;
}
