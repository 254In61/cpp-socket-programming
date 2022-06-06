// Comments here are like in C++ i.e ung // or /*  */ for comments spanning different lines.
// Ref : https://www.baeldung.com/ops/jenkinsfile-comments#:~:text=Single%2DLine%20Comments,commented%20and%20ignored%20in%20Jenkinsfile.
/*
1) pipeline : A Declarative Pipeline-specific syntax that defines a "block" containing all content and instructions for executing the entire Pipeline.
2) agent : A Declarative Pipeline-specific syntax that instructs Jenkins to allocate an executor (on a node) and workspace for the entire Pipeline.
3) stage : A syntax block that describes a stage of this Pipeline. Read more about stage blocks in Declarative Pipeline syntax on the Pipeline syntax page. As mentioned above, stage blocks are optional in Scripted Pipeline syntax.
4) steps : A Declarative Pipeline-specific syntax that describes the steps to be run in this stage.
5) sh : A Pipeline step (provided by the Pipeline: Nodes and Processes plugin) that executes the given shell command.
6) junit : another Pipeline step (provided by the JUnit plugin) for aggregating test reports.

** Pipeline made as simple as possible. To make it more complex & robust : https://www.jenkins.io/doc/book/pipeline/syntax/
*/

pipeline { 
    agent any 
    options {
        skipStagesAfterUnstable()
    }
    stages {
        stage('build-docker-containers') {
            // Build 5 docker containers
            steps { 
                sh './docker-containers-build' 
            }
        }

        stage('unit-test-server') { 
            // Test server.cpp with docker_1 running as server
            steps { 
                sh './docker-containers-unittest-server-run' 
            }
        }
        
        stage('unit-test-client') { 
            // Test client.cpp with docker_2 running as client
            steps { 
                sh './docker-containers-unittest-client-run' 
            }
        }

        stage('intergration-test-multiple-hosts'){
            // Run client.cpp across all hosts to test working
            steps {
                sh './docker-containers-multiple-clients-run'
            }
        }

        stage('delete-docker-containers'){
            // Run client.cpp across all hosts to test working
            steps {
                sh './docker-containers-delete'
            }
        }

    //     stage('Deploy'){
    //         // Deploy server.cpp and client.cpp for production
    //         steps {
    //             sh './docker-test-run'
    //         }
    //     }
    }
}