#pragma once

#include <iostream>

#include <boost/asio.hpp>

#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>

using boost::asio::ip::tcp;


class session : public std::enable_shared_from_this<session> {
public:
    session(tcp::socket socket) 
        : m_socket(std::move(socket)) {}

    void run();

private:
    void wait_for_connection();

private:
    tcp::socket m_socket;
    boost::asio::streambuf m_buffer;
};