#pragma once 

#include <iostream>
#include <memory>
#include <utility>

#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/basic_socket_acceptor.hpp>

#include <boost/system/system_error.hpp>
#include <boost/system/error_code.hpp>

#include "session.hpp"

using boost::asio::ip::tcp;

class server {
public:
    server(boost::asio::io_context& io_context, short port);

private:
    void do_accept();

private:
    tcp::acceptor m_acceptor;
};