<h1 align = center> AEDS II</h1>
<h1 align = center> TOP K ITENS</h1>

<strong><p align = center> GUSTAVO HENRIQUE D'ANUNCIAÇÃO FERREIRA</p></strong>

<h2 align = center>  🧩 OBJETIVO </h2>

<p><strong>Solucionar um clássico problema chamado "Top k itens", encontrando os k itens mais relevantes de um dado conjunto de dados, utilizando estruturas de Hash e Heap.</strong></p>

<h2 align = center>  🧭 REGRAS: </h2> 

- O caminhamento deve ocorrer em uma única matriz de tamanho N x N
- --
- Quatro tipos de elementos vão compor a matriz e srão espalhados aleatoriamente: (a) item de passagem livre (número 1 na posição da matriz); (b) item de dano, indicado pelo carácter ‘*’; (c) paredes definidas como ‘#’ e; por fim, (d) uma ‘?’ que indica o alvo da exploração.
- --
- O alvo (?) estará posicionado de forma randômica na matriz em qualquer uma das posições tidas como válidas.
- --
- Tem-se como regra a condição de dano. Consideramos dano o item ‘*’, o qual obriga o algoritmo a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.
Ao sofrer um dano o algoritmo deve demarcar a posição com o item 1, neutralizando o mesmo e abrindo novas possibilidades de caminhamento / rotas até o estágio de finalização.

<h2 align=center>📚BIBLIOTECAS UTILIZADAS</h2>
- Durante a implementação do algoritmo, as bibliotecas utilizadas foram:

<table align=center>
     <tr>
        <td> std::iostream </td>    
    </tr>
    <tr>
        <td> std::string </td>    
    </tr>
        </tr>
        <tr>
        <td>string.h</td>
    </tr>
    <tr>
        <td>fstream</td>
    </tr>
        <tr>
        <td>vector</td>
    </tr>
        </tr>
        <tr>
        <td>sstream</td>
    </tr>
        </tr>
        <tr>
        <td>stack</td>
    </tr>
        </tr>
        <tr>
        <td>queue</td>
    </tr>
        </tr>
        <tr>
        <td>cmath</td>
    </tr>
        </tr>
        <tr>
        <td>ctime</td>
    </tr>
        </tr>
        <tr>
        <td>chrono</td>
    </tr>
            </tr>
        <tr>
        <td>string</td>
    </tr>
    
</table>

<h2 align = center>📄 ARQUIVOS UTILIZADOS</h2>

<h3><b>Arquivos de codificação: </b></h3>
<table>
<tr>
        <td> main.cpp </td>    
    </tr>
    <tr>
        <td> bfs.hpp </td>    
    </tr>
    <tr>
        <td>bfs.cpp</td>
    </tr>
        <tr>
        <td> dfs.hpp </td>    
    </tr>
    <tr>
        <td>dfs.cpp</td>
    </tr>
        <tr>
        <td> random.hpp </td>    
    </tr>
    <tr>
        <td>random.cpp</td>
    </tr>
</table>

<b> main.cpp: Contém o código que será executado pelo terminal</b>

<b> bfs.hpp: Contém a declaração das bibliotecas, structs para a estrutura de fila e as funções utilizadas com seus parâmetros para o funcionamento do método de busca em largura</b>

<b> bfs.cpp: Contém a implementação do funcionamento das funções utilizadas no método de busca em largura</b>

<b> dfs.hpp: </b>

<b> dfs.cpp: </b>

<b> random.hpp: </b>

<b> random.cpp: </b>

<strong>OBS: Os arquivos com extensão ".hpp" deve estar incluso aos arquivos "main.cpp" e também aos seus respectivos arquivos com extensão ".cpp"</strong>

<h3><b>Arquivos de leitura: </b></h3>
<table>
<tr>
        <td> input.data </td>    
    </tr>
</table>

<b>input.data: Contém em sua primeira linha a quantidade de linhas e colunas que as matrizes terão e, no resto do documento, os valores que irão compor essas matrizes</b>

<h3><b>Arquivos de saída: </b></h3>
<table>
<tr>
        <td> log_bfs.data </td>    
    </tr>
    <tr>
        <td> log_dfs.data </td>    
    </tr>
        <tr>
        <td> outputRandom.data </td>    
    </tr>
        </tr>
        <tr>
        <td> resultado_final.data </td>    
    </tr>
