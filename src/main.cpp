#include "functions.hpp"
#include "HeapMAX.hpp"
#define PAL_EXIBIDAS 20
#define NUM_ENTRADAS 1

int main(){
    vector<string> caminhos;
    string prefix = "../dataset/";
    string nome_entrada;

    for(int i=0; i<NUM_ENTRADAS; i++){
        cout << "Informe o nome da entrada: ";
        cin >> nome_entrada;

        string caminho_completo = prefix + nome_entrada;

        caminhos.push_back(caminho_completo);

    }


    vector<string> textos = LeTexto(caminhos);

    string textos_concatenados = Concatena(textos);
    
    unordered_set<string> stopwords = LeStopwords("../dataset/stopwords.txt");

    string texto_tratado = Tratamento(textos_concatenados);

    string texto_semSW = RemoveSW(texto_tratado, stopwords);

    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);

    HeapMAX HeapMaxima;

    for(const auto& item : frequencia){
        HeapMaxima.inserir(DataPair(item.first, item.second));
    }

    cout << "As " << PAL_EXIBIDAS << " palavras mais frequentes, seguidas de sua frequencia: " << endl;
    for(int i=0; i<PAL_EXIBIDAS && !HeapMaxima.Vazia(); ++i){
        DataPair pair = HeapMaxima.PesquisaMAX();
        cout << pair.palavra << " : " << pair.freq << endl;
    }

    return 0;
}