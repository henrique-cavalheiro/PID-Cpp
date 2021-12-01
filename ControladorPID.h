#ifndef PID_INCLUIDO
#define PID_INCLUIDO

class ControladorPID{
	public:
	
		ControladorPID(double Kp,double Ki, double Kd, double SaidaMax, double SaidaMin)
		{
			this->Kp=Kp;
			this->Ki=Ki;
			this->Kd=Kd;
			this->SaidaMax=SaidaMax;
			this->SaidaMin=SaidaMin;
		}
		
		double VariavelControle(double tempoDaUltimaAtt)
		{
			double erro = ValorDesejado - VariavelProcesso;
			
			TermoIntegral += Ki * erro * tempoDaUltimaAtt;
			TermoIntegral = Limita(TermoIntegral);
			
			double entradaD = VariavelProcesso - UltimaVariavelProcesso;
			double termoDerivativo = Kd * (entradaD / tempoDaUltimaAtt);
			
			double termoProporcional = Kp * erro;
			
			double saida = TermoIntegral + termoProporcional - termoDerivativo;
			saida = Limita(saida);
			
			return saida;
		}
		
		void setKp(double kp){Kp=kp;}
		double getKp(){return Kp;}
		
		void setKi(double ki){Ki=ki;}
		double getKi(){return Ki;}
		
		void setKd(double kd){Kd=kd;}
		double getKd(){return Kd;}
		
		double getSaidaMax(){return SaidaMax;}
		
		double getSaidaMin(){return SaidaMin;}
		
		void setTermoIntegral(double termoIntegral){TermoIntegral=termoIntegral;}
		double getTermoIntegral(){return TermoIntegral;}
		
		void setVariavelProcesso(double variavelProcesso)
		{
			UltimaVariavelProcesso = VariavelProcesso;
			VariavelProcesso = variavelProcesso;
		}
		double getUltimaVariavelProcesso(){return UltimaVariavelProcesso;}
		
		void setValorDesejado(double valorDesejado){ValorDesejado=valorDesejado;}
		double getValorDesejado(){return ValorDesejado;}
		
		
		private:
			
			double Kp=0,Ki=0,Kd=0,SaidaMax=0,SaidaMin=0,TermoIntegral=0,VariavelProcesso=0,UltimaVariavelProcesso=0,ValorDesejado=0;
			
			double Limita(double variavelParaLimitar){
				if(variavelParaLimitar < SaidaMin){return SaidaMin;}
				if(variavelParaLimitar > SaidaMax){return SaidaMax;}
				
				return variavelParaLimitar;
			}
};

#endif

