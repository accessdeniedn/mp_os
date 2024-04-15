#ifndef MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H
#define MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H

#include <logger.h>
#include "client_logger_builder.h"

#include <iostream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <set>

class client_logger final :
    public logger
{
    friend class client_logger_builder;

protected:

    static std::map<std::string, std::pair<std::ofstream*, size_t>> _files_streams_all;
    std::map<std::string, std::pair<std::ofstream*, std::set<logger::severity>>> _files_streams;
   
    std::set<logger::severity> _console_streams;

    std::string _log_format;

public:

    client_logger();

    client_logger(
        client_logger const &other);

    client_logger &operator=(
        client_logger const &other);

    client_logger(
        client_logger &&other) noexcept;   //����������� - ��������� �� ��� ��� ����

    client_logger &operator=(
        client_logger &&other) noexcept;  //��������� �� �������

    ~client_logger() noexcept final;

public:

    [[nodiscard]] logger const *log(
        const std::string &message,
        logger::severity severity) const noexcept override;

protected:
    

};

#endif //MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H