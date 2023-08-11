<h1 align = center> AEDS II</h1>
<h1 align = center> TOP K ITENS</h1>

<strong><p align = center> GUSTAVO HENRIQUE D'ANUNCIAÇÃO FERREIRA</p></strong>

<h2 align = center>  🧩 OBJETIVO </h2>

<p><strong>Solucionar um clássico problema chamado "Top k itens", encontrando os k itens mais relevantes de um dado conjunto de dados, utilizando estruturas de Hash e Heap.</strong></p>

<h2 align = center>  ❓ APRESENTAÇÃO DO PROBLEMA: </h2> 

 O Problema consiste em ler de um arquivo txt um texto, e tratá-lo para extrair as K palavras mais frequentes e, consequentemente, mais relevantes do texto.

<h2 align=center>📚BIBLIOTECAS UTILIZADAS</h2>
- Durante a implementação do algoritmo, as bibliotecas utilizadas foram:

<table align=center>
     <tr>
        <td>iostream </td>    
    </tr>
    <tr>
        <td>string </td>    
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
        <td>algorithm</td>
    </tr>
        </tr>
        <tr>
        <td>unordered_set</td>
    </tr>
        </tr>
        <tr>
        <td>unordered_map</td>
    </tr>
    
</table>

<h2 align = center>📄 ARQUIVOS UTILIZADOS</h2>

<h3><b>Arquivos de codificação: </b></h3>
<table>
<tr>
        <td> main.cpp </td>    
    </tr>
    <tr>
        <td> functions.hpp </td>    
    </tr>
    <tr>
        <td>functions.cpp</td>
    </tr>
        <tr>
        <td> HeapMAX.hpp </td>    
    </tr>
    <tr>
        <td>HeapMAX.cpp</td>
    </tr>
</table>

<b> main.cpp: Contém o código que será executado pelo terminal</b>

<b> functions.hpp: Contém a declaração das funções que envolvem leitura de arquivos, tratamento de palavras, e contagem de palavras. </b>

<b> functions.cpp: Contém a implementação das funções referenciadas no arquivo "functions.hpp"</b>

<b> HeapMAX.hpp: Contém a declaração da Struct que vai armazenar o par que vai conter as informações da palavra e sua frequencia. Também contém a declaração da classe e funções que vão compor a estrutura de Heap máxima. </b>

<b> HeapMAX.cpp: Contém a implementação das funções referenciadas no arquivo "HeapMAX.hpp".</b>


<strong>OBS: Os arquivos com extensão ".hpp" deve estar incluso aos arquivos "main.cpp" e também aos seus respectivos arquivos com extensão ".cpp"</strong>

<h3><b>Arquivos de leitura: </b></h3>
<table>
<tr>
        <td> DomCasmurro.txt </td>    
    </tr>
    <tr>
        <td> Semana_Machado_Assis.txt </td>    
    </tr>
    <tr>
        <td> stopwords.txt </td>    
    </tr>
</table>

<b>DomCasmurro.txt, Semana_Machado_Assis.txt: Contém o texto que deve ser lido para extração das K palavras mais frequentes.</b>

<b>stopwords.txt: Contém as palavras sem relevância semântica que devem ser desconsideradas do texto.</b>


<h2 align = center> 💡ALGORITMO </h2>

- Primeiro, a leitura do texto a partir do arquivo .txt referenciado é lido e armazenado em uma string. A seguir, as stopwords também são lidas do seu arquivo referente e armazenadas em um unordered_set.

```c++
    string texto = LeTexto("../dataset/Semana_Machado_Assis.txt");
    unordered_set stopwords = LeStopwords("../dataset/stopwords.txt");
```

- Antes de seguir para a parte de remoção das stopwords, o texto passa por um tratamento, onde todas as palavras são passadas para a forma minúscula e todas as pontuações são retiradas do texo, já que não tem relevância para os fins desejados.

```c++
    string texto_tratado = Tratamento(texto);
```

- Nesta etapa, já com o texto tratado, as stopwords são retiradas do texto para que apenas as palavras com relevância semântica permaneçam para a contagem.

```c++
   string texto_semSW = RemoveSW(texto_tratado, stopwords);
```

- Agora, já com as palavras relevantes devidamente separadas, a contagem das palavras é feita e armazenada em um unordered_map do tipo <string, int> onde a string representa a palavra, e a variavel inteira representa a frequencia dela no texto.

```c++
    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);
```

- Por fim, a estrutura de Heap maxima é referenciada, e o par contendo as palavras e sua respectiva frequencia no texto são passados para dentro da estrutura de heap. Após esse processo, as K palavras mais relevantes do texto podem ser extraídas.

```c++
        HeapMAX HeapMaxima;

    for(const auto& item : frequencia){
        HeapMaxima.inserir(DataPair(item.first, item.second));
    }

    cout << "As " << MAX << " palavras mais frequentes, seguidas de sua frequencia: " << endl;
    for(int i=0; i<MAX && !HeapMaxima.Vazia(); ++i){
        DataPair pair = HeapMaxima.PesquisaMAX();
        cout << pair.palavra << " : " << pair.freq << endl;
    }
```

