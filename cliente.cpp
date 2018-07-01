
#include "crip.cpp"

int main(int argc, char* argv[]) {
	struct sockaddr_in socketservidor;
	socketservidor.sin_family = AF_INET;
	socketservidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	socketservidor.sin_port = htons(8080);

	int cliente = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(cliente, (struct sockaddr*) &socketservidor, sizeof(socketservidor)) != 0) {
		perror("Nao pode conectar");
		return 1;
	}
	printf("\n\n");

	while (1) {
		char msg[1000];
		
		printf("\t Digite sua mensagem: ");
		fflush(stdin);
		fgets (msg, 1001, stdin);
		
		string msg2 = msg;
		string cipher = encryptRailFence(msg2);
		char * tab2 = new char [cipher.length()+1];
		strcpy (tab2, cipher.c_str());
		printf("\tCodificado cliente: %s\n\n", tab2);

		send(cliente, tab2, strlen(msg), 0);
		printf("\n\n");
	}

	return 0;
}
