## SSH Key setup
In this directory, create an ssh public/private key pair using `ssh-keygen` that will be used to authenticate the agent to the dashboard.

## Automatic Setup

Make sure the generate_keys script is executable:
`chmod +x generate_keys.sh`
Run the script:
`./generate_keys.sh`

## Manual Setup

Create a "keys" directory, then generate the SSH keys in it:
```
mkdir keys
cd keys
ssh-keygen -t rsa -f jenkins_agent_key
```