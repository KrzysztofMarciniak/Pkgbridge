#pragma once

#include "commands/command.h"

class PkgbridgeOutCommand : public Command {
       public:
        CommandInfo info() const override;

        int run(const AppContext& ctx) override;
};
