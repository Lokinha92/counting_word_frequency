#include "functions.hpp"
#include "HeapMAX.hpp"

int main(){
    string texto = LeTexto("../dataset/DomCasmurro.txt");
    unordered_set stopwords = LeStopwords("../dataset/sw.txt");

    string texto_tratado = Tratamento(texto);

    string texto_semSW = RemoveSW(texto_tratado, stopwords);

    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);

    HeapMAX HeapMaxima;

    for(const auto& item : frequencia){
        HeapMaxima.inserir(DataPair(item.first, item.second));
    }

    cout << "As 20 palavras mais frequentes: " << endl;
    for(int i=0; i<20 && !HeapMaxima.Vazia(); ++i){
        DataPair pair = HeapMaxima.PesquisaMAX();
        cout << pair.palavra << " : " << pair.freq << endl;
    }

    return 0;
}