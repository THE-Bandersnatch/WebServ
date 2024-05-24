/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:00 by bgannoun          #+#    #+#             */
/*   Updated: 2024/05/24 23:45:22 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
	private:
		// std::vector<int> servSockets; //no
		std::string serverName;
		std::vector<int> ports;
		std::string host;
		std::string maxBodySize;
		Location data;
	public:
		void	setServerName(std::string const& Value);
		void	setHost(std::string const& Value);
		void	setmaxBodySize(std::string const& Value);
		void	parse_server_ports(const std::string& ports, ServerData& server);
		std::string		getMaxbodysize() const;
		std::string getHost() const;
		std::string getServerName()const;
		std::vector<int> getPorts() const;

		void	printport();
		
};


		// std::map<std::string, Location> locations;
		// Location loc;
		// loc.path = "fdsaf";
		// locations["/"] = loc;
		