</table>

<b> log_bfs.data: Contém o caminho adotado na matriz pelo método de busca em largura (BFS).</b>

<b> log_dfs.data: Contém o caminho adotado na matriz pelo método de busca em profundidade (DFS).</b>

<b> outputRandom.data: Contém o caminho adotado na matriz pelo método randômico de busca.</b> 

<b> resultado_final.data: Contém o número de iterações feitas pelo método de busca em profundidade (DFS). </b>

<h2 align = center> 💡ALGORITMO </h2>

- O primeiro método executado é o método de busca por profundidade (DFS).
Uma variável do tipo abstrato DFS é iniciada, a contagem do tempo de execução é iniciada, a busca é realizada e o tempo de execução é exibido ao fim da busca, assim como o número de iterações.

```c++
    DFS dfs;
    auto start = chrono::high_resolution_clock::now();
    dfs.lerArquivo();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    cout << "Tempo de execucao: " << seconds << " segundos" << endl;
```

- Ao fim da execução do método de busca em profundidade, o método de busca em largura (BFS) é executado.
A contagem do tempo de execução é iniciada, a busca é realizada chamando a função "BFS()" e, ao fim da busca, o tempo de execução e o número de iterações é exibido.

```c++
    auto comeco = chrono::high_resolution_clock::now();
    BFS();
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - comeco;
    double sec = duracao.count();
    cout << "Tempo de execucao: " << sec << " segundos" << endl;
```

- Por ultimo, o método de busca randômico é executado.
Uma variável do tipo abstrato Mapa é iniciada e passada como parâmetro para a função "ReadMatrix()".
Após isso, a contagem do tempo de execução é iniciada, a busca é realizada e o tempo de execução é exibido no terminal, assim como o número de iterações feitas na busca.

```c++
    Mapa m;
    srand(time(NULL));
    ReadMatrix(&m);
    auto start2 = chrono::high_resolution_clock::now();
	Random(&m);
    auto end2 = chrono::high_resolution_clock::now();      
    chrono::duration<double> duration2 = end2 - start2;
    double seconds2 = duration2.count();
    cout << "Tempo de execucao: " << seconds2 << " segundos" << endl;
```
<h2 align = center> 🔍 MAIS SOBRE OS MÉTODOS DE BUSCA </h2>
<h3 align = center> BUSCA EM LARGURA (BFS)</h3>

<p>Na teoria dos grafos, busca em largura (ou busca em amplitude, também conhecido em inglês por Breadth-First Search - BFS) é um algoritmo de busca em grafos utilizado para realizar uma busca ou travessia num grafo e estrutura de dados do tipo árvore. Intuitivamente, você começa pelo vértice raiz e explora todos os vértices vizinhos. Então, para cada um desses vértices mais próximos, exploramos os seus vértices vizinhos inexplorados e assim por diante, até que ele encontre o alvo da busca. (Wikipedia)</p>

<p>O BFS é um algoritmo clássico de busca em grafos que explora sistematicamente todos os vértices de um grafo a partir de um vértice inicial. Ele garante que todos os vértices sejam visitados em uma ordem crescente de suas distâncias em relação ao vértice inicial. Em outras palavras, o BFS visita os vértices em camadas, começando pelo vértice inicial e avançando para seus vizinhos antes de explorar vértices mais distantes. (Chat GPT)</p>

<p>Em síntese, podemos trazer a lógica da busca em largura para o caminhamento de matrizes NxN, como é o caso deste algorítmo. A matriz é tratada como um grafo, onde cada elemento representa um vértice. O BFS percorre os elementos das posições não visitadas, explorando seus vizinhos antes de partir para as proximas posições. Isso garante que os elementos sejam visitados em uma ordem crescente em relação a sua distância com a posição inicial da busca. Em outras palavras, a busca ocorre em um "formato de onda" onde sua área se expande a cada iteração.
A busca é controlada por uma estrutura de fila, onde a posição, ou vértice, atual da busca é representada pelo primeiro valor da fila. </p>

<div align = center> <img align src = /img/BFS.gif> </div>

<p>No caso desta implementação do método BFS, a busca ocorre em um labirinto em formato de matriz, que segue as regras citadas ao começo do documento. Essa matriz é lida do arquivo "input.data" (dataset/input.data) e deve obrigatóriamente ser uma matriz quadrada de tamaho NxN. Eis um exemplo de entrada do arquivo "input.data" de uma matriz de formato 10x10</p>

