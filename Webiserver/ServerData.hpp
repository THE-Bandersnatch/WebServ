/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:00 by bgannoun          #+#    #+#             */
/*   Updated: 2024/05/24 20:28:48 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef serverdata_hpp
#define serverdata_hpp

#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include  "fcntl.h"
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void setnonblocking(int sock);

struct Location
{
	std::string path;
	std::string root;
	std::vector<std::string> acceptedMethods;
	std::string index;
	bool autoIndex;
	std::string uploadPath;
	std::string cgiPath;
};

class ServerData{
	// private:
		std::string serverName;
		std::vector<int> ports;
	public:
		std::vector<int> servSockets; //no
		
		std::string host;
		std::string maxBodySize;

		//MaxBodySize
		// std::map<std::string, Location> locations;
		// Location loc;
		// loc.path = "fdsaf";
		// locations["/"] = loc;
		ServerData(){}
		ServerData(std::string servName, std::string ho, std::vector<int> portss);
		std::vector<int> &getServSockets();
		bool isIaSocket(int i);
		void addLocation(Location loc);
		std::string getHost() const;
		std::vector<Location> getLocation() const;
		std::vector<int> getPorts() const;
		std::string getServerName() const;
		void	setServerName(std::string const& Value);
		void parse_server_ports(const std::string& ports, ServerData& server);
};

#endif