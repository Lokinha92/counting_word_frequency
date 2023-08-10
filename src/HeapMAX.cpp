#include "HeapMAX.hpp"

void HeapMAX::prop(int index){
    int maior = index;
    int esq = 2 * index + 1; // calculando valor do filho da esquerda do indice em questao (index)
    int dir = 2 * index + 2; // calculando valor do filho da direita

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