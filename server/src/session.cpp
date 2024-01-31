#include "../include/session.hpp"

void session::wait_for_connection() {
    auto self(shared_from_this());

    boost::asio::async_read_until(m_socket, m_buffer, "\0", 
    [this, self](boost::system::error_code error_code, size_t lenght){
        if (!error_code) {
            std::string data;
            boost::asio::buffer_copy(boost::asio::buffer(data), m_buffer.data());

            std::cout << data << std::endl;
            wait_for_connection();
        } else {
            std::cout << "Error while accepting connection: " << error_code.message() << std::endl;
        }
    });
}

void session::run() {
    wait_for_connection();
}