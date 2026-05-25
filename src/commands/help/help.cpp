#include <iostream>
#include "commands/help/help.h"

int HelpCommand::run() {
    std::cout << "pkgbridge help:\n";
    std::cout << "  help\n";
    std::cout << "  in-gentoo\n";
    std::cout << "  out-pkgbridge\n";
    return 0;
}
