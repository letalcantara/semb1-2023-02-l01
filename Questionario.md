# Questionário Sistemas Embarcados I

## 1. Explique brevemente o que é compilação cruzada (***cross-compiling***) e para que ela serve.
R: No processo de compilação cruzada, é compilada um código em um sistema diferente para o qual o software será executado, ou seja, o host (plataforma no qual o firmware etá sendo desenvolvido)  e o target (plataforma ou arquitetura para qual o software será compilado) são diferente. 
A compilação cruzada serve para economia de recursos e tempo do projetista, uma vez que pode testar o fireware em um sistema mais complexo antes de implementá-lo.


## 2. O que é um código de inicialização ou ***startup*** e qual sua finalidade?
Startup é um código responsável pela inicialização do progama, com objetivo de preparar o ambiente de execução para que o main.c possa ser carregado corretamente. Esse código configura o ambiente alocando as áreas de memória para pilha e heap, configura interrupções, temporizadores, etc. Além disso ainda iniciliza bibliotecas e faz o carregamento do programa princial

## 3. Sobre o utilitário **make** e o arquivo **Makefile responda**:

#### (a) Explique com suas palavras o que é e para que serve o **Makefile**.
Makefile é um arquivo utilizado pelo utilitário make com o intuito principal de automatiza o processo de compilação e contrução de arquivos objetos. 
#### (b) Descreva brevemente o processo realizado pelo utilitário **make** para compilar um programa.
Primeiramente o make analisa o Makefile e determina quais arquivos-fonte devem ser atulizados. Para isso verifica as datas de modificação dos aquivos fonte e objetos, verifica as dependências e executa os comandos de compilacão necessários.
#### (c) Qual é a sintaxe utilizada para criar um novo **target**?
targets: prerequisites
	recipe
#### (d) Como são definidas as dependências de um **target**, para que elas são utilizadas?
A definição das dependências são listadas levando em conta quais arquivos são necessários para construir esse target específico. As dependências são usada pelo make para deteminar quando que o target necessita ser reconstruido.
#### (e) O que são as regras do **Makefile**, qual a diferença entre regras implícitas e explícitas?
As regras do Makefile são as instruções que definem como será construido os alvos. As regras implícitas são regras que o próprio make utiliza para compilar certos tipos de arquivos. Já regras explícitas são regras definidas pelo usuário no Makefile.

## 4. Sobre a arquitetura **ARM Cortex-M** responda:

### (a) Explique o conjunto de instruções ***Thumb*** e suas principais vantagens na arquitetura ARM. Como o conjunto de instruções ***Thumb*** opera em conjunto com o conjunto de instruções ARM?
O Thumb é um conjunto de instrução com maior eficiência em termos de memória e consumo de energia. As intruções são codificadas em 16bits, ocupando menos espaço na memória, e possibilitando um menor consumo de energia.
### (b) Explique as diferenças entre as arquiteturas ***ARM Load/Store*** e ***Register/Register***.
A arquitetura ARM Load/Store utiliza de instruções dedicadas de carga e armazenamento para transferir dados entre memória e registradores. Dessa forma, para essa arquitetura é necessário carregar os dados da memória para os registradores antes de realizas as operaçoes e, por fim, armazenar os resultados de volta na memória.
A arquitetura Register/Register, por sua vez, não acessa diretamente a memória para que as operações sejam feitas entre os registradores.
### (c) Os processadores **ARM Cortex-M** oferecem diversos recursos que podem ser explorados por sistemas baseados em **RTOS** (***Real Time Operating Systems***). Por exemplo, a separação da execução do código em níveis de acesso e diferentes modos de operação. Explique detalhadamente como funciona os níveis de acesso de execução de código e os modos de operação nos processadores **ARM Cortex-M**.
A execução do código é separada em diferentes níveis de acesso e modos de operção visando oferecer maior flexibilidade e segurança aos sistemas basedos em RTOS. Os níveis de acesso incluem o modo privilegiado e modo de exceção. O modo privilegiado é o nível de acesso com privilégios completos, onde o código tem acesso amplo aos recursos do sistema. Já o modo de exceção é ativado em resposta a eventos especiais, como interrupções. Nesse modo, o código é executado em um contexto separado, com acesso limitado a recursos e permissões reduzidas.

### (d) Explique como os processadores ARM tratam as exceções e as interrupções. Quais são os diferentes tipos de exceção e como elas são priorizadas? Descreva a estratégia de **group priority** e **sub-priority** presente nesse processo.

