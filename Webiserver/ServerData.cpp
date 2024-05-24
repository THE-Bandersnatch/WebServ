#include "ServerData.hpp"
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


int main() 
{
    std::ifstream file("ourconfig.conf");
    std::string line;

    std::vector<ServerData> servers;

    while (std::getline(file, line)) {
        if (line.empty()) //skip empty lines
            continue;

        if (line.find("[server]") != std::string::npos)
        {
            ServerData server; // Start of a new server block
            while (std::getline(file, line)) 
            {
                if (line.empty()) //end of server
                    break;
                std::istringstream line_stream(line);
                std::string key, value;
                if (std::getline(line_stream, key, '=')) 
                {
                    line_stream >> value;
                    std::cout << value << std::endl;
                    exit(0);
                        // key >> server.serverName;
                    // if (key.find("serverName") != std::string::npos)
                }
                        // std::getline(line_stream, server.serverName);
                //     else if (key == "port") 
                //         line_stream >> server.port;
                //     else if (key == "host")
                //         std::getline(line_stream, server.host);
                //     else if (key == "maxBodySize")
                //         line_stream >> server.maxBodySize;
                // }
            }
            servers.push_back(server); // Add the server to the vector of servers
        }
    }
    std::cout << servers[0].serverName << std::endl;

    return 0;
}