#include <spdlog/spdlog.h>

#include <CLI/CLI.hpp>
#include "services/log_service/log_service.h"
#include "commands/command.h"

int main(int argc, char** argv) {
        AppContext ctx;
        std::string CLI_APP = "pkgbridge: " + ctx.version;
        CLI::App app{CLI_APP};

        app.add_flag("-v,--verbose", ctx.verbose, "verbose mode");
        app.add_option("--log", ctx.log_file, "log file path");

        if (argc < 2) {
                spdlog::error("No input. Try --help.");
                exit(1);
        }

        if (ctx.verbose) {
                spdlog::info("verbose enabled");
        }

        if (ctx.has_log()) {
          spdlog::info("logging to: {}", ctx.log_file);
        }

        for (const auto& [name, cmd] : CommandRegistry::all()) {
                auto info = cmd->info();

                auto* sub = app.add_subcommand(info.name, info.description);

                sub->callback([&ctx, name]() {
                        auto* cmd = CommandRegistry::find(name);

                        if (cmd) {
                                cmd->run(ctx);
                        }
                });
        }

        CLI11_PARSE(app, argc, argv);
        LogService::init(ctx);
        return 0;
}