As exceções são eventos que ocorrem durante a execução do código em situações anômalas como violação de memória, erros de instrução, etc. A interrupção, por outro lado são eventos acionados peos periféricos para alertr uma condição que querer atenção imediata. A exceções são tratadas por tratatores de exceção específico, enqualto as interrupções são gerenciadas pelo NVIC que prioriza as interrupções e organiza em grupos de prioridade e subprioridade.Essa subdivisão permite uma granularidade adicional na priorização das interrupções e garante uma resposta eficiente do sistema a eventos externos
### (e) Qual a diferença entre os registradores **CPSR** (***Current Program Status Register***) e **SPSR** (***Saved Program Status Register***)?
Ambos os registradores controlam o estado do processador especialmente em situações de exceção e interrupção. O CPSR oném o estado do processador durante a execução normal do código. Quando uma subrotina se incia, o processador salva o conteúdo do CPSR no SPR , permitindo que o processador retome a execução do código no estado xato em que estava antes da exceção.
### (f) Qual a finalidade do **LR** (***Link Register***)?
O LR tem a finalidade de armazenar o endereço de retorno de uma sub-rotina após sua execução, permitindo que ao final da sub-rotina, o control retorne para o ponto de execução correto do programa especial.
### (g) Qual o propósito do Program Status Register (PSR) nos processadores ARM?
O PSR armazena as informações sobre o estado do processador durante a execução do código, como modo de operação atual, flags de condição e estado de habilitação das interrupções. Ele, portanto, tem função de controlar e gerenciar a execução do código de forma adequada, especialment em situações de exceção.
### (h) O que é a tabela de vetores de interrupção?

### (i) Qual a finalidade do NVIC (**Nested Vectored Interrupt Controller**) nos microcontroladores ARM e como ele pode ser utilizado em aplicações de tempo real?

### (j) Em modo de execução normal, o Cortex-M pode fazer uma chamada de função usando a instrução **BL**, que muda o **PC** para o endereço de destino e salva o ponto de execução atual no registador **LR**. Ao final da função, é possível recuperar esse contexto usando uma instrução **BX LR**, por exemplo, que atualiza o **PC** para o ponto anterior. No entanto, quando acontece uma interrupção, o **LR** é preenchido com um valor completamente  diferente,  chamado  de  **EXC_RETURN**.  Explique  o  funcionamento  desse  mecanismo  e especifique como o **Cortex-M** consegue fazer o retorno da interrupção. 

### (k) Qual  a  diferença  no  salvamento  de  contexto,  durante  a  chegada  de  uma  interrupção,  entre  os processadores Cortex-M3 e Cortex M4F (com ponto flutuante)? Descreva em termos de tempo e também de uso da pilha. Explique também o que é ***lazy stack*** e como ele é configurado. 


## Referências

### Básicas

[1] [STM32F411xC Datasheet](https://www.st.com/resource/en/datasheet/stm32f411ce.pdf)

[2] [RM0383 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

[3] [Using the GNU Compiler Collection (GCC)](https://gcc.gnu.org/onlinedocs/gcc/index.html)

[4] [GNU Make](https://www.gnu.org/software/make/manual/html_node/index.html)

### Vídeos Microsoft Teams

[5] [05 - Introdução à arquitetura de computadores](https://web.microsoftstream.com/embed/channel/f6b3a0de-e6f3-4652-b2d5-f1164032498a?app=microsoftteams&sort=undefined&l=pt-br#)

[6] [06 - Arquitetura Cortex-M Parte 1/2](https://web.microsoftstream.com/embed/channel/f6b3a0de-e6f3-4652-b2d5-f1164032498a?app=microsoftteams&sort=undefined&l=pt-br#)

[7] [07 - Arquitetura Cortex-M Parte 2/2](https://web.microsoftstream.com/embed/channel/f6b3a0de-e6f3-4652-b2d5-f1164032498a?app=microsoftteams&sort=undefined&l=pt-br#)

[8] [08 - Microcontroladores STM32](https://web.microsoftstream.com/embed/channel/f6b3a0de-e6f3-4652-b2d5-f1164032498a?app=microsoftteams&sort=undefined&l=pt-br#)

[9] [10 - Introdução à arquitetura de computadores](https://web.microsoftstream.com/embed/channel/f6b3a0de-e6f3-4652-b2d5-f1164032498a?app=microsoftteams&sort=undefined&l=pt-br#)

### Material Suplementar

[5] [A General Overview of What Happens Before main()](https://embeddedartistry.com/blog/2019/04/08/a-general-overview-of-what-happens-before-main/)
 
[6] [Bare metal embedded lecture-1: Build process](https://youtu.be/qWqlkCLmZoE?si=mn5yDnJYudQ1PpZH)
 
[7] [Bare metal embedded lecture-2: Makefile and analyzing relocatable obj file](https://youtu.be/Bsq6P1B8JqI?si=yuNLPj3JQ-2IT1yo)
 
[8] [Bare metal embedded lecture-3: Writing MCU startup file from scratch](https://youtu.be/2Hm8eEHsgls?si=c27MpZ47ApiMSwHR)
 
[9] [Lecture 15: Booting Process](https://youtu.be/3brOzLJmeek?si=MsHRUEJP8zofjwJQ)