<div align = center> <img align src = /img/exemplo_entrada.png> </div>

<h4 align = center>👨‍💻 CODIFICAÇÃO DO MÉTODO DE BUSCA EM LARGURA (BFS)</h4>
<strong><p align = center> bfs.hpp (src/bfs.hpp)</p></strong>

Como dito anteriormente, o arquivo "bfs.hpp" contém a declaração de todas as bibliotecas e funções utilizadas pelo algoritmo.

De início, as bibliotecas e o namespace são declarados.

```c++
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;
```

Logo após, as structs que compõem a estrutura de fila são declaradas.

```c++
typedef struct No No;
typedef struct Fila Fila;

struct No {
    int pos;
    No* prox;
};

struct Fila{
    No* primeiro;
    No* ultimo;
};
```

A struct "No" representa as posições da fila, e armazena o valor inteiro que vai controlar o método de busca, representado a linha e a coluna atual da busca na matriz.

A struct "Fila" representa a estrutura de fila propriamente dita. E contém os ponteiros para o primeiro e ultimo elemento da fila.

Em seguida, as funções usadas durante a implementação do BFS são declaradas.

Primeiro, as funções que envolvem a estrutura de fila são declaradas:

```c++
// funções da fila
void inicia_fila(Fila* f);
bool vazia(Fila* f);
void enfilera(Fila* f, int val);
void desenfilera(Fila* f);
void mostra_fila(Fila* f);
void limpa_fila(Fila* f);
```

A função "inicia_fila()" serve para iniciar uma fila vazia;

A função "vazia()" verifica se uma fila tem elementos ou não;

"enfilera()" adiciona um item ao final da fila.

"desenfilera()" remove o primeiro elemento da fila.

"mostra_fila()" mostra todos os elementos da fila.

"limpa_fila()" remove todos os elementos da fila de uma vez.

Todas as funções recebem a fila em questão como parâmetro, e a função "enfilera()" recebe como parâmeto, além da fila, o valor inteiro a ser adicionado à fila.

Depois, são declaradas as funções que envolvem a montagem e reinicio da matriz

```c++
// funções da matriz
void matrix_values(char *vet_values);
int matrix_size();
void reseta_mat(char **mat, int tam);
```

A função "matrix_values()" recebe um vetor do tipo char como parâmetro, e serve para ler a matriz do arquivo "input.data" e armazenar os caracteres no vetor.

"matrix_size()" retorna a dimensão da matriz lida do arquivo "input.data"

"reseta_mat()" serve para resetar os valores da matriz quando a busca atinge um "*", e recebe como parâmetro a matriz em questão e um inteiro que representa a dimensão da matriz.

Por fim, as funções de verificação da matriz, e a função principal do BFS são declaradas.

```c++
// funções de verificação, log e função principal
void verifica_1(char *mat, int i, int j, int tam, Fila *linha, Fila *coluna);
void verifica_ast(char *mat, int i, int j, int i_inicio, int j_inicio, int tam, Fila *linha, Fila *coluna);
void log(char *mat, int tam);
void BFS();
```

"verifica_1()" verifica se a posição passada como parâmetro pela matriz tem o caractere '1' como valor e executa as açoes necessárias para o BFS.

"verifica_ast()" verifica se a posição passada como parâmetro pela matriz tem o caractere '*' como valor e executa as açoes necessárias para o BFS.

As duas funções recebem como parâmetro a matriz em questão, a posição a ser verificada (i e j), e as filas que fazem controle do método de busca.

"log()" recebe a matriz em questão, e um inteiro que representa a dimensão da matriz. Serve para exportar o caminho tomado pelo método dentro da matriz para o arquivo "log_bfs.data"(dataset/log_bfs.data).

"BFS()" é a função principal, e executa todos os passos necessários para o funcionamento do método de busca em largura.

<strong><p align = center> bfs.cpp (src/bfs.cpp)</p></strong>

Seguindo a ordem das declarações no arquivo bfs.hpp, a implementação do funcionamento das funções é feito, de acordo com as descrições anteriores.

