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
        <td> input.txt </td>    
    </tr>
    <tr>
        <td> input2.txt </td>    
    </tr>
    <tr>
        <td> input3.txt </td>    
    </tr>
        <tr>
        <td> stopwords.txt </td>    
    </tr>
</table>

<b>input.txt: Contém o texto que deve ser lido para extração das K palavras mais frequentes. O programa é capaz de ler n arquivos, basta inseri-los na pasta "dataset"</b>

<b>stopwords.txt: Contém as palavras sem relevância semântica que devem ser desconsideradas do texto.</b>


<h2 align = center> 💡ALGORITMO </h2>

- No cabeçalho do arquivo 'main.cpp' é possível definir a quantidade de arquivos que serão lidos, e também a quantidade de palavras serão mostradas na saída. Basta alterar o valor das constantes "PAL_EXIBIDAS" e "NUM_ENTRADAS"

```c++
#define PAL_EXIBIDAS 35
#define NUM_ENTRADAS 3
```

- De início, é pedido ao usuário que insira o nome dos arquivos que deverão ser lidos, no formato nomearquivo.txt. o nome desses arquivos são concatenados com o resto do endereço para a pasta dataset, os caminhos são armazenados no vector 'caminhos'.

```c++
    vector<string> caminhos;
    string prefix = "../dataset/";
    string nome_entrada;

    for(int i=0; i<NUM_ENTRADAS; i++){
        cout << "Informe o nome da entrada: ";
        cin >> nome_entrada;

        string caminho_completo = prefix + nome_entrada;

        caminhos.push_back(caminho_completo);

    }
```

- Com todos os caminhos devidamente armazenados, o vector que os contém é passado para a função 'LeTexto', que vai ler o texto contido nos arquivos passados pelo usuário, armazenar cada texto em uma string e armazenar essas strings em um novo vector. Esse vector contendo os textos é passado para a função 'Concatena' que irá concatenar todos os textos em uma única string. 

```c++
    vector<string> textos = LeTexto(caminhos);

    string textos_concatenados = Concatena(textos);
```

- Aqui, as stopwords são lidas do arquivo .txt e passadas para um unordered_set para que sejam acessadas posteriormente na fase de tratamento do texto.

```c++
   unordered_set stopwords = LeStopwords("../dataset/stopwords.txt");
```

- Nesta etapa, ocorre o tratamento dos textos lidos. A função 'Tratamento' tem como objetivo retirar a pontuação contida no texto e também converter todo o texto para letras minúsculas. O tratamento retorna uma string com o texto no formato correto, que é passado para a função 'RemoveSW' que, como o nome sugere, acessa o unordered_set contendo as stopwords e retira as palavras sem relevância semântica dos textos lidos.

```c++
    string texto_tratado = Tratamento(textos_concatenados);

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

    cout << "As " << PAL_EXIBIDAS << " palavras mais frequentes, seguidas de sua frequencia: " << endl;
    for(int i=0; i<PAL_EXIBIDAS && !HeapMaxima.Vazia(); ++i){
        DataPair pair = HeapMaxima.PesquisaMAX();
        cout << pair.palavra << " : " << pair.freq << endl;
    }

```

- Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos k elementos com maiores valores. Sua complexidade, caso implementado adequadamente, é de O(nlogk), onde n é o tamanho da coleção de dados e k o número de itens mais relevantes.

<h2 align = center> 🔍 A ESTRUTURA HEAP </h2>

<p>Heaps tem a estrutura de arvore binária, mas não de pesquisa. As seguintes propriedades podem definir um heap:</p>

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
    long unsigned int esq = 2 * index + 1; 
    long unsigned int dir = 2 * index + 2;

    if(esq < heap.size() && heap[esq].freq > heap[maior].freq){
        maior = esq;
    }

    if(dir < heap.size() && heap[dir].freq > heap[maior].freq){
        maior = dir;
    }

    if(maior != index){
        swap(heap[index], heap[maior]);
        prop(maior); 
    }
}
```
A função prop faz o papel do 'Heapfy', e é responsável por manter a estrutura de Heap máxima funcionando corretamente após inserções e remoções. Aqui, um indice da heap é passado como parâmetro e, de principio, o indice do maior valor é atribuido a esse parâmetro. O calculo dos filhos da esquerda e direita desse indice é realizado, dando forma a estrutura de Heap.

Depois é feito a verificação dos filhos da esquerda e da direita em busca de elementos fora da posição, no caso, índices que contém elementos com o atributo 'freq' maior que o do índice considerado o maior. A função é executada de forma recursiva até que todos os elementos estejam na posição adequada 

```c++
void HeapMAX::inserir(const DataPair& pair){

    heap.push_back(pair);

    int index = heap.size() - 1; 

    while(index > 0 && heap[index].freq > heap[(index - 1)/2].freq){ 
        swap(heap[index], heap[(index - 1)/2]); 
        index = (index - 1)/2; 
    }
}
```
Para a inserção de elementos, obviamnte, um elemento é inserido no vector que representa a heap. Após a inserção, a frequencia do elemento inserido é comparado com a frequencia do seu elemento pai, e caso seja maior, eles são trocados de lugar e o índice do filho é atualizado para o índice do pai. Esse processoé repetido até que o elemento inserido esteja no nó raiz (ou seja, um novo elemento máximo), ou até que a frequencia seja menor que a do elemento pai.

```c++
DataPair HeapMAX::PesquisaMAX(){

    DataPair Max = heap.front(); 
    heap[0] = heap.back(); 
    heap.pop_back(); 
    prop(0);

    return Max;
}
```
Essa função é responsável por extrair o elemento máximo da heap.
O elemento máximo é extraído e armazenado no objeto 'Max'. Depois, o ultimo elemento da heap é passado para o nó raiz e a posição onde ele se encontrava é removida, ou seja, o maior elemento anterior saiu da heap. Como a estrutura foi modificada, a função prop (Heapfy) é chamada para que a estrutura seja reorganizada.

```c++
bool HeapMAX::Vazia(){
    return heap.empty();
}
```
Aqui, é simplesmente feita uma verificação se há elementos na Heap.

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
vector<string> LeTexto(vector<string> entradas);
string Concatena(vector<string> textos);
string Tratamento(const string& texto);

unordered_set<string> LeStopwords(const string& caminhoArquivo);

string RemoveSW(const string& textoTratado, unordered_set<string>& stopwords);

unordered_map<string, int> ContaFrequencia(const string& texto);
```

