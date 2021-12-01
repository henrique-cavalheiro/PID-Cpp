#ifndef ATUADOR_INCLUIDO
#define ATUADOR_INCLUIDO

class Atuador{
	public:
		
		Atuador(){
			t = 0;
			entradaAtual=0;
			saida=1000;
		}
		
		double Atuar(double tempoDaUltimaAtt){
			
			t += tempoDaUltimaAtt;
			
			if(entradaAtual > entradaAnterior){
				if(flag1==false){
					flag1=true;
					flag2=false;
					t=0;
				}
				saida = saida * exp((entradaAtual/1000) * t);
			}
			
			if(entradaAtual <= entradaAnterior){
				if(flag2 == false){
					flag1=false;
					flag2=true;
					t=0;
				}
				saida = saida * exp((-entradaAtual/1000) * t);
			}
			
			return saida;
		}
		
		double getEntradaAtual(){
			return entradaAtual;
		}
		void setEntradaAtual(double value){
			entradaAnterior = entradaAtual;
			entradaAtual = value;
		}
		
	private:
		double t, entradaAtual,entradaAnterior, saida;
		bool flag1 = false, flag2 = false;
};

#endif
