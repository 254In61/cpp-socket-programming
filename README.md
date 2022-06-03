Overview
========
Building sockets between client<> server setup using C++

This project is a base upon which MySQL querry from the client end-points can be perfomed through the server.
Only the server will be able to interract with the MySQL DB in the background.


How to run
==========
- Confirm the IP address of your server end and edit the client.cpp accordingly.
- Ensure the port chosen is a free one, available.
- To run server :
  $ g++ -o compiled-server server.cpp
  ./compiled-server

- To run client :
  $ g++ -o compiled-client client.cpp
  ./compiled-client


Testing
=======
- Client.cpp is tested on docker containers.
- Containers are dynamically created, code run on them, then destroyed.
- To build image, check docker-test-environment/Dockerfile

Author
=======
254in61

