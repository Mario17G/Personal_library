#include <bits/stdc++.h>
using namespace std;

struct libro{
	int id;
	string title;
	string author;
	int year;
};


void add(vector<libro> &lista){
	int tam = lista.size();
	libro aux;
	int band;

	do{
		band = 0;
		cout << "Enter the book id:" << endl;
		cin >> aux.id;
		for(int i = 0; i < tam; i++){
			if (lista[i].id == aux.id){
				cout << "Repeated ID, please enter a unique ID:"<< endl;
				band = 1;
			}
		}


	}while(band != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter the title of the book:" << endl;
	getline(cin, aux.title);


	cout << "Enter the author of the book:" << endl;
	getline(cin, aux.author);

	cout << "Enter the year of publication of the book:" << endl;
	cin >> aux.year;

	lista.push_back(aux);
}

void show(vector<libro>& lista){

	if (lista.empty()){
		cout<<"\nHERE ARE NO BOOKS!\n" << endl;
		return;
	}

	int tam = lista.size();

	cout << "\nBOOK LIST \n"<<endl;

	for(int i = 0; i < tam; i++){
		cout << "ID: "<< lista[i].id<<endl;
		cout << "TITLE: "<< lista[i].title<<endl;
		cout << "AUTHOR: "<< lista[i].author<<endl;
		cout << "YEAR: "<< lista[i].year<<endl;
		cout << "_________________________"<<endl;
	}
}

void edit(vector<libro> &lista){
	int tam = lista.size();
	libro aux;
	int id;

	cout << "Enter the book id:" << endl;
	cin >> id;

	for(int i = 0; i < tam; i++){
		if (lista[i].id == id){
			aux.id = lista[i].id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter the title of the book:" << endl;
			getline(cin, aux.title);
			cout << "Enter the author of the book:" << endl;
			getline(cin, aux.author);
			cout << "Enter the year of publication of the book:" << endl;
			cin >> aux.year;

			lista[i] = aux;

			return;
		}
	}
	
	cout << "Please enter a valid ID:"<<endl;
}

void del(vector<libro> &lista){
	int tam = lista.size();
	int id;

	cout << "Enter the book id:" << endl;
	cin >> id;

	for(int i = 0; i < tam; i++){
		if (lista[i].id == id){
			lista.erase(lista.begin() + (i));
			break;
		}
	}
	
	cout << "Please enter a valid ID:"<<endl;
}


int main() {
    
    vector<libro> biblioteca;
    int opcion;

    do{

    	cout <<"\n-----------LIBRARY-----------"<< endl;
    	cout <<"1)ADD BOOK"<< endl;
    	cout <<"2)SHOW BOOKS"<< endl;
    	cout <<"3)EDIT BOOK"<< endl;
    	cout <<"4)DELETE BOOK"<< endl;
    	cout <<"5)EXIT"<< endl;
    	cin >> opcion;

    	switch(opcion){

    		case 1: 
    			add(biblioteca);
    			break;
    		case 2: 
    			show(biblioteca);
    			break;
    		case 3: 
    			edit(biblioteca);
    			break;
    		case 4:
    			del(biblioteca); 
    			break;
    		case 5: 
    			break;
    		default: cout << "Please enter a valid option:"<< endl;

    	}
    	
    }while(opcion != 5 );

    return 0;
}