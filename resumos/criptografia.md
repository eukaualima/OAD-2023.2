# 🔐 Criptografia
Resumo da aula sobre criptografia.
### 🔍 O que é criptografia?
* É uma técnica empregada para obter **privacidade** e **autenticidade** em dados compartilhados.
* A complexidade da criptografia está ligada diretamente a **importância dos dados compartilhados**.
* A técnica consiste em transformar os dados **inteligíveis** em outros **ininteligíveis** por meio de alguma **lógica** ou **função matemática**. Podendo ser reversível ou não.
* **Quando reversível**, os dados criptografados voltam ao seu estado original por meio de uma **função** ou **lógica inversa** a aplicada na criptografia.
### 👑 Termos mais utilizados
* Texto plano
  * Equivale aos **dados em seu plano original**.
* Texto cifrado/criptografado
  * Texto plano que **já sofreu** o processo de criptografia.
* Cifra
  * Algoritmo **usado para cifrar/criptografar**.
* Cifragem
  * Ato de **submeter o texto plano** ao processo de criptografia.
* Decifragem
  * Ato de **submeter a criptografia** ao processo de decriptografia.
* Chave de criptografia
  * Conjunto de caracteres utilizados para modificar o textos cifrados diferentes ainda que sob a mesma cifra.
  * **Nem todas** as cifras possuem uma chave.
  * A chave é um **elemento modificador**, uma chave diferente resulta em uma **cifragem diferente**.
### ⚔️ Cifras de substituição
* Cifra de César
  * Uma das mais simples e remotas cifras conhecidas. Consiste em substituir cada caractere do texto plano por um correspondente em um dicionário de cifragem
    * ABCDEFGHIJKLMNOPQRSTUVWXYZ **(texto plano)**
    * DEFGHIJKLMNOPQRSTUVWXYZABC **(alfabeto de ciframento, deslocando 3)**
    * A palavra TEXTO cifrada fica WHAWR
* Cifra de Atbash
  * O alfabeto de ciframento consiste no alfabeto original invertido
    * ABCDEFGHIJKLMNOPQRSTUVWXYZ **(texto plano)**
    * ZYXWVUTSRQPONMLKJIHGFEDCBA **(alfabeto de ciframento)**
    * A palavra TEXTO cifrada fica GVCGK
### 🔑 Cifras de substituição com palavra chave
* Escolhe-se uma palavra sem letras repetidas
* A chave será o início do alfabeto de ciframento e as letras seguintes seguem a ordem natural do alfabeto, excluindo as que já estão na chave
  * Ex: Palavra chave **ADILSON**
    * ABCDEFGHIJKLMNOPQRSTUVWXYZ **(texto plano)**
    * **ADILSON**BCEFGHJKMPQRTUVWXYZ **(texto de ciframento)**
    * A palavra TEXTO cifrada fica TOXTK
### 〰️ Cifras de transposição geométrica
* Tranposição geométrica
  * Entrada por linha e saída por coluna
  * O texto plano é inserido em uma matriz ocupando linha a linha
  * O texto cifrado é retirado pelas colunas da matriz preenchida
    * Ex: Utilizando uma matriz 5X5 cifrar a frase ORGANIZAÇÃO DE ARQUIVOS
      * Texto cifrado : OIOAVRZ ROGADQSAÇEUXNÃ IX

![image](https://github.com/eukaualima/OAD-2023.2/assets/59632185/5b9c12c8-4fe3-4ef2-8add-26be307c412b) ![image](https://github.com/eukaualima/OAD-2023.2/assets/59632185/c1d1d069-f053-44af-9ccb-b7b1e280d02c)
### 💻 Cifras digitais
* As operações são feitas entre bits de um determinado símbolo
* Utilizado em dispositivos digitais como computadores
* Podem ser usados operadores lógicos somados a uma chave para obter o texto cifrado
* Ex: Cifrar 00110100 utilizando como chave 11110010 e operador XOR
  * Sequencia cifrada: 11000110
* Ex: Cifrar 00110100 utilizando como chave 11110010 e operador AND
  * 00110000
* Ex: Cifrar 00110100 utilizando como chave 11110010 e operador OR
  * 11110110
* Ex: Cifrar 00110100 utilizando operador NOT (Aqui não é possível utilizar chave, pois NOT é unário)
  * 11001011
### 🪬 Cifras digitais de cifra assimétrica
* Cifras com maior grau de complexidade
* A chave de ciframento é diferente da chave de deciframento
* Normalmente, a chave de ciframento é conhecida por chave pública e a chave de deciframento, chave privada
* O principal algoritmo de chave assimétrica conhecido é o RSA (Rivest, Shalmir, Adleman)
  * Ambas as chaves relacionam-se entre si por corresponderem a números primos
  * O algoritmo RSA consiste nos seguintes passos
    * Escolha 2 números primos (p e q)
    * n = p x q
    * Calcule z = (p - 1) x (q - 1)
    * Encontre um número primo em relação a **z** e chame-o de **e**
    * Encontra d = e - 1 % z
    * A chave pública consiste no par {e, n} e a chave privada em {d, n}
