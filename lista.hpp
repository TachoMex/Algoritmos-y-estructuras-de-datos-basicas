template<class T>
class nodoLista{
	public:
		nodoLista *sig;
		T dato;	
};

template<class T>
class lista_abstracta{
	//protected:
	public:
		int tam;
		nodoLista<T> *inicio;
		nodoLista<T> *fin;

	public:
	virtual void push(const T&)=0;
	virtual T pop()=0;	


	void insertaInicio(const T& elem){
		nodoLista<T> *nuevo = new nodoLista<T>();
		nuevo->dato=elem;
		nuevo->sig=inicio;
		inicio=nuevo;
		if(fin==nullptr){
			fin=inicio;
		}
		tam++;
	}

	void insertaFinal(const T& elem){
		nodoLista<T> *nuevo=new nodoLista<T>();
		nuevo->dato=elem;
		nuevo->sig=nullptr;
		if(fin==nullptr){
			fin=nuevo;
		}else{
			fin->sig=nuevo;
			fin=nuevo;
		}
		if(inicio==nullptr){
			inicio=fin;
		}
			tam++;
	}

	void eliminaInicial(){
		nodoLista<T> *aux=inicio->sig;
		delete inicio;
		inicio=aux;
		tam--;
	}

	T datoInicial(){
		return inicio->dato;
	}

	virtual T& operator[](int n){

	}

	lista_abstracta(){
		tam=0;
		inicio=nullptr;
		fin=nullptr;
	}

	bool vacia(){
		return tam==0;
	}

};

template<class T>
class pila:public lista_abstracta<T>{
public:
	void push(const T& elem){
		this->insertaInicio(elem);
	}

	T pop(){
		T elem=this->datoInicial();
		this->eliminaInicial();
		return elem;
	}
};

template<class T>
class cola:public lista_abstracta<T>{
public:
	void push(const T& elem){
		this->insertaFinal(elem);
	}

	T pop(){
		T elem=this->datoInicial();
		this->eliminaInicial();
		return elem;
	}
};

template<class T>
class lista:public lista_abstracta<T>{
public:
	T& operator[](int idx){
		nodoLista<T> *aux=this->inicio;
		for(int i=0;i<idx;i++){
			aux=aux->sig;
		}
		return aux->dato;
	}

	void inserta(int idx, const T& elem){
		if(this->fin=nullptr){
			this->inicio = new nodoLista<T>();
			this->fin=this->inicio;
			this->fin->sig=nullptr;
			this->fin->dato=elem;
		}
	}
	void push(const T& e){

	}
	T pop(){

	}
};
