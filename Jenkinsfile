#!groovy
pipeline {
    agent {label 'C'}
    stages {
        stage('setup') {
            steps {
                echo 'Jenkins: Installing prerequisites...'
                dir("tools")
                {
                    sh 'chmod +x install_sdl.sh'
                    sh './install_sdl.sh'
                }
            }
        }
        stage('build') {
            steps {
                echo 'Jenkins: Building...'
                dir("samples/hello_world") {
                    sh 'make'
                    archiveArtifacts artifacts: '**/bin/*', fingerprint: true
                }
                dir("samples/sdl_hello") {
                    sh 'make'
                    archiveArtifacts artifacts: '**/bin/*', fingerprint: true
                }
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
                    archiveArtifacts artifacts: '**/bin/*', fingerprint: true
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