Primeiro, as funções que envolvem a estrutura de fila
```c++
void inicia_fila(Fila *f)
{
    f->primeiro = f->ultimo = nullptr;
}

bool vazia(Fila *f)
{
    return (f->primeiro == nullptr);
}

void enfilera(Fila *f, int val)
{
    No *NovoNO = new No;
    NovoNO->pos = val;
    NovoNO->prox = nullptr;
    if (vazia(f))
    {
        f->primeiro = f->ultimo = NovoNO;
    }
    else
    {
        f->ultimo->prox = NovoNO;
        f->ultimo = NovoNO;
    }
}

void desenfilera(Fila *f)
{
    if (vazia(f))
    {
        cout << "FILA VAZIA!" << endl;
    }
    else
    {
        // int removeu = f->primeiro->pos; // o que ta removendo
        No *remove = f->primeiro;
        f->primeiro = f->primeiro->prox;
        delete remove;
    }
}

void mostra_fila(Fila *f)
{
    if (vazia(f))
    {
        cout << "FILA VAZIA!!" << endl;
    }
    No *espaco = f->primeiro;
    while (espaco)
    {
        cout << espaco->pos << " ";
        espaco = espaco->prox;
    }
    cout << endl;
}

void limpa_fila(Fila *f)
{
    while (!vazia(f))
    {
        desenfilera(f);
    }
}

```

Depois as funções que envolvem a matriz em questão

```c++
int matrix_size()
{
    string tam;
    int cont = 0;
    ifstream file;
    file.open("./dataset/input.data");

    if (file.is_open())
    {
        while (cont != 2)
        {
            getline(file, tam, ' ');
            cont++;
        }
    }

    return stoi(tam);
}

void matrix_values(char *vet_values)
{
    char aux;
    int k = 0;
    ifstream file;
    file.open("./dataset/input.data");

    if (file.is_open())
    {
        while (file >> aux)
        {
            vet_values[k] = aux;
            k++;
        }
    }

    file.close();
}


void reseta_mat(char *mat, int tam)
{
    int i = 0, j = 0;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (*((mat + i * tam) + j) == 'v')
            {
                *((mat + i * tam) + j) = '1';
            }
        }
    }
}
```

Agora, em uma abordagem mais detalhada, segue a maneira que o método foi implementado, tendo como funções principais "verifica_1()",  "verifica_ast()", "log()" e "BFS()"

```c++
void BFS()
{
    int tam = matrix_size(), k = 4;
    char mat[tam][tam], vet_values[(tam * tam)+4];

    matrix_values(vet_values);
```

A princípio, a dimensão da matriz lida do arquivo "input.data" é armazenada na variável "tam", a variável k é inicializada em 4 para que a leitura seja feita a partir do primeiro item da matriz (ela servirá como um contador na hora de armazenar os valores do vetor "vet_values" para a matriz), a matriz "mat" é inicializada com as dimensões dadas pelo valor de tam, e o vetor "vet_values" é inicializado com a dimensão dado pelo valor de tam², já que, a quantidade de elementos de uma matriz é dado pelo número de linhas (i) multiplicado pelo número de colunas (j). Depois o vetor "vet_values" é passado como parâmetro da função "matrix_values()" para que os valores sejam lidos do arquivo "input.data" e para dentro do vetor.

A seguir, os valores armazenados no vetor "vet_values" são transferidos para a matriz "mat".
```c++
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            mat[i][j] = vet_values[k];
            k++;
        }
    }
```

Depois, as filas que vão controlar a busca são declaradas e inicializadas. Também são declaradas as variáveis i_final e J_final, elas servirão para verificar a existência do alvo ('?') na matriz.

Note que as variáveis i_final e j_final são inicializadas com o valor -1. Isso por que o alvo pode estar em qualquer posição, e valores negativos não fazem parte do domínio analisado na matriz

A variável cont também é declarada e inicializada em 0, ela representa o número de iterações feitas pelo BFS.

```c++
    Fila linha, coluna;
    inicia_fila(&linha);
    inicia_fila(&coluna);
    int cont = 0, i_final = -1, j_final = -1;
```

Em seguida, a existência do caractere alvo ('?') é verificado. Caso ele seja identificado na matriz, o índice referente a sua posição na matriz (linha e coluna) é armazenado nas variáveis i_final e j_final, respectivamente. Se não, uma mensagem de erro é exibida no terminal.

