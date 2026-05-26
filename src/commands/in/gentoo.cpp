#include <iostream>

#include "commands/in/gentoo.h"
#include "services/package_service/package_service.h"

CommandInfo GentooInCommand::info() const {
    return {
        "in-gentoo",
        "Parse Gentoo ebuild into IR",
        {},
        {"pkgbridge in gentoo"}
    };
}

int GentooInCommand::run(const AppContext& ctx) {
    if (ctx.verbose) {
        std::cout << "[verbose] running gentoo parser\n";
    }

    std::cout << "[in/gentoo] parsing dummy gentoo package...\n";

    PackageService::loadDummy();

    return 0;
}

REGISTER_COMMAND(GentooInCommand);
