pipeline { 
    agent any 
    options {
        skipStagesAfterUnstable()
    }
    stages {
        stage('Build') { 
            steps { 
                sh 'g++ -o compiled-server server.cpp && ./compiled-server' 
            }
        }
        stage('Test'){
            steps {
                sh 'g++ -o compiled-client client.cpp && ./compiled-client'
            }
        }
        stage('Deploy') {
            steps {
                sh 'ansible-playbook site.yml'
            }
        }
    }
}