```c++
    // Identificando a posição do alvo
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (mat[i][j] == '?')
            {
                i_final = i;
                j_final = j;
                mat[i][j] = '1';
                break;
            }
        }
    }

    if (i_final == -1)
    {
        cout << "O ALVO NÃO FOI IDENTIFICADO NA MATRIZ!" << endl
             << endl;
        return;
    }
```

Aqui, chegamos a parte da função onde a busca é configurada e ocorre de fato.

Primeiramente, a posição de início é definida através do valor contido nas variáveis i_inicio, j_inicio, para alterá-la basta modificar o valor das variáveis. Depois de definida a posição inicial, ela é adicionada à sua respectiva fila para que a busca comece. A posição de inicio é marcada como visitada.

Também são declaradas as variáveis i e j, que vão representar a linha e coluna atual onde a busca se encontra.

```c++
    // Setando a posição de início

    int i_inicio = 0;
    int j_inicio = 0;

    enfilera(&linha, i_inicio);
    enfilera(&coluna, j_inicio);
    mat[i_inicio][j_inicio] = 'v';

    int i, j;
```
Enfim, a busca finalmente acontece. Vamos a uma visão mais a fundo dela:

```c++
// BFS !!

    while (!vazia(&linha))
    {
        i = linha.primeiro->pos;
        j = coluna.primeiro->pos;

        if (i == i_final && j == j_final)
        {
            cont ++;
            break;
        }

        desenfilera(&linha);
        desenfilera(&coluna);

        verifica_1((char *)mat, i + 1, j, tam, &linha, &coluna); // baixo
        verifica_1((char *)mat, i, j - 1, tam, &linha, &coluna); // esq
        verifica_1((char *)mat, i - 1, j, tam, &linha, &coluna); // p cima
        verifica_1((char *)mat, i, j + 1, tam, &linha, &coluna); // direita

        verifica_ast((char *)mat, i + 1, j, tam, &linha, &coluna); // baixo
        verifica_ast((char *)mat, i, j - 1, tam, &linha, &coluna); // esq
        verifica_ast((char *)mat, i - 1, j, tam, &linha, &coluna); // p cima
        verifica_ast((char *)mat, i, j + 1, tam, &linha, &coluna); // direita

        cont++;
    }
```

A busca ocorrerá enquanto existirem elementos nas filas. Como durante toda a busca, o número de elementos das filas de linha e coluna serão sempre o mesmo, basta que a verificação no loop while seja feita em apenas uma das filas para que a busca aconteça.

O primeiro passo da busca, é acessar o primeiro elemento das filas de linha e coluna, e atribuir ao valor de i e j respectivamente.

Em seguida, é verificado se a posição atual da busca é a posição do caractere alvo ('?'). Caso seja, o contador de iterações é incrementado e a busca é encerrada, se não, a busca continua.

Após essa verificação, a posição atual do processamento é desenfileirada para que a próxima posição visitada seja a primeira da fila, e seja processada após a verificação.

A verificação é feita "em blocos" de forma que seja verificado o valor das posições vizinhas abaixo, a esquerda, acima e a direita (nessa ordem de prioridade) da posição de processamento atual.

O primeiro bloco de verificação, verifica se a posição vizinha é o caractere '1', utilizando a função "verifica_1":

```c++
void verifica_1(char *mat, int i, int j, int tam, Fila *linha, Fila *coluna)
{
    if (((i >= 0 && i <= tam - 1) && (j >= 0 && j <= tam - 1)) && *((mat + i * tam) + j) == '1')
    {
        *((mat + i * tam) + j) = 'v';
        enfilera(linha, i);
        enfilera(coluna, j);
    }
}
```

A função "Verifica_I" verifica se o índice do valor verificado pertente ao domínio da matriz, e se o valor verificado corresponde ao caractere '1'. 
Caso a verificação seja verdadeira, a posição é marcada como visitada e o valor do índice da linha e da coluna são adicionados à sua respectiva fila para que seus vizinhos também sejam analizados e processados.

Caso o vizinho da posição atual de processamento não seja um caminho livre (caractere '1'), é verificado através da função "verifica_ast' se o valor do vizinho corresponde ao caractere '*'.