Para definir quantas palavras mais frequentes vão ser mostradas na tela, basta modificar o valor da constante MAX:

```c++
#define MAX 20
```

- Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos
elementos e heap para manter a lista dos k elementos com maiores valores. Sua complexidade,
caso implementado adequadamente, é de O(nlogk), onde n é o tamanho da coleção de dados
e k o número de itens mais relevantes.

<h2 align = center> 🔍 A ESTRUTURA HEAP </h2>

<p>Heaps são arvores binárias, mas não de pesquisa. As seguintes propriedades podem definir um heap:</p>

- O heap é uma árvore binária completa ou quase completa da esquerda para a direita. Isso ajuda para que ela possa ser representada utilizando um vetor, que é o caso deste algorítmo.

- Cada nó da arvore pode ter valor maior/menor ou igual ao de seus filhos.
    Quando o maior valor está no nó raiz, a estrutura é chamada Heap Maxima, e já quando o menor valor está na raíz, é chamada de Heap Mínima.

Para esta implementação, foi utilizado o conceito de Heap Maxima, eis um exemplo visual da sua estrutura:

<div align = center> <img align src = /img/MAXHEAPEX.png> </div>

- Note que, o maior valor da heap (17) está no topo da árvore, e os valores seguem uma orem decrescente da esquerda para a direita até o menor valor (7).

- Nessa imagem, pode-se observar também que não há "salto" ao percorrer a estrutura em largura, logo ela pode ser considerada uma Heap. Podemos também observar a propriedade de Heap quase completa, já que apenas o filho da esquerda do elemento 10 está presente.


Além da vantagem da fácil representação da heap utilizando um vetor, também é de destaque o acesso rápido ao elemento máximo, com complexidade O(1) e a inserção eficiente com complexidade O(logn).

<h4 align = center>👨‍💻 CODIFICAÇÃO DA ESTRUTURA HEAP MÁXIMA</h4>
<strong><p align = center> HeapMAX.hpp (src/HeapMAX.hpp)</p></strong>

Como dito anteriormente, o arquivo "bfs.hpp" contém a declaração de todas as bibliotecas e funções utilizadas pelo algoritmo.

De início, as bibliotecas e o namespace são declarados.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
```

Logo após, a struct que vai armazenar o par do tipo <string, int> é criada

```c++
struct DataPair {
    string palavra;
    int freq;

    DataPair(const string &p, int f) : palavra(p), freq(f) {}
};
```

Depois, a classe que vai compor a estrutura de HeapMaxima é criada, juntamente com as funções que vão garantir o funcionamento da estrutura.

```c++
class HeapMAX {
private:
    vector<DataPair> heap;

    void prop(int index);
public:
    HeapMAX(){}

    void inserir(const DataPair& pair);

    DataPair PesquisaMAX();

    bool Vazia();

};
```
Note que, a representação do heap é feita com o vector "heap" e ele armazena dados do tipo abstrato DataPair, que são as informações a serem extraídas do conjunto de dados.

```c++
void prop(int index): Essa função é responsável por manter a propriedade de Heap Maxima após cada inserção e remoção.

void inserir(const DataPair& pair): Responsável por inserir um nó na estrutura Heap.

DataPair PesquisaMAX(): Responsável por extrair o maior valor da estrutura.

bool Vazia(): Responsavel por verificar se a estrutura está vazia ou não.
```

<strong><p align = center> HeapMAX.cpp (src/HeapMAX.cpp)</p></strong>

Seguindo a ordem das declarações no arquivo HeapMAX.hpp, a implementação do funcionamento das funções é feito, de acordo com as descrições anteriores.

```c++
void HeapMAX::prop(int index){

    int maior = index;
    long unsigned int esq = 2 * index + 1; // calculando valor do filho da esquerda do indice em questao (index)
    long unsigned int dir = 2 * index + 2; // calculando valor do filho da direita

    if(esq < heap.size() && heap[esq].freq > heap[maior].freq){
        maior = esq;
    }

    if(dir < heap.size() && heap[dir].freq > heap[maior].freq){
        maior = dir;
    }

    if(maior != index){
        swap(heap[index], heap[maior]);
        prop(maior); // recursividade aq, e é repetida até que a propriedade seja mantida para todos os nós
    }
}

void HeapMAX::inserir(const DataPair& pair){

    heap.push_back(pair);

    int index = heap.size() - 1; // posicao do novo elemento

    while(index > 0 && heap[index].freq > heap[(index - 1)/2].freq){ // executa enquanto o indice não é o nó raiz (0)
                                                                     // e enquanto a freq do atual é maior que o do pai
        swap(heap[index], heap[(index - 1)/2]); // troca o nó de lugar
        index = (index - 1)/2; // atualiza o indice do atual pro do maior anterior (pai)
    }
}

DataPair HeapMAX::PesquisaMAX(){

    DataPair Max = heap.front(); // elemento maximo
    heap[0] = heap.back(); // substitui a raiz pelo ultimo nó da heap
    heap.pop_back(); // remove o ultimo nó da heap
    prop(0); // reorganiza

    return Max;
}

