# Soma matriz com threads
Repositorio com programa em C com finalidade de somar valores de uma matriz com N threads usando a trava mutex para evitar problemas de acesso.   
Aluno: João Luís Queiroz Castro de Almeida  
Turma: B  
Período: 3  
Cadeira: Infraestrutura de software  

## Para começar   

É necessario clonar o repositorio e fazer a abertura do local dos arquivos com:   

```bash
$ git clone https://github.com/joaoluis87/somaThreads.git
$ cd somaThreads
```

## Compilar o programa   

Com o repositorio aberto, é compilado o programa com o comando "make bin", onde o Makefile realizará o compilamento com "gcc main.c -o main".   

```bash
$ make bin
```

## Rodar o programa   

Já  com o programa compilado, para rodar é necessário o comando "make run", onde o Makefile utilizará do "./main".  

```bash
$ make run
```
Dessa maneira o código lerá um valor N que representa o valor de linhas e colunas da matriz, que será lida logo em seguida.
Tendo os valores armazenados na matriz, é feito por N threads a soma de cada linha e a soma geral dos valores na matriz armazenada.
Foram usadas as funções "pthread_mutex_lock(&mutex);" e "pthread_mutex_unlock(&mutex);" para garantir o acesso aos dados e fazer alterações apenas uma thread por vez.

## Finalização   

Com a conclusão do programa, o Makefile se propõe apagar o programa compilado com "rm main", para isso é preciso utilizar o comando "make clean".  

```bash
$ make clean
```