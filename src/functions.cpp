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