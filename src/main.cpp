#include "functions.hpp"

int main(){
    string texto = LeTexto("./dataset/DomCasmurro.txt");
    unordered_set stopwords = LeStopwords("./dataset/sw.txt");

    string texto_tratado = Tratamento(texto);

    string texto_semSW = RemoveSW(texto_tratado, stopwords);

    unordered_map<string, int> frequencia = ContaFrequencia(texto_semSW);

    for(const auto& dados : frequencia){
        cout << dados.first << " : " << dados.second << endl;
    }

    return 0;
}