#include "../include/server.hpp"

server::server(boost::asio::io_context& io_context, short port) 
    :  m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)) {
        do_accept();
    }

void server::do_accept() {
    m_acceptor.async_accept([this](boost::system::error_code error_code, tcp::socket socket){
        if (!error_code) {
            std::cout << "creating session on this endpoint: " << socket.remote_endpoint().address().to_string() 
                      << ": " << socket.remote_endpoint().port() << std::endl;
            
            std::make_shared<session>(std::move(socket))->run();
        } else {
            std::cout << "Error while accepting connection: " << error_code.message() << std::endl;
        }

        do_accept();
    });
}