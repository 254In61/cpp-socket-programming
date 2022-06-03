About docker
============
- Docker for Linux − It allows one to run Docker containers on the Linux OS.
- Docker Engine − It is used for building Docker images and creating Docker containers.
- Docker Hub − This is the registry which is used to host various Docker images.
- Docker Compose − This is used to define applications using multiple Docker containers.

Docker Installation
===================
- Docker is designed to run on Linux Kernerl version is 3.8 or higher. 
- Check kernel : $ uname -a
- If new install : https://www.tutorialspoint.com/docker/installing_docker_on_linux.htm
- Check version : $ docker version

Images : Pull Images >> Run images >> remove images
====================================================
- In Docker, everything is based on Images. An image is a combination of a file system and parameters.
- Log into docker hub.
- Search e.g Ubuntu
- pull the image using the command there i.e sudo docker pull jenkins
  $ docker pull ubuntu
  $ docker pull redhat/ubi8-minimal
- List docker images on the system : $ docker images
- Inspect image using : $ docker inspect <Repository>
- Remove docker image : $ docker rmi ImageID

Containers
===========
- Containers are instances of Docker images that can be run using the Docker run command. The basic purpose of Docker is to run containers.
- Running of containers is managed with the Docker run command.
- Run image : $ docker run -it ubuntu /bin/bash
   * Sudo command to ensure that it runs with root access.
   * ubuntu is the name of the image we want to download from Docker Hub and install on our Ubuntu machine.
   * ─it is used to mention that we want to run in interactive mode.
   * /bin/bash is used to run the bash shell once ubuntu is up and running.
   * The run command is used to mention that we want to create an instance of an image, which is then called a container.If the image isn't present in local system , the run command downloads from the docker hub.
- list all of the containers on the machine via the docker ps command.
  [amaseghe@fedora ~]$ docker ps
  CONTAINER ID   IMAGE     COMMAND       CREATED         STATUS         PORTS     NAMES
  734f3d2aecd6   ubuntu    "/bin/bash"   5 seconds ago   Up 4 seconds             sleepy_rosalind
  [amaseghe@fedora ~]$ 
- Check running top-level processes within a container : $ sudo docker top <CONTAINER ID>
- Stop a running container : $ docker stop <CONTAINER ID>
- Delete a container : $ docker rm ContainerID
- Remove more than 1 in 1 line : $ docker stop docker_1 docker_2 docker_3 docker_4
  The delete: $ docker rm docker_1 docker_2 docker_3 docker_4
- ** Check lifecycle design at the bottom of the page : https://www.tutorialspoint.com/docker/docker_working_with_containers.htm

- When you start a container with /bin/bash instance, the moment you exit, that container ceases to exist. But when you start the container to run a certain app/process, then it will stay up/persistent.
  $ docker run --name mynginx1 -p 80:80 -d nginx

Docker File & Own Image
=======================
- You might want to have own docker image, with certain packages intact already.
- You use the Dockerfile to build the image.
https://www.tutorialspoint.com/docker/docker_file.htm
https://www.tutorialspoint.com/docker/building_docker_files.htm

- After building your image you can upload it to public repo for others to use it .
https://www.tutorialspoint.com/docker/docker_public_repositories.htm

Sample Builds
=============
- Build a docker image for web-server : https://www.tutorialspoint.com/docker/building_web_server_docker_file.htm

Network
========
- Check here : https://www.tutorialspoint.com/docker/docker_networking.htm

Getting it to work on Ansibe for my code testing
================================================
https://faun.pub/launch-and-configure-docker-container-using-ansible-playbook-95607550623f

1) Had to install the modules. : $ ansible-galaxy collection install community.docker
https://docs.ansible.com/ansible/latest/collections/community/docker/docker_container_module.html

For My environment
========================================================

- Needed an image that create ansible hosts which can be sshd into for testing purpose.
- Found that here : https://hub.docker.com/r/rastasheep/ubuntu-sshd
- I don't need to change the root password! since these are containers to be created and destroyed after testing code.