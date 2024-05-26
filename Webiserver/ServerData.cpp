/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:37:13 by khaimer           #+#    #+#             */
/*   Updated: 2024/05/26 12:04:08 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerData.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void    ServerData::setServerName(std::string const& Value)
{
    this->serverName = Value;
}

void	ServerData::setHost(std::string const& Value)
{
   this->host = Value;
}

void	ServerData::setmaxBodySize(std::string const& Value)
{
    this->maxBodySize = Value;
}

void ServerData::parse_server_ports(const std::string& ports, ServerData& server) 
{
  std::string port_str = ports;

    // std::cout << port_str << "   << HERE\n";
  size_t split = port_str.find(',');
  while (split != std::string::npos) 
  {
    std::string port_number = port_str.substr(0, split);
    int port = std::atoi(port_number.c_str());
    server.ports.push_back(port);
    port_str = port_str.substr(split + 1); // Remove the extracted part from the remaining string
    split = port_str.find(',');
  }
  if (!port_str.empty()) // Handle the last port (if no comma)
  {
    int port = std::atoi(port_str.c_str());
    if (port)
        server.ports.push_back(port);
  }
}

std::string    ServerData::getMaxbodysize() const
{
    return this->maxBodySize;
}

std::string ServerData::getServerName() const
{
    return this->serverName;
}

std::string ServerData::getHost() const
{
    return this->host;
}

std::vector<int> ServerData::getPorts() const
{
    return this->ports;
}

void	ServerData::printport() //solo
{
    for (size_t i = 0; i < this->ports.size(); i++)
    {
        std::cout << this->ports[i] << " ";
    }
    std::cout << "(hosts)\n";
}

void ServerData::setLocation(const std::string& locationPath, Location* locationData)
{
    this->locations[locationPath] = locationData;
    std::cout << "KHALIL IS HERE\n";
}

