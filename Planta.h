#ifndef PLANTA_INCLUIDA
#define PLANTA_INCLUIDA

class Planta{
	public:
		
		Planta(){
			t=0;
		}
		
		double AtualizaPlanta(double entrada, double tempoDaUltimaAtt){
			
			double saida;
			
			t += tempoDaUltimaAtt;
			
			saida = entrada * ((-2.5  * exp(-t)) + (0.8333 * exp(-3 * t)) + 1.6667);
			
			saida=Limita(saida);
			
			return saida;
		}
		
		double getTempoDecorrido(){
			return t;
		}
		
		void ResetaTempo(){
			t=0;
		}
		
	private:
		double t;
		
		double Limita(double variavelParaLimitar){
			if (variavelParaLimitar < 0) { return 0; }
            if (variavelParaLimitar > 1000) { return 1000; }

            return variavelParaLimitar;
		}
	
};

#endif
