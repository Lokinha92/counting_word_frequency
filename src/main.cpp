#include "functions.hpp"
#include "HeapMAX.hpp"
#define MAX 20

int main(){
    string texto = LeTexto("../dataset/hino.txt");
    unordered_set stopwords = LeStopwords("../dataset/stopwords.txt");

    string texto_tratado = Tratamento(texto);

    string texto_semSW = RemoveSW(texto_tratado, stopwords);

    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);

    HeapMAX HeapMaxima;

    for(const auto& item : frequencia){
        HeapMaxima.inserir(DataPair(item.first, item.second));
    }

    cout << "As " << MAX << " palavras mais frequentes, seguidas de sua frequencia: " << endl;
    for(int i=0; i<MAX && !HeapMaxima.Vazia(); ++i){
        DataPair pair = HeapMaxima.PesquisaMAX();
        cout << pair.palavra << " : " << pair.freq << endl;
    }

    return 0;
}