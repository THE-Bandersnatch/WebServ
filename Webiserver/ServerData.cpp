/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:37:13 by khaimer           #+#    #+#             */
/*   Updated: 2024/05/24 20:29:51 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerData.hpp"
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void    ServerData::setServerName(std::string const& Value)
{
    this->serverName = Value;
}


void ServerData::parse_server_ports(const std::string& ports, ServerData& server) 
{
  std::string port_str = ports;

  size_t split = port_str.find(',');
  while (split != std::string::npos) 
  {
    std::string port_number = port_str.substr(0, split);
    int port = std::atoi(port_number.c_str());
    server.ports.push_back(port);
    port_str = port_str.substr(split + 1); // Remove the extracted part from the remaining string
    split = port_str.find(',');
  }

  // Handle the last port (if no comma)
  if (!port_str.empty()) 
  {
    int port = std::atoi(port_str.c_str());
    if (port)
        server.ports.push_back(port);
  }
}


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
                {
                    server.parse_server_ports(value,server);
                    // for (size_t i = 0; i < server.ports.size(); i++)
                    // {
                    //     std::cout << server.ports[i] << std::endl;
                    // }
                }
                else if (std::strstr(key.c_str(), "serverName") != nullptr)
                {
                    server.setServerName(value);
                    // std::cout << server.serverName << std::endl;
                }
                else if (std::strstr(key.c_str(), "host") != nullptr)
                    server.host = value;
                else if (std::strstr(key.c_str(), "maxBodySize") != nullptr)
                    server.maxBodySize = value;
            }
            servers.push_back(server); // Add the server to the vector of servers
        }
    }
    return 0;
}



