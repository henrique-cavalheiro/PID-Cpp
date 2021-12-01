#include <iostream>
#include <math.h>
#include "ControladorPID.h"
#include "Planta.h"
#include "Atuador.h"
//#include <stdlib.h>
#include <windows.h>

using namespace std;

int main(){
	
	ControladorPID pid(0,0,0,100,10);
	Atuador atuador;
	Planta planta;
	double tempoDaUltimaAtt = 0.1, Kp, Ki,Kd,ValorDesejado,VariavelProcesso=0,Saida,contador=0;
	double saidaPlanta = 0, saidaAtuador = 0, tempoSimulacao=0;
	
	cout << "\t\t\t\t\t\tControlador PID" << endl << endl;
	cout << "Este programa faz o controle PID de uma variavel hipotetica, que tem um valor minimo de 0 e maximo de 1000.";
	cout << "O usuario deve escolher o valor o qual se deseja obter.";
	cout << "A variavel representa uma planta com uma funcao de transferencia G=5/(s^2 + 4*s + 3),";
	cout << "e para controlar este valor sera necessario escolher os ganhos proporcional, integral e derivativo." << endl;
	cout << "A simulacao dura 15 s e depois se encerra." << endl << endl;
	system("pause");
	system("cls");
	

	cout << "Digite o valor do ganho proporcional:";
	while(!(cin >> Kp)){
		cout << "Erro: digite um numero real:";
		cin.clear();
		cin.ignore(40,'\n');
		}
	pid.setKp(Kp);
	

	cout << "Digite o valor do ganho integral:";
	while(!(cin >> Ki)){
		cout << "Erro: digite um numero real:";
		cin.clear();
		cin.ignore(40,'\n');
		}	
	pid.setKi(Ki);
	

	cout << "Digite o valor do ganho derivativo:";
	while(!(cin >> Kd)){
		cout << "Erro: digite um numero real:";
		cin.clear();
		cin.ignore(40,'\n');
		}
	pid.setKd(Kd);
	
	cout << "Digite o valor desejado para a saida:";
	while(!(cin >> ValorDesejado) || ValorDesejado < 0 || ValorDesejado > 1000){
		cout << "Erro: digite um numero real entre 0 e 1000:";
		cin.clear();
		cin.ignore(40,'\n');
		}
	pid.setValorDesejado(ValorDesejado);
	pid.setVariavelProcesso(0);
	pid.setTermoIntegral(0);
	planta.ResetaTempo();
	saidaPlanta=0;
	tempoDaUltimaAtt=0.1;
	
	
	while(1)
	{
		
		pid.setVariavelProcesso(saidaPlanta);
		atuador.setEntradaAtual(pid.VariavelControle(tempoDaUltimaAtt));
		saidaAtuador = atuador.Atuar(tempoDaUltimaAtt);
		saidaPlanta = planta.AtualizaPlanta(saidaAtuador,tempoDaUltimaAtt);

		Saida = saidaPlanta;
		
		system("cls");
		cout << "Saida:" << Saida << endl << "Tempo decorrido:" << tempoSimulacao<< endl;
		Sleep(100);
		tempoSimulacao+=0.1;
		if(tempoSimulacao>=15){
			break;
		}
	}
	
	system("pause");
	
	return 0;
	
}
