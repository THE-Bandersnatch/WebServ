42 Webserver Project: Mini_serv
Overview
This project involves creating a simple, non-blocking web server that listens for client connections, assigns unique IDs to clients, and facilitates communication between them. The goal is to gain hands-on experience in handling low-level networking using sockets, mastering the select function, and ensuring robust error handling. This README serves as a guide to understanding, setting up, and running the project.

Features
Non-Blocking Server:

Handles multiple clients concurrently using the select() system call.
Ensures smooth communication without blocking the server's main loop.
Dynamic Client Management:

Assigns unique IDs to connected clients.
Tracks active connections and cleanly handles disconnections.
Message Broadcasting:

Relays messages from one client to all other connected clients.
Ensures that client-server interactions are efficient and responsive.
Error Handling:

Robust error reporting for socket creation, binding, and runtime exceptions.
Graceful shutdown on unexpected errors.
Learning Objectives
Master low-level networking concepts, including sockets and file descriptors.
Implement event-driven programming using select().
Build a foundational understanding of how web servers handle concurrent connections.
Getting Started
Prerequisites
A Unix-based operating system (e.g., Linux, macOS).
GCC compiler (to compile the server code).
Basic knowledge of C programming and networking.
Installation
Clone this repository:

bash
Copier le code
git clone https://github.com/your-username/mini_serv.git
cd mini_serv
Compile the server:

bash
Copier le code
gcc -Wall -Wextra -Werror mini_serv.c -o mini_serv
Usage
Start the Server:
Run the server with a specified port number:

bash
Copier le code
./mini_serv <port_number>
Example:

bash
Copier le code
./mini_serv 8080
Connect Clients:
Use tools like telnet to connect to the server:

bash
Copier le code
telnet 127.0.0.1 8080
Interaction:

Each client is assigned a unique ID upon connection.
Messages sent by one client are broadcasted to all others.
Error Handling
If the server fails to start, check for:
Correct port availability.
Sufficient user permissions.
Debugging logs are printed to stderr.
Project Structure
bash
Copier le code
mini_serv/
├── mini_serv.c        # Main server implementation
├── Makefile           # Optional: Automate compilation
└── README.md          # Project documentation
Example Output
Server Startup:

arduino
Copier le code
Server started on port 8080
Waiting for connections...
Client Connection:

arduino
Copier le code
Client 0 connected
Client 1 connected
Broadcast Message:

arduino
Copier le code
Client 0: Hello, everyone!
Client 1: Hi, Client 0!
Future Enhancements
Add support for advanced features like HTTP protocol.
Implement secure communication using SSL/TLS.
Optimize performance for handling hundreds of connections.
For any queries or issues, feel free to open a pull request or contact me directly. Let's build a robust web server! 🚀
