# Algoritmo de Metropolis para o modelo de Ising

Código em C++ para implementar o algoritmo de metrópole para solucionar o modelo de Ising para 


## Introdução

O modelo de Ising, que recebe o nome em homenagem a Ernest Ising, foi proposto como uma forma de
estudar fenômenos magnéticos em materiais, e sua relação com a temperatura. O modelo consiste em uma
rede onde cada sı́tio é ocupado por um elemento, (chmados aqui de spin), que podem assumir apenas dois
valores, simulando o comportamento da componente z de um spin eletrônico. A evolução temporal de cada
spin depende de seu próprio valor e do valor de seus vizinhos mais próximos, e também da temperatura
do sistema. Dessa forma, se houver um padrão de alinhamento entre os spins ocorre o surgimento de um
momento magnético total do sistema. O código implementa o modelo descrito assima e permite realizar simulações para diferentes sistemas, de forma a estudar algumas
propriedades termodinâmicas como a magnetização e a energia em função do tempo e da temperatura,
bem como fenômenos de transição de fase.

## Algoritmo de Metropolis

Iremos simular um sistema com todos os spins inicialmente com valor 1, submetidos a um banho térmico à
uma temperatura T , poranto a evolução temporal do sistema irá tender ao equilibrio. Para simular a troca
de energia entre o sistema e o banho térmico foi usado o método de Monte Carlo, que consiste em uma
abordagem estocástica para o problema. A evolução do sistema acontece usado o algorı́timo de Metropolis,
que consiste em:
1. Escolher um spin e calcular E f lip , a energia necessária para mudar o seu estado
2. Se E f lip é negativo, o spin muda de valor
3. Se E f lip é positivo é gerado um número aleatório entre 0 e 1. Se ≤ e −E f lip /(K B T ) , onde K B é a
constante de Boltzmann e T a temperatura do sistema, o spin muda de valor, do contrário permanece
inalterado.

Para implementar o algoritimo de Metropolis, foi implementada a classe 'rede', que possui atributos e métodos para calcular e armazenar as informações termodinâmicas da rede.

O método 'sweep' percorre a rede, elemento por elemento e calcula as energias do estado atual de cada spin, que consiste no negativo da soma do produto do spin pelos seus quatro vizinhos mais próximos, e a energia do estado com o spin invertido. Para simular uma rede infinita foram aplicadas condições periódicas de fronteira, ou seja, os spins posicionados nas extremidades de uma linha ou coluna da matriz consideram como vizinho o spin posicionado na outra extremidade. 

A evolução do sistema acontece usado o algorı́timo de Metropolis,
que consiste em:
1. Escolher um spin e calcular a energia necessária para mudar o seu estado
2. Se tal energia for negativa, o spin muda de valor
3. Se for positiva, é gerado um número aleatório entre 0 e 1, e o estado do spin é determinado pela distribuição de Boltzman
