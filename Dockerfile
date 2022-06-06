# Docker image that will have git,python3 & g++ compiler installed.
# Settled for below being the latest and runs an app not just basic /bin/bash.
# Build your docker image using this Dockerfile : $ docker build -t my-docker-image .
# Run container:  docker run -d --name nginx-container -e TZ=UTC -p 8080:80 ubuntu/nginx:1.18-22.04_beta
# https://hub.docker.com/r/ubuntu/nginx

FROM ubuntu/nginx
# RUN apt -y update && apt -y install git python3
RUN apt -y update
RUN apt -y install build-essential git