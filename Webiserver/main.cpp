#include "ServerData.hpp"

int main() 
{
    std::ifstream file("ourconfig.conf");
    std::string line;

    std::vector<ServerData> servers;

    while (std::getline(file, line)) 
    {
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
                line_stream >> key;
                line_stream >> value;
                if (std::strstr(key.c_str(), "port") != nullptr)
                    server.parse_server_ports(value,server);
                else if (std::strstr(key.c_str(), "serverName") != nullptr)
                    server.setServerName(value);
                else if (std::strstr(key.c_str(), "host") != nullptr)
                    server.setHost(value);
                else if (std::strstr(key.c_str(), "maxBodySize") != nullptr)
                    server.setmaxBodySize(value);
            }
            servers.push_back(server); // Add the server to the vector of servers
        }
    }

    for (size_t i = 0; i < servers.size(); i++)
    {
        std::cout << std::endl << "[ SERVER " << i << " ]\n";
        std::cout << servers[i].getServerName() << "   << server name\n";
        std::cout << servers[i].getHost() << " << host\n";
        std::cout << servers[i].getMaxbodysize() << " <<  Max Size\n";
        servers[i].printport();
        
    }
    
    


    
    
    return 0;
}