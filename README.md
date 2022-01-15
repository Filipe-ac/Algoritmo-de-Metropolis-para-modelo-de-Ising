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

Para implementar o algoritimo descrito na seção anterior, foi criada a classe \textit{rede}, que possui atributos e métodos para calcular e armazenar as informações termodinâmicas da rede.

O método \textit{sweep} percorre a rede, elemento por elemento e calcula as energias do estado atual de cada spin ($E_1$), que consiste no negativo da soma do produto do spin pelos seus quatro vizinhos mais próximos, e a energia do estado com o spin invertido $E_2$. Para simular uma rede infinita foram aplicadas condições periódicas de fronteira, ou seja, os spins posicionados nas extremidades de uma linha ou coluna da matriz consideram como vizinho o spin posicionado na outra extremidade. 

Em seguida, é feito o cálculo da energia $E_{flip} = E_2 - E_1$, e aplicado a condição descrita na seção anterior: Se $E_{flip} \leq 0$ o valor do spin é multiplicado por $-1$, do contrário é gerado um número aleatório $r$, uniformemente distribuído entre 0 e 1, e se $r \leq e^{-(E_2-E_1)/T}$ o valor é multiplicado por $-1$.

Em seguida é somada a contribuição de cada spin para a energia do sistema e a magnetização total, definida simplesmente como a soma de todos os valores de spin:
\begin{equation}
M = \sum s_i
\end{equation}

Por fim, a magnetização é dividida pelo número de spins para normalizar o valor, e a energia é dividida por 2 pois cada par de spin é considerado duas vezes.