```c++
void verifica_ast(char *mat, int i, int j, int i_inicio, int j_inicio, int tam, Fila *linha, Fila *coluna)
{
    if (((i >= 0 && i <= tam - 1) && (j >= 0 && j <= tam - 1)) && *((mat + i * tam) + j) == '*')
    {
        *((mat + i * tam) + j) = '1';
        reseta_mat(mat, tam);
        limpa_fila(linha);
        limpa_fila(coluna);
        enfilera(linha, i_inicio);
        enfilera(coluna, j_inicio);
    }
}
```
A função "Verifica_ast" verifica se o índice do valor verificado pertente ao domínio da matriz, e se o valor verificado corresponde ao caractere '*'. 

Seguindo as regras, a posição contendo o '*' é definida como '1' e se torna um caminho livre para passagem. Isso da margem para novas possibilidades de caminho até o alvo.
Após isso, as posições já visitadas são novamente transformadas em '1', através da função "reseta_mat". As filas são limpas, e é adicionado o índice inicial em ambas as filas, significando que a execução voltou ao inicio.

Ao fim da verificação de um índice, o contador de iterações é incrementado, sinalizando que a busca avançou para a próxima posição.

Caso a busca fique "presa" entre paredes e não consiga mais proseguir rumo ao alvo, a fila se esvazia, a busca é encerrada e o caminho tomado e o número de iterações se limitam até aquele momento da busca.

Atingindo o alvo, ou não, ao fim de todas as verificações, a posição do alvo é novamente substituída pelo caractere '?'. A função "log" é usada para mostrar o caminho tomado pelo BFS até o fim da busca. A matriz contendo o caminho é gravada no arquivo "log_bfs.data".

Finalmente, uma mensagem é exibida no terminal para dizer que a busca chegou ao fim, juntamente com o número de iterações feitas durante ela.

```c++
    mat[i_final][j_final] = '?';

    log((char *)mat, tam);
    

    cout << "\nBFS CHEGOU AO FINAL!" << endl;
    cout << "Quantidade de passos BFS: " << cont << endl;
}
```

<h3 align = center> BUSCA EM PROFUNDIDADE (DFS)</h3>

YGOR BOTA SUA DOCUMENTAÇÃO AQUI

<h3 align = center> MÉTODO RANDÔMICO</h3>

RAFAEL BOTA SUA DOCUMENTAÇÃO AQUI

<h2 align=center>🧠 DISCUSSÃO</h2>

Após o processo de análise e de submeter os algoritmos a testes com diferentes matrizes de diferentes tamanhos, algumas perguntas podem ser levantadas e discutidas:

- 1: Para diferentes tamanhos de matriz e posicionamento das paredes, há predominância de um dos algoritmos em termos de iterações e tempo de execução?

- 2: Algum dos algoritmos é capaz de encontrar o melhor caminho, ou seja, o com o menor número de iterações?

<h2 align = center>📈 Resultados esperados</h2>

É esperado que, a partir de uma mesma entrada para os 3 algoritmos, eles sejam capazes de percorrer o labirinto rumo ao caractere alvo realizando a busca de acordo com o que cada um deles se propõe e seguindo as regras descritas, exibindo ao final o tempo de execução e o número de iterações feitas no processo. Isso permitirá uma análise dos 3 métodos, comparando seus tempos de execução e a quantidade de iterações.

Utilizando a seguinte matriz como entrada para os 3 algoritmos, podemos exemplificar o funcionamento.

<div align = center> <img align src = /img/exemplo_entrada.png> </div>

A partir da leitura dessa matriz, os métodos devem ser executados e suas iterações e tempo de execução devem ser mostrados no terminal, dessa forma:

<div align = center> <img align src = /img/resultado_esperado.png> </div>

Nota-se que, por se tratar de um "caminho fechado", o BFS e o DFS fazem o mesmo número de iterações, porém com tempos distintos. Já o método randômico faz mais iterações e em um tempo diferente também.

Os caminhos tomados por cada tipo de busca pode ser acessado no respectivo aqruivo de saída: "log_bfs" para o BFS, "log_DFS" para o DFS e "outputRandom" para o método randômico.

<strong><p align = center> log_dfs.data</p></strong>

<div align = center> <img align src = /img/log_dfs.png> </div>

<strong><p align = center> log_bfs.data</p></strong>

<div align = center> <img align src = /img/log_bfs.png> </div>

<strong><p align = center> outputRandom.data</p></strong>

<div align = center> <img align src = /img/log_rand.png> </div>

<h2 align = center>🔧 Compilação e execução </h2>
</h2>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             
