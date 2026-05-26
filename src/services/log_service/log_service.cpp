#include "services/log_service/log_service.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

void LogService::init(const AppContext& ctx) {
    std::vector<spdlog::sink_ptr> sinks;

    sinks.push_back(
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
    );

    if (ctx.has_log()) {
        try {
            sinks.push_back(
                std::make_shared<spdlog::sinks::basic_file_sink_mt>(
                    ctx.log_file, true
                )
            );
        } catch (const spdlog::spdlog_ex& e) {
            spdlog::error("failed to open log file '{}': {}", ctx.log_file, e.what());
            std::exit(1);
        }
    }

    auto logger = std::make_shared<spdlog::logger>(
        "pkgbridge",
        begin(sinks),
        end(sinks)
    );

    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info);
    spdlog::flush_on(spdlog::level::info);
}
