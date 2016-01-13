#ifndef TRIE_H
#define TRIE_H
#include<iostream>
#include<cstring>
#ifndef null
#define null NULL
#endif
using namespace std;

class nodoTrie{
	public:
		nodoTrie *hojas[27];
		nodoTrie();
};

nodoTrie *EOW= new nodoTrie();

class trie{
	public:
		nodoTrie * raiz;
		trie();
		void agregarPalabra(const char *);
		void imprime();
		bool existe(const char *);
		void opciones(const char *);
	private:
		void imprime(nodoTrie*,const char *);
};

nodoTrie::nodoTrie(){
	for(int i=0;i<27;i++)
		hojas[i]=null;
}

trie::trie(){
	raiz=new nodoTrie();
}

void trie::agregarPalabra(const char * p){
	nodoTrie * actual = raiz;
	while(actual->hojas[*p-'a'] != null && *p != '\0'){
		actual=actual->hojas[*p-'a'];
		p++;
	}
	while(*p!='\0'){
		actual->hojas[*p-'a']=new nodoTrie();
		actual=actual->hojas[*p-'a'];
		p++;
	}
	actual->hojas[26]=EOW;
}

void trie::imprime(){
	char *p = new char[1]; 
	*p='\0';
	this->imprime(raiz,p);
}

void trie::imprime(nodoTrie *actual,const char * p){
	if(actual->hojas[26]==EOW)
		cout<<p<<endl;
	for(int i=0;i<26;i++){
		if(actual->hojas[i]!=null){
			int size=strlen(p);
			char *aux=new char[size+1];
			strcpy(aux,p);
			*(aux+size)='a'+i;
			*(aux+size+1)='\0';
			this->imprime(actual->hojas[i],aux);
		}
	}
}

bool trie::existe(const char * p){
	nodoTrie * actual = raiz;
	while(*p==' ')
		p++;
	while(*p!='\0'){
			if(*p > 'z' || *p<'a')
				return false;
			if(actual->hojas[*p-'a']==null)
				return false;
			actual=actual->hojas[*p-'a'];
		p++;
	}
	if(actual==null) 
		return false;
	if(actual->hojas[26] == EOW)
		return true;
	return false;
}

void trie::opciones(const char * p){
	const char *aux=p;
	nodoTrie * actual=raiz;
	while(*p!='\0'){
		if(actual->hojas[*p-'a']==null)
			return;
		actual=actual->hojas[*p-'a'];
		p++;
	}
	imprime(actual,aux);
}

#endif