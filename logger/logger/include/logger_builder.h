#ifndef MATH_PRACTICE_AND_OPERATING_SYSTEMS_LOGGER_BUILDER_H
#define MATH_PRACTICE_AND_OPERATING_SYSTEMS_LOGGER_BUILDER_H

#include "logger.h"

class logger_builder
{

public:

    virtual ~logger_builder() noexcept = default;

public:

    virtual logger_builder *add_file_stream(
        std::string const &stream_file_path,
        logger::severity severity) = 0;

    virtual logger_builder* add_file_stream_minimal_severity(
        std::string const& stream_file_path,
        logger::severity severity) = 0;

    virtual logger_builder* add_file_stream(
        std::string const& stream_file_path,
        std::set<logger::severity> severity) = 0;

    virtual logger_builder *add_console_stream(
        logger::severity severity) = 0;

    virtual logger_builder* add_console_stream_minimal_severity(
        logger::severity severity) = 0;

    virtual logger_builder* add_console_stream(
        std::set<logger::severity> severity) = 0;

    virtual logger_builder* transform_with_configuration(
        std::string const &configuration_file_path) = 0;

    virtual logger_builder* change_message_mask(
        std::string const& mask) = 0;

    virtual logger_builder *clear() = 0;

    virtual logger *build() const = 0;

protected:

    static logger::severity string_to_severity(
        std::string const &severity_string);

};

#endif //MATH_PRACTICE_AND_OPERATING_SYSTEMS_LOGGER_BUILDER_H



