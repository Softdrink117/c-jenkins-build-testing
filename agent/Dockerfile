# An official Jenkins image provided by Jenkins
FROM jenkins/ssh-agent 
# Set the user to root to have unrestricted access to all files and commands
# while installing dependencies.
USER root 

# Install Dependencies
RUN apt-get update && apt-get install git && apt-get install cmake gcc -y
RUN apt-get update && apt-get install build-essential -y
RUN apt-get update && apt-get install ca-certificates -y

# Install extra dependencies - SDL2
RUN apt-get install -y libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev