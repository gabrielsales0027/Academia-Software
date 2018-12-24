#include "academia.h"

int academia::getAcima_do_peso() const
{
    return acima_do_peso;
}

void academia::setAcima_do_peso(int value)
{
    acima_do_peso = value;
}

void academia::ordenarNome()
{
     std::sort(gym.begin(), gym.end(), [](pessoa a, pessoa b){return a.getNome()<b.getNome();});
}

void academia::ordenarImc()
{
    ordenarNome();
    std::stable_sort(gym.begin(),gym.end(),[](pessoa a, pessoa b){return a.getImc()<b.getImc();});
}

pessoa academia::operator[](int i)
{

        return gym[i];
}

academia::academia()
{

}

void academia::inserirPessoa(const pessoa p)
{
    gym.push_back(p);
}

void academia::acimaDoPeso()
{
    for(int i = 0; i < gym.size();i++){
        if(gym[i].getImc()> 25){
            acima_do_peso += 1;
        }
    }
}

float academia::maiorImc()
{
    pessoa *maior = std::max_element(gym.begin(),gym.end(),[](pessoa a, pessoa b){ return a.getImc() < b.getImc();});
    return maior->getImc();
}

float academia::saldo()
{
    float s = 0;
    for(int i = 0; i < gym.size();i++){
        s += gym[i].getPlano();
        }
    return s*mensalidade;
}

void academia::clear()
{
    gym.clear();
}

int academia::size()
{
       return gym.size();

}

int academia::find(QString nome)
{
    for(int i = 0; i<gym.size();i++){
        if(gym[i].getNome() == nome){
            return i;
        }
    }
    return -1;
}

