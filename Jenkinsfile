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
                sh 'ansible-playbook site.yml'
            }
        }
        stage('Deploy') {
            steps {
                sh 'ansible-playbook site.yml'
            }
        }
    }
}