bool HeapMAX::Vazia(){
    return heap.empty();
}
```

Dessa forma, é esperado que essa estrutura receba um par do tipo <string, int> e seja capaz de manter sempre o elemento com maior valor do tipo inteiro no nó raiz, extraindo assim a palavra com maior frequencia no texto lido como entrada.


<h3 align = center> 👨‍💻 CODIFICAÇÃO DA LEITURA, TRATAMENTO, E CONTAGEM DE PALAVRAS</h3>


<strong><p align = center> functions.hpp (src/functions.hpp)</p></strong>

- Primeiro, as bibliotecas e o namespace são declarados.

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
```

- A seguir, todas as funções são declaradas:

```c++
string LeTexto(const string& caminhoArquivo);
string Tratamento(const string& texto);

unordered_set<string> LeStopwords(const string& caminhoArquivo);

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords);

unordered_map<string, int> ContaFrequencia(const string& texto);
```

```c++
string LeTexto(const string& caminhoArquivo): É responsável por ler o texto do arquivo .txt através do caminho referenciado e armazenar em uma string.

string Tratamento(const string& texto): É responsável por retirar a pontuação e passar o texto lido para o formato minúsculo em sua totalidade.

unordered_set<string> LeStopwords(const string& caminhoArquivo): Responsável por Ler as stopwords de um arquivo .txt através do caminho referenciado e armazenar em um unordered_set.

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords): Responsável por remover as stopwords armazenadas no unordered_set do texto lido e tratado.

unordered_map<string, int> ContaFrequencia(const string& texto):
responsável por fazer a contagem da frequência de palavras e armazena-las como um par do tipo <string, int> dentro de um unordered_map, onde o tipo string representa a palavra, e a variável do tipo inteiro representa a frequencia dessa palavra no texto.
```

<strong><p align = center> functions.cpp (src/functions.cpp)</p></strong>

Seguindo a ordem das declarações no arquivo functions.hpp, a implementação do funcionamento das funções é feito, de acordo com as descrições anteriores.

```c++
#include "functions.hpp"

string LeTexto(const string& caminhoArquivo){
    ifstream arquivo(caminhoArquivo);
    string conteudo;

    if(arquivo.is_open()){
        string linha;
        while(getline(arquivo, linha)){
            conteudo += linha + "\n";
        }
        arquivo.close();
    } else{
        cout << "Erro ao abrir arquivo" << endl;
    }

    return conteudo;
}

string Tratamento(const string& texto){
    string Texto_tratado = texto;

    transform(Texto_tratado.begin(), Texto_tratado.end(), Texto_tratado.begin(), ::tolower); // minusculas

    Texto_tratado.erase(remove_if(Texto_tratado.begin(), Texto_tratado.end(), ::ispunct), Texto_tratado.end()); // tirando pontos

    return Texto_tratado;
}

unordered_set<string> LeStopwords(const string& caminhoArquivo){
    unordered_set<string> stopwords;
    ifstream arquivo(caminhoArquivo);

    if(arquivo.is_open()){
        string palavra;

        while(arquivo >> palavra){
            stopwords.insert(palavra);
        }
        arquivo.close();
    } else{
        cout << "Erro ao abrir arquivo txt" << endl;
    }

    return stopwords;
}

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords){
    stringstream separador(textoTratado);
    string palavra;
    string texto_semSW;

    while(separador >> palavra){
        if(stopwords.find(palavra) == stopwords.end()){
            texto_semSW += palavra + " ";
        }
    }

    return texto_semSW;
}

unordered_map<string, int> ContaFrequencia(const string& texto){
    unordered_map<string, int> palavras;

    istringstream separador(texto);
    string palavra;

    while(separador >> palavra){
        palavras[palavra]++;
    }

    return palavras;
}
```

Dessa forma, é esperado que a leitura, o tratamento e a contagem das palavras seja realizada de forma correta ao fim da utilização de todas as função descritas.

<h2 align = center>📈 Resultados esperados</h2>

É esperado que, a partir de um dado texto como entrada, o programa seja capaz de elencar as K palavras mais relevantes do texto, mostrando na tela a palavra e sua frequência.

Como exemplo, utilizemos o hino nacional brasileiro:

<div align = center> <img align src = /img/hino.png> </div>

A partir da leitura deste texto, o programa deve tratar, analisar e mostrar na tela as K palavras mais frequentes do texto.
No contexto deste exemplo, as 20 palavras mais frequentes do hino nacional brasileiro devem ser mostradas na tela, assim como a frequencia que elas aparecem.

<div align = center> <img align src = /img/saidaesperada.png> </div>



<h2 align = center>🔧 Compilação e execução </h2>
</h2>

<b>Utilizando Makefile/Make:</b>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             

<b>Usando g++: no terminal, navegue até a pasta src:</b>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `g++ main.cpp functions.cpp HeapMAX.cpp`                | Executa a compilação do programa utilizando o g++
|  `./a.out`            | Executa o programa após a compilação             
