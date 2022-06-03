# Docker image that will have git,python3 & g++ compiler installed.
# Settled for below being the latest and runs an app not just basic /bin/bash.
# Build your docker image using this Dockerfile : $ docker build -t my-docker-image . 

FROM ubuntu/nginx
# RUN apt -y update && apt -y install git python3
RUN apt -y update
RUN apt -y install build-essential git