#!groovy
pipeline {
    agent {label 'C'}
    stages {
        stage('build') {
            steps {
                echo 'Jenkins: Building...'
                dir("samples/hello_world") {
                    sh 'make'
                }
            }
        }
        stage('test') {
            steps {
                echo 'Jenkins: Testing...'
                dir("samples/hello_world") {
                    sh 'make run'
                }
            }
        }
    }
    post {
        always {
            echo 'Jenkins: Pipeline finished.'
        }
    }
}