#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>
#include<thread>

void ausgeben(std::vector<std::vector<bool>> feld){
    for(int i =0; i<feld.size(); i++){
        std::vector<bool> platzhalter= feld[i];
        for(int j=0; j<platzhalter.size(); j++){
            if(platzhalter[j]){
                std::cout<<"♥"<<std::flush; //Zeichen für eine lebende Zelle
            }
            else{
                std::cout<<"□"<<std::flush; //Zeichen für eiene tote Zelle
            }
        }
        std::cout<<""<<std::endl;
        platzhalter.clear();
    }
}

bool updateZelle(std::vector<std::vector<bool>> zustand, int stelle, int zeile) {
    int anzahlLebende = 0;
    bool zustandZelle = false;

    for (int i = std::max(0, stelle - 1); i < std::min(static_cast<int>(zustand.size()), stelle + 2); i++) {
        for (int j = std::max(0, zeile - 1); j < std::min(static_cast<int>(zustand[i].size()), zeile + 2); j++) {
            if (i == stelle && j == zeile) {
                zustandZelle = zustand[i][j];
            } else if (zustand[i][j]) {
                anzahlLebende++;
            }
        }
    }

    if (zustandZelle) { //wenn die Zelle lebt 
        return (anzahlLebende == 2 || anzahlLebende == 3);  
    } else { //wenn die Zelle tot ist 
        return (anzahlLebende == 3);
    }
}



std::vector<std::vector<bool>> einlesen(){
    std::vector<std::vector<bool>> rückgabe;
    std::vector<std::vector<bool>> empty;
    std::ifstream text; 
    text.open("spielfeld.txt");
    std::string zeile;
    std::vector<bool> zeilenvektor; 
    int zeilenlänge=-1; 
    bool erfülltBedingung=true;

    while(text){
        
        
        std::getline(text,zeile);

        for(int i=0; i<zeile.size(); i++){
            if(zeile[i]=='0'){
                zeilenvektor.push_back(1);
            }
            else if(std::isspace(zeile[i])){
                zeilenvektor.push_back(0);
            }
            else {
                erfülltBedingung=false;
            }
        }

    
        if(zeilenlänge==-1){ //wenn noch keine Länge erwartet wird wird sie festgelegt
            zeilenlänge=zeilenvektor.size();
        }
        
        rückgabe.push_back(zeilenvektor);
        
        zeilenvektor.clear();

    }

    rückgabe.pop_back(); // Die letze Zeile wird aus irgend eienem Grund doppelt eingelsen 
    text.close();
    
    for(int i=0; i<rückgabe.size(); i++){
         
        if(rückgabe[i].size()!=zeilenlänge) {
            erfülltBedingung=false;
        }
    }
    if(rückgabe.size()!=zeilenlänge){
        erfülltBedingung=false;
    }

    if(erfülltBedingung){
        std::cout<<erfülltBedingung<<std::endl;
        return rückgabe;
    } 
    else{
        std::cout<<erfülltBedingung<<std::endl;
        return empty;
    }
}

std::vector<std::vector<bool>> updateFeld(std::vector<std::vector<bool>> feld){
    std::vector<std::vector<bool>> neuesFeld; 
    std::vector<bool> zeilenvektor; 

    for(int i=0; i<feld.size(); i++){
        zeilenvektor=feld[i];
        for(int j=0; j<feld.size(); j++){
            zeilenvektor[j]=updateZelle(feld,i,j);
        }
        neuesFeld.push_back(zeilenvektor);
        zeilenvektor.clear();
    }
    return neuesFeld;
}


int main(){
    std::vector<std::vector<bool>> feld = einlesen();
    int wartezeit=2000; 
    
    std::cout << "\x1B[2J\x1B[H";
    while(42){
        
        ausgeben(feld);
        feld=updateFeld(feld);
        
        std::cout << "\x1B[2J\x1B[H";
        std::this_thread::sleep_for(std::chrono::milliseconds(wartezeit));
    }
    
    
    return 0; 

}
