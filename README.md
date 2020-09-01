# Coding Challenge: API da 42 em C <br>

Primeiro é necessário colocar as suas chaves (UID e SECRET) no o arquivo studen_data.h (linhas 31 e 32)<br>
Aplicação CLI para busca de alunos utilizando a api da 42 (https://api.intra.42.fr/)<br>
A aplicação recebe:<br>
1. Um argumento:<br>
intra **id** de um determinado aluno<br>
retorna o **máximo de informações possíveis** sobre o aluno<br>
**ou**<br>
2. Dois argumentos:<br>
intra **id** de um determinado aluno e **dado** a ser buscado<br>
retorna a **resposta para o dado específico**<br>

A aplicação foi construída em C, utilizando as bibliotecas curl, stdio, unistd, fcntl, stdlib e string<br>
A aplicação pode ser **executada de duas maneiras**, de acordo com a pasta selecionada: **student_data ou student_data_conteiner**<br>

## student_data <br>
Se trata da aplicação CLI *sem a conteinerização* <br>
![Alt text](https://leopard.in.ua/presentations/rubyc_2015/pictures/docker-cons.png?raw=true "")

Digite no terminal: <br>
**cd student_data** *para ir para a pasta correta*<br>
**make**  *para gerar o executável student-search*<br>
**./student-search "intra_id do aluno a ser buscado"**  *para todos os dados do aluno*<br>
**./student-search "intra_id do aluno a ser buscado" "dado a ser buscado"** *para o dado específico do aluno*<br>
<br>
**make clean**  *caso queira deletar o executável e os dados*<br>

## student_data_conteiner <br>
Se trata da mesma aplicação conteinerizada em um ambiente com Debian Buster OS e tools necessários para execução<br>
Para execução da aplicação é necessária a instalação do Docker (https://docs.docker.com/get-docker/)<br>
<br>
![Alt text](https://blog.justdigital.com.br/wp-content/uploads/images/blog/docker-whale-logo.png?raw=true "")

Digite no terminal: <br>
**cd student_data_cointeiner**  *para ir para a pasta correta*<br>
**docker build -t "nome_da_imagem" .**  *para criar a imagem*<br>
**docker run --name "nome_do_conteiner" -it "nome_da_imagem"**  *para executar o conteiner no terminal*<br>
**cd student_data** *para ir para a pasta da aplicação dentro do conteiner*<br>
**make**  *para gerar o executável student-search*<br>
**./student-search "intra_id do aluno a ser buscado"**  *para todos os dados do aluno*<br>
**./student-search "intra_id do aluno a ser buscado" "dado a ser buscado"** *para o dado específico do aluno*<br>
<br>
**make clean**  *caso queira deletar o executável e os dados*<br>
**exit**  *para sair do conteiner*

## exemplos de dados específicos a serem buscados no segundo argumento
id<br>
email<br>
login<br>
first_name<br>
last_name<br>
url<br>
phone<br>
displayname<br>
image_url<br>
staff<br>
correction_point<br>
pool_month<br>
pool_year<br>
location<br>
wallet<br>
level<br>
anonymize_date<br>
