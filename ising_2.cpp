#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include<stdio.h>
#include <list>


using namespace std;

void print(string tes){
    cout << tes << endl;
    }
void printi(int f){
    cout << f << endl;
    }
void printd(double f){
    cout << f << endl;
    }


double rm = RAND_MAX;
double rand11(){
    return (rand()/rm)*2.0-1.0;
    }
double rand01(){
    return (rand()/rm);
    }


class rede{

    public:

        int lado = 10; double temperatura;double H = 0;
        double energia; double media_energia; double dp_energia;
        vector<vector<int> > matriz;
        double magnetizacao; double media_mag; double dp_mag;

        void ocupa(){
            for (int i = 0; i < lado; i++){
                vector<int> temp;
                for (int j = 0; j < lado; j++){
                    temp.push_back(1);
                }
                matriz.push_back(temp);
                    }
            }

        void sweep(){
            energia = 0; magnetizacao = 0;
            for (int i = 0; i < lado; i++){
                for (int j = 0; j < lado; j++){

                    double energia1 = 0; double energia2 = 0;
                    double valor = matriz[i][j];

                    if (i == 0){energia1 = energia1 + valor*matriz[lado-1][j];
                                energia2 = energia2 - valor*matriz[lado-1][j];}
                    else {energia1 = energia1 + valor*matriz[i-1][j];
                        energia2 = energia2 - valor*matriz[i-1][j];}

                    if (i == lado-1){energia1 = energia1 + valor*matriz[0][j];
                            energia2 = energia2 - valor*matriz[0][j];}
                    else {energia1 = energia1 + valor*matriz[i+1][j];
                           energia2 = energia2 - valor*matriz[i+1][j];}

                    if (j == 0){energia1 = energia1 + valor*matriz[i][lado-1];
                            energia2 = energia2 - valor*matriz[i][lado-1];}
                    else {energia1 = energia1 + valor*matriz[i][j-1];
                        energia2 = energia2 - valor*matriz[i][j-1];}

                    if (j == lado-1){energia1 = energia1 + valor*matriz[i][0];
                        energia2 = energia2 - valor*matriz[i][0];}
                    else {energia1 = energia1 + valor*matriz[i][j+1];
                        energia2 = energia2 - valor*matriz[i][j+1];}

                    energia2 = energia2*-1 -H*matriz[i][j]*-1;
                    energia1 = energia1*-1 - H*matriz[i][j];

                    if (energia2 - energia1 <= 0){
                        matriz[i][j] = matriz[i][j]*-1;
                        energia = energia + energia2;}
                    else{
                        float r = rand01();

                        if(r <= exp(-(energia2-energia1)/temperatura)){
                            matriz[i][j] = matriz[i][j]*-1;
                            energia = energia + energia2;}
                        else{
                            energia = energia + energia1;}
                        }
                    magnetizacao = magnetizacao + matriz[i][j];
                    }
                }
            magnetizacao = magnetizacao/double(pow(lado,2));
            energia = energia/double(2);
            }


        void mag_x_tempo(int n = 10000, string arquivo = "teste"){

                ofstream arq;
                arq.open(arquivo.c_str());
                for (int i = 0; i < n; i++){
                    sweep();
                    arq << i << "\t" << magnetizacao << "\n";
                    }

            arq.close();
            }

        void media_mag_func(double temp = 1){
            temperatura = temp;

            float dp = 2;double mag;

            double media = 0;
            double soma = 0; double soma2 = 0;
            double soma_energia = 0;double soma2_energia = 0;


            // chagar no equilibrio
            for(int i = 0; i < 1000; i ++){
                sweep();
                }
            // media

            for(int i = 0; i < 5000; i ++){
                sweep();
                soma = soma + magnetizacao;
                soma2 = soma2 + pow(magnetizacao,2);
                soma_energia = soma_energia + energia;
                soma2_energia = soma2_energia + pow(energia,2);

                }
            // desvio padrao
            media = soma/5000;media_energia = (soma_energia/5000);

            dp = sqrt(soma2/5000 - pow(media,2)); dp_energia = sqrt(soma2_energia/5000 - pow(media_energia,2));
            // fazer energia por spin
            dp_energia = dp_energia/sqrt(pow(lado,2)); media_energia = media_energia/double(pow(lado,2));
            //cout << dp << "\t" << temperatura << "\t"<< media <<"\n";
            media_mag = media; dp_mag = dp;

            }

        void media_x_temp(){
            ofstream arq,arq2;
            arq.open("mag_x_temp2");arq2.open("e_x_temp2");
            int tamanho = 10;
            double lista[tamanho] = {2,2,2.21,2.22,2.23,2.24,2.25,2.26,2.265,2.268};
            for (int i = 1; i < tamanho; i++){
                ocupa();
                media_mag_func(lista[i]);
                if (media_mag < 0){media_mag = media_mag*-1;}
                arq << lista[i] << "\t" << media_mag << "\t"<< dp_mag << "\n";
                arq2 << lista[i] << "\t" << media_energia << "\t" <<dp_energia << "\n";
                }
            arq.close();arq2.close();
            }

    void correlacao(){
        for(int x = 0; x < int(lado/2); x++){
            for (int y = 0; y < int(lado/2); y++){

                }
            }
        }

    };

void magnetizacao_tempo(){
    rede r; r.lado = 10;
    double lista[6] = {1.5,2,2.25,2.7,4,6};
    string ls[6] = {"t1.5","t2","t2.25","t2.7","t4","t6"};
    for(int i = 0; i < 6; i++){
        cout << lista[i] << "\n";
        r.temperatura = lista[i];r.ocupa();
        r.mag_x_tempo(1000,ls[i]);

        }
    }

void mag_x_h(){

    rede rrr; rrr.lado = 50;
    double listah[10] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

    double listat[1] = {2.27};
    string listas[1] = {"h2.27"};


    for (int t = 0; t < 1; t++){
        ofstream arq; arq.open(listas[t].c_str());

        for(int h = 0; h < 10; h++){
            rrr.H = listah[h];
            rrr.ocupa();
            rrr.media_mag_func(listat[t]);
            cout << listat[t] << "\n";
            arq << rrr.H << "\t" << rrr.magnetizacao << "\n";

            }
        arq.close();
        }
    }
int main()
{

    mag_x_h();
    cout << 'asdas';
    //magnetizacao_tempo();

    //rede r;r.lado = 100;r.ocupa();
    //r.temperatura = 2.27;
    //r.mag_x_tempo();
    //r.media_mag_func();
    //r.media_x_temp();
    //r.temperatura = 1;
    //r.mag_x_tempo();

}
