#include <iostream>
#include "commands/in/gentoo.h"
#include "services/package_service/package_service.h"

int GentooInCommand::run() {
    std::cout << "[in/gentoo] parsing dummy gentoo package...\n";

    PackageService::loadDummy();

    return 0;
}
