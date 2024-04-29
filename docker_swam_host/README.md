## Swarm Host Configuration

Theory is:
- One Docker container for Jenkins itself
- One Docker container running Docker-in-Docker (DinD)
- Jenkins configured to use a Docker "Cloud" build system

https://medium.com/@shivam77kushwah/docker-inside-docker-e0483c51cc2c
https://devopscube.com/docker-containers-as-build-slaves-jenkins/

Interconnect to Jenkins is based on this SO post:
https://stackoverflow.com/questions/66492160/connecting-to-docker-daemon-from-jenkins-running-inside-a-docker-container

After launching the container with docker compose up, need to set privilege for jenkins user to be able to communicate with the socket:

```docker exec Jenkins-Docker-Host chown 0:1000 /var/run/docker.sock```

This is almost working, but it doesn't meaningfully benefit my pipelines so I haven't continued to pursue it.