# An official Jenkins image provided by Jenkins
FROM jenkins/ssh-agent 
# Set the user to root to have unrestricted access to all files and commands on the system
# This is not good practice and is only done for testing and example purposes.
USER root 

# Install Dependencies
RUN apt-get update && apt-get install git && apt-get install cmake gcc -y
RUN apt-get update && apt-get install build-essential -y
RUN apt-get update && apt-get install ca-certificates -y