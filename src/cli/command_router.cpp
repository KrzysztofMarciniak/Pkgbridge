#include <iostream>
#include "cli/command_router.h"
#include "commands/help/help.h"
#include "commands/in/gentoo.h"
#include "commands/out/pkgbridge.h"
#include "metadata/version.cpp"
int CommandRouter::run(int argc, char** argv) {
    std::cout << "version: " << PKGBRIDGE_VERSION << "\n";
    if (argc < 2) {
        std::cout << "no command provided\n";
        return HelpCommand::run();
    }

    std::string cmd = argv[1];

    if (cmd == "help") {
        return HelpCommand::run();
    }

    if (cmd == "in-gentoo") {
        return GentooInCommand::run();
    }

    if (cmd == "out-pkgbridge") {
        return PkgbridgeOutCommand::run();
    }

    std::cout << "unknown command: " << cmd << "\n";
    return 1;
}
