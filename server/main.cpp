#include "include/server.hpp"

int main() {
    boost::asio::io_context io_context;
    server server(io_context, 55555);
    io_context.run();
    
    return 0;
}