```c++
vector<string> LeTexto(vector<string> entradas): É responsável por percorrer o vector contendo os caminhos para os arquivos de texto, ler e armazenar em uma string e armazenar essas strings em um novo vector.

string Concatena(vector<string> textos): É responsável por percorrer o vector contendo as strings com os textos armazenados e concatená-los em uma única string.

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

vector<string> LeTexto(vector<string> entradas){
    vector<string> textos;
    string conteudo;

    for(int i=0; i<entradas.size(); i++){
        fstream arquivo(entradas[i]);
        

        if(arquivo.is_open()){
            string linha;

            while(getline(arquivo, linha)){
                conteudo += linha + "\n";
            }

            textos.push_back(conteudo);

            conteudo = "";

            arquivo.close();
        } else {
            cout << "Erro ao abrir arquivo" << endl;
        }
    }

    return textos;
}

```
Aqui, o vector contendo o caminho das entradas é percorrido, o arquivo referente a cada caminho é lido, armazenado em uma string e armazenado em um novo vector chamado 'textos'.

```c++

string Concatena(vector<string> textos){
    string textos_concatenados;

    for(int i=0; i<textos.size(); i++){
        textos_concatenados += textos[i] + "\n";
    }

    return textos_concatenados;
}
```
Nessa função o vector 'textos' contendo as strings com os dados de entrada é percorrido e todos os textos são concatenados em uma unica string.

```c++

string Tratamento(const string& texto){
    string Texto_tratado = texto;

    transform(Texto_tratado.begin(), Texto_tratado.end(), Texto_tratado.begin(), ::tolower); // minusculas

    replace(Texto_tratado.begin(), Texto_tratado.end(), '-', ' ');

    Texto_tratado.erase(remove_if(Texto_tratado.begin(), Texto_tratado.end(), ::ispunct), Texto_tratado.end()); // tirando pontos

    return Texto_tratado;
}

```
O tratamento é realizado nessa função, a string contendo os textos concatenados é tratada passando todo o conteúdo para o formato minúsculo, os hífens são substituídos por espaços e também é retiranda toda a pontuação contida.

```c++

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

```
Nessa função, as stopwords são lidas e armazenadas em um unordered_set.

O unordered_set é um contêiner que armazena elementos únicos sem chaves associadas. Cada elemento é seu próprio valor distinto, e não há associação explícita entre chaves e elementos. Ele é projetado para armazenar e recuperar elementos de maneira eficiente. Dessa forma, se torna uma boa opção para armazenar as stopwords com fins de acessá-las posteriormente para a remoção das stopwords do texto.

O unordered_set trata colisões com a estratégia de endereçamento fechado, ou seja, cada posição da tabela hash contém uma lista simplesmente encadeada, e registros iguais são adicionados a sua respectiva lista.

```c++

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
```
Essa função faz o tratamento final das entradas, retirando as palavras sem relevância semântica (stopwords) dos arquivos de entrada. O texto retornado deve estar devidamente tratado para que a contagem de palavras seja feita.

```c++

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

Finalmente, a contagem das palavras é feita dentro da estrutura unordered_map, armazenando um par do tipo <string, int>, onde a string representa a palavra e o inteiro representa a frequencia da palavra nos arquivos de entrada.

A escolha dessa estrutura se deu justamente pelo fato da fácil associação de chave-valor, no caso, palavra-frequencia. Assim como o unordered_set, o unordered_map trata colisões com a estratégia de endereçamento fechado.

Dessa forma, ao mesmo tempo que as palavras são inseridas no unordered_set, é verificado se ela já está presente. Caso esteja, o contador de frequencia é incrementado em 1, se não, a chave (palavra) é inserida e o contador de frequencia é inicializado em 1.

Dessa forma, é esperado que a leitura, o tratamento e a contagem das palavras seja realizada de forma correta ao fim da utilização de todas as função descritas.

<h2 align = center>📈 Resultados esperados</h2>

É esperado que, a partir de n textos passados como entrada, o programa seja capaz de elencar as K palavras mais relevantes, mostrando na tela a palavra e sua frequência.

Como exemplo, utilizemos o hino nacional brasileiro:

<div align = center> <img align src = /img/hino.png> </div>

A partir da leitura deste texto, o programa deve tratar, analisar e mostrar na tela as K palavras mais frequentes do texto.
No contexto deste exemplo, as 20 palavras mais frequentes do hino nacional brasileiro devem ser mostradas na tela, assim como a frequencia que elas aparecem.

<div align = center> <img align src = /img/saidaesperada.png> </div>



<h2 align = center>🔧 Compilação e execução </h2>
</h2>
      

<b>No terminal, navegue até a pasta src:</b>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `g++ main.cpp functions.cpp HeapMAX.cpp`                | Executa a compilação do programa utilizando o g++
|  `./a.out`            | Executa o programa após a compilação             
