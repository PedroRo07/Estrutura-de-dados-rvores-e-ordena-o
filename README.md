# Estrutura-de-dados-rvores-e-ordena-o

Estruturas de Dados: Árvores e Grafos

A grande familia

Este repositório contém as resoluções dos desafios propostos para a disciplina de Estrutura de dados, implementados em C++. O foco do projeto é a manipulação eficiente de árvores e estruturas de dados, garantindo otimização de tempo e memória.

## 1. Equipe e Responsabilidades

A divisão de tarefas foi estabelecida para que cada membro fosse responsável pelo ciclo completo (lógica, implementação e testes) dos seus respectivos desafios:

* **Pedro Ró:** Implementação dos Desafios 1, 3 e 4.
* **Hygor Nobre:** Implementação dos Desafios 2, 5, 6 e 7.
* **Gustavo Ribeiro:** Implementação dos Desafios 8 e 9.
* **Renato Augusto:** Implementação dos Desafios 11, 12 e 13.

## 2. Desafios Concluídos

Foram concluídos com sucesso os seguintes problemas:
* **01:** Retrato de uma árvore (Contagem de folhas e nós internos)
* **02:** Três percursos
* **03:** Construção de uma BST (Árvore Binária de Busca)
* **04:** Busca com profundidade em BST
* **05:** Altura e níveis
* **06:** Remoção em uma BST
* **07:** Diagnóstico de balanceamento
* **08:** Seleção em ação
* **09:** Inserção estável de registros
* **11:** Quicksort com três regiões
* **12:** Reconstrução balanceada
* **13:** Catálogo com consultas por faixa


## 3. Decisões de Implementação

Para garantir que os códigos cumprem os rigorosos requisitos das plataformas de avaliação automática, adotamos as seguintes premissas:
* **Silêncio no I/O:** Os códigos leem a entrada e imprimem a saída estritamente conforme os exemplos dos enunciados. Não foram incluídas mensagens interativas (ex: `cout << "Digite o valor:"`) para evitar falhas ("Wrong Answer") nos corretores automáticos.
* **Gestão de Memória Otimizada:** No Desafio 01, optou-se por não instanciar nós e ponteiros fisicamente. A árvore foi mapeada usando apenas um `std::vector<bool>` para identificar os nós pais, economizando recursos significativos.
* **Inserção Recursiva (BST):** Nos Desafios 03 e 04, a árvore foi construída via alocação dinâmica (`new Node`) com percurso recursivo, garantindo que valores duplicados fossem ignorados por padrão para manter chaves únicas.

## 4. Complexidades de Tempo e Memória

Abaixo estão as complexidades garantidas para as implementações principais (ajuste ou adicione os de outros membros conforme necessário):

| Desafio | Complexidade de Tempo | Complexidade de Memória | Observação |
| :--- | :--- | :--- | :--- |
| **01 (Retrato)** | $O(n)$ | $O(n)$ | Uso de vetor booleano de tamanho $n+1$. Leitura linear. |
| **03 (Construção)**| $O(n \cdot h)$ | $O(n)$ | Onde $h$ é a altura final da árvore. Sem exigência de balanceamento. |
| **04 (Busca)** | $O(h + 1)$ | $O(n)$ | Custo por consulta é proporcional à profundidade da árvore. |

## 5. Comandos Exatos de Compilação e Execução

Os códigos foram desenvolvidos para compilação via `g++`. Abra o terminal na pasta do projeto e utilize os comandos abaixo.

**No Windows:**
```bash
# Para compilar (exemplo com o desafio 01)
g++ 01_retrato.cpp -o 01_retrato.exe

# Para executar
.\01_retrato.exe
```

**No Linux / macOS:**
```bash
# Para compilar
g++ 01_retrato.cpp -o 01_retrato

# Para executar
./01_retrato
```

## 6. Como Rodar Todos os Testes Automáticos

Para testar grandes volumes de dados sem digitar manualmente, utilize o redirecionamento de ficheiros de texto (`<`). 

1. Crie um ficheiro `input.txt` na mesma pasta do executável e cole dentro dele os dados de entrada do problema.
2. Execute o programa redirecionando esse ficheiro como entrada padrão:

**Windows:**
```bash
.\01_retrato.exe < input.txt
```

**Linux / macOS:**
```bash
./01_retrato < input.txt
```
O resultado será impresso diretamente no terminal, processando todo o ficheiro de uma só vez, permitindo a validação imediata com o "Exemplo de saída" esperado.
