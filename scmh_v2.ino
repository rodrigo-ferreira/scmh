/*
* Classe que representa a leitura de dados
*/
class LeituraDados {
  private:
  
  String _data = "";
  int _valor = 0;
  
  public:

  String getData(){return _data;}
  void setData(String v){_data = v;}
  int getValor(){return _valor;}
  void setValor(int v){_valor = v;}
};

/*
* Classe que represnta os dados de um hidrometro
*/
class HidrometroDados {
  private:
  
  String _numero = "";
  int _estadoSensor = 2;
  float _relacaoRevolucao = 1;
  LeituraDados _leituraDados;
  
  public:

  String getNumero(){return _numero;}
  void setNumero (String v){_numero = v;}
  int getEstadoSensor(){return _estadoSensor;}
  void setEstadoSensor(int v){_estadoSensor = v;}
  float getRelacaoRevolucao(){return _relacaoRevolucao;}
  void setRelacaoRevolucao(float v){_relacaoRevolucao = v;}
  LeituraDados getLeitura() {return _leituraDados;}
  void setLeitura(LeituraDados v){_leituraDados = v;}
  
};

/*
* Classe que representa um hidrometro
*/
class Hidrometro {
  private:

  HidrometroDados _dados;
  
  public:

  HidrometroDados getDados(){return _dados;}
  void setDados(HidrometroDados v){_dados = v;}

  void leSensor(){}
  
};

class EconomiaDados {
  private:

  /* Categoria da economia. Ela pode ser 
   *  DOM - Domiciliar
   *  COM - Comercial
   *  IND - Industrial
   *  PUB - Pública
  */
  String _categoria = "";
  HidrometroDados _hidrometroDados;
  
  public:

  // Cria os dados de uma economia
  EconomiaDados(){
    _categoria = "DOM";
  }
  
  // Cria os dados de uma economia a partir de sua matricula
  EconomiaDados(String v){
    _categoria = v;
  }

  // Cria os dados de uma economia com os dados do hidrometro
  EconomiaDados(HidrometroDados h){
    _categoria = "DOM";
    _hidrometroDados = h;
  }
  
  // Cria os dados de uma economia com a categoria de economia e os dados do hidrometro
  EconomiaDados(String c, HidrometroDados h){
    _categoria = c;
    _hidrometroDados = h;
  }

  // Cria os dados de uma economia com a categoria de economia e o número do hidrometro associado
  EconomiaDados(String c, String hn){
    _categoria = c;
    _hidrometroDados.setNumero(hn);
  }
  
  String getCategoria(){return _categoria;}
  void setCategoria (String v){_categoria = v;}
  HidrometroDados getDados(){return _hidrometroDados;}
  void setDados(HidrometroDados v){_hidrometroDados = v;}
};

/*
* Classe que representa os dados de um Imovel
*/
class ImovelDados {
  private:
  
  // Matrivula do imovel
  String _matricula = "";
  
  public:

  String getmatricula(){return _matricula;}
  void setmatricula(String v){_matricula = v;}
};

/*
* Classe que represnta os dados de uma fatura
*/
class FaturaDados {
  private:

  String _competencia = "";
  HidrometroDados _hidrometroDados;
  LeituraDados _leituraAtual;
  LeituraDados _leituraAnterior;

  public:

  String getCompetencia(){return _competencia;}
  void setCompetencia(String v){_competencia = v;}
  HidrometroDados getHidrometroDados(){return _hidrometroDados;}
  void setHidrometroDados(HidrometroDados v){_hidrometroDados = v;}
  LeituraDados getLeituraAtual(){return _leituraAtual;}
  void getLeituraAtual(LeituraDados v){_leituraAtual = v;}
  LeituraDados getLeituraAnterior(){return _leituraAtual;}
  void getLeituraAnteriror(LeituraDados v){_leituraAnterior = v;}
};

class Economia {
  private:
  
  EconomiaDados _dados;
  Hidrometro _hidrometro;
  
  public:

  // Instancia uma economia com os seus dados e seu hidrometro
  Economia(){};

  // Instancia uma economia com os seus dados e seu hidrometro
  Economia(EconomiaDados d, Hidrometro h){
    _hidrometro = h;
    _dados = d;
  };
  
  EconomiaDados getDados(){return _dados;}
  void setDados(EconomiaDados v){_dados = v;}
  Hidrometro getHidrometro(){return _hidrometro;}
  void setHidrometro(Hidrometro v){_hidrometro = v;}
};

/*
* Classe que representa um imóvel
*/
class Imovel {
  private:

  ImovelDados _dados;
  //Economia* *_economias[];
  List<Economia> _economias;
  
  public:

  // Instancia um imovel acrescentando uma única economia associada ao mesmo
  Imovel(){
    Imovel(1);
  }

  // Instancia um imovel acrescentando as economias associadas ao mesmo
  Imovel(Economia *ecs[]){
    *_economias = ecs;
  }

  // Instancia um imovel acrescentana a quantidade de economias indicada no parametro economiasTot
  Imovel(int economiasTot){
    Economia* ecs[economiasTot];
    for (int i = 0; i < economiasTot; i++){
      Economia e;
      ecs[i]= e;
    }
    *_economias = ecs;
  }
  
  ImovelDados getDados(){return _dados;}
  void setDados(ImovelDados v){_dados = v;}
  Economia* getEconomias(){return *_economias;}
  void setEconomias(Economia* *v[]){_economias = *v;}
  
};

#define ECONOMIA_TOT 8
Imovel im(ECONOMIA_TOT);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  //Após esperar um intervalo de tempo prédeterminado faz a varredura nos sensores
  if (sizeof(im.getEconomias)>0){
    for (int i=0;i< sizeof(im.getEconomias);i++){
      Economia e = im.getEconomias[i];
      Hidrometro h = e.getHidrometro();
      h.leSenor();
    }  
  }
}
