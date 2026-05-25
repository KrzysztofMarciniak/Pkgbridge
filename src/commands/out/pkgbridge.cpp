#include <iostream>
#include "commands/out/pkgbridge.h"
#include "services/transform_service/transform_service.h"

int PkgbridgeOutCommand::run() {
    std::cout << "[out/pkgbridge] exporting dummy JSON IR...\n";

    TransformService::exportDummy();

    return 0;
}
