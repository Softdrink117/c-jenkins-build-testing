#!groovy
pipeline {
    agent {label 'C'}
    stages {
        stage('build') {
            steps {
                echo 'Jenkins: Building...'
                dir("samples/hello_world") {
                    sh 'make'
                    echo 'Hello World build finished'
                }
                dir("samples/sdl_hello") {
                    sh 'make'
                    echo 'SDL build finished'
                }
                archiveArtifacts artifacts: '**/bin/*', fingerprint: true
            }
        }
        stage('test') {
            steps {
                echo 'Jenkins: Testing...'
                dir("samples/hello_world") {
                    sh 'make run'
                }
                dir("samples/sdl_hello") {
                    sh 'make run'
                }
            }
        }
        stage('deploy') {
            when {
                expression {
                    currentBuild.result == null || currentBuild.result == 'SUCCESS'
                }
            }
            steps {
                echo 'Jenkins: Deploy...'
                echo 'Deploy test stub'
            }
        }
    }
    post {
        always {
            echo 'Jenkins: Pipeline finished.'
        }
    }
}