#!/bin/bash

# Generate a key pair and store it in a subdirectory
mkdir keys
cd keys

if ! test -f jenkins_agent_key;then
    echo "Generating new key pair 'jenkins_agent_key'..."
    ssh-keygen -t rsa -f jenkins_agent_key
fi

if test -f .env; then
    echo "Removing existing .env file..."
    rm .env
fi
echo "Creating .env file..."
echo "SSH_AGENT_PUB_KEY=\"__key__\"" | cat > ./.env
PubKey=$( cat jenkins_agent_key.pub )
sed -i "s|__key__|${PubKey}|g" .env
mv ./.env ../.env