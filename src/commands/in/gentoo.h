#pragma once

#include "commands/command.h"

class GentooInCommand : public Command {
public:
    CommandInfo info() const override;

    int run(const AppContext& ctx) override;
};
