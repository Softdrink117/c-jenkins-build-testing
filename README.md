# c-jenkins-build-testing
 Testing of Jenkins-based automated build chain for C projects

 Inspired by and adapted from https://medium.com/@bianca_ionescu99/run-jenkins-in-docker-container-for-c-c-projects-652dfa924a

The main purpose of this repo is to demonstrate a basic Agent configuration that can support C projects.

## Setup

- Launch Jenkins Dashboard, either from an existing instance or using the Compose project
    - Make sure that necessary plugins are installed:
        - SSH Agent Plugin
        - SSH Build Agents Plugin
        - SSH Credentials Plugin
- Launch the Agent Compose project
    - Make sure that the Agent is on the same Docker network as the Dashboard, or is otherwise able to communicate with it
    - Set up the Agent as a Node in Jenkins. This guide is designed around a simple deployment on a permanent machine, rather than dynamically created instances.
        - Jenkins Page -> Manage Jenkins -> Manage Nodes and Clouds -> New Node
            - Set "Remote Root Directory"; recommended value is `/home/jenkins/agent`
            - Set "Launch Method" to "Launch agents via SSH"
            - There are multiple ways to authenticate the SSH keys; for a simple deployment, Manual Trust is recommended:
                > Configure Agent -> Launch Method -> Manually trusted key verification strategy

## Notes

Sometimes the default bitnami username/password combination is actually `user`/`bitnami` instead of the `admin`/`bitnami` specified by the environment variables. I'm not entirely sure what causes this, but it's not a major issue since the default credentials should be changed immediately in any real production scenario.

## Test Project Additional Setup

To build the Hello World test project, the following additional configuration is needed:

- Jenkins Plugins:
    - Pipeline
    - Pipeline: API
    - Pipeline: Job
    - Git
    - Github

## Other Recommended Plugins

- Safe Restart
- Folders