#include "cli/command_router.h"
#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
    spdlog::info("pkgbridge started");
    CLI::App app{"pkgbridge"};
    bool verbose = false;
    app.add_flag("-v", verbose, "verbose mode");

    CLI11_PARSE(app, argc, argv);

//    return CommandRouter::run(argc, argv);
}
