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
    }
    post {
        always {
            echo 'Jenkins: Pipeline finished.'
        }
    }
}