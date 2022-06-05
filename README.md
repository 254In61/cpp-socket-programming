Overview
========

Building sockets between client<> server setup using C++

This project is a base upon which MySQL querry from the client end-points can be perfomed through the server. Only the server will be able to interract with the MySQL DB in the background.

How to run
===========
Confirm the IP address of your server end and edit the client.cpp accordingly.

Ensure the port chosen is a free one, available.

To run server : $ g++ -o compiled-server server.cpp && ./compiled-server

To run client : $ 

Local dev testing
=================
Step 1 : Upload your code to the git repository
Step 2 : Edit the group_vars/all_vars.yml file to reflect your values.
Step 3 : Build the docker image by following instructions on Dockerfile
Step 4 : Fire off the test : $ ansible-playbook site.yml


CI/CD
=====
- Jenkins is used for the CI/CD process
- **Unittesting of classes and functions is yet to be developed.
- Unittest-server build starts first.
- ** server has to be started and left in up state for the next steps to work.
     currently running it with a shell script from home directory **
- Unittest-client build comes second after unittest-server succeeds.
- end-to-end integration-testing is done using ansible playbook, site.yml where client code is run from 
  docker containers to simulate different clients communicating with server.

Author
======
254in61