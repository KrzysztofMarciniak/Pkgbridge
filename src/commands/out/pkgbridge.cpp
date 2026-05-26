#include <iostream>

#include "commands/out/pkgbridge.h"
#include "services/transform_service/transform_service.h"

CommandInfo PkgbridgeOutCommand::info() const {
    return {
        "out-pkgbridge",
        "Export IR as pkgbridge JSON format",
        {},
        {"pkgbridge out pkgbridge"}
    };
}

int PkgbridgeOutCommand::run(const AppContext& ctx) {
    if (ctx.verbose) {
        std::cout << "[verbose] exporting pkgbridge IR\n";
    }

    std::cout << "[out/pkgbridge] exporting dummy JSON IR...\n";

    TransformService::exportDummy();

    return 0;
}

REGISTER_COMMAND(PkgbridgeOutCommand);
