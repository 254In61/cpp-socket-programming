pipeline { 
    agent any 
    options {
        skipStagesAfterUnstable()
    }
    stages {
        stage('Build') { 
            steps { 
                sh 'g++ -o compiled-client client.cpp && ./compiled-client' 
            }
        }
        stage('Test'){
            steps {
                sh './docker-ansible-test-run'
            }
        }
        stage('Deploy') {
            steps {
                sh './docker-ansible-test-run'
            }
        }
    }
}