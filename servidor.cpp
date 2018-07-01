
#include "crip.cpp"

int main(int argc, char* argv[]) {

	struct sockaddr_in socketservidor;
	socketservidor.sin_family = AF_INET;
	socketservidor.sin_addr.s_addr = INADDR_ANY;
	socketservidor.sin_port = htons(8080);

	char *buffer;

	buffer = (char*)malloc(sizeof(char)*1000);

	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	int activado = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

	if (bind(servidor, (struct sockaddr*)&socketservidor, sizeof(socketservidor)) != 0) {
		perror("Falha bind");
		return 1;
	}

	printf("\n\t   Aguardando conexao......  \n");
	listen(servidor, 100);

	//------------------------------

	struct sockaddr_in clientesock;
	unsigned int tam;
	int cliente = accept(servidor, (struct sockaddr*) &clientesock, &tam);

	printf("\n\t Conexao recebida de [%d]\n", cliente);
	send(cliente, "Ola cliente!", 13, 0);
	send(cliente, ":)\n", 4, 0);

	//------------------------------

	printf("\n\n");
	while (1) {
		int bytesRecibidos = recv(cliente, buffer, 1001, 0);
		if (bytesRecibidos <= 0) {
			perror("Desconectado");
			return 1;
		}
		fflush(stdin);
		string str = sconvert(buffer, bytesRecibidos);
		printf("\tCodificado servidor: %s\n\n", str.c_str());
		//printf("%s\n", cipher.c_str());
		str[bytesRecibidos] = '\0';
		printf("\tRecebido %d bytes mensagem => ", bytesRecibidos);
		cout << "Decodificado: "<< decryptRailFence(str) << endl;
		printf("\n");
	}

	free(buffer);

	return 0;
}
