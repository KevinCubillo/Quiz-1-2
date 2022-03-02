#include <iostream>
#include <bits/stdc++.h>
#define DEFAULT_MAX_SIZE 1024

using namespace std;


class Media{

private:
    int tipo;
    string descripcion;
    string fecha;
    string autor;
    int duracion;

public:

    Media(int tipo=0, string descripcion="", string fecha ="", string autor =""){ // tipo 0 IMAGEN
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->autor = autor ;
    }
    Media (int tipo = 1, string descripcion ="", string fecha ="", int duracion =0){ //tipo 1 VIDEO
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->duracion = duracion;

    }
    Media (int tipo = 2, string descripcion ="", int duracion =0, string autor =""){ //tipo 2 AUDIO
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->duracion = duracion;
        this->autor = autor;

    }

    string getInfo(){

        string contenido;
        if (tipo == 0){
           return "\nTipo: Imagen\n     _\n  n_|_|_,__    \n |===.-.===|    \n |  ((_))  |    \n '==='-'==='\n\nDescripcion: "+
           descripcion+"\nFecha: "+fecha+"\nFotografo"+autor;

        }
        if (tipo == 1){
            return "\nTipo: Video\n  _______________       \n |    .          |       \n |    :;..       |       \n |    :;;;;;.    |       \n |    ;;;:'      |       \n |    ;:'        |       \n |_______________|\n\nDescripcion"
            +descripcion+"\nFecha: "+fecha+"\nDuracion: "+to_string(duracion)+" segundos";

        }
        if (tipo == 2){
           return "\nTipo: Audio\n      ;\n      ;;\n      ;';.\n      ;  ;;\n      ;   ;;\n      ;    ;;\n      ;    ;;\n      ;   ;'\n      ;  ' \n ,;;;,; \n ;;;;;;\n `;;;;'\n\nDescripcion: "+
           descripcion+"\nDuracion: "+to_string(duracion)+"\nAutor: "+autor;
        }
        return "Noticia vacia";

    }
};


class Noticia {

protected:
    string title;
    string date;
    string reporter;


public:

    Noticia(string title, string date, string reporter){
        this->title = title;
        this->date = date;
        this->reporter = reporter;
    }

   ~Noticia(){

   }

   virtual string getInfo() = 0;

};

class NoticiaPaper: public Noticia {

private:
    string path;

public:

    NoticiaPaper(string title, string date, string reporter, string path): Noticia(title, date, reporter){
        this->path = path;
    }

    string getInfo(){
      return"Title: "+ title+"\nDate: "+date+"\nReporter: "+reporter+"\nImage Path: "+this->path+"\n";
    }

};

class NoticiaDigital: public Noticia {

private:

   vector<Media*> listMedia;

public:

    NoticiaDigital(string title, string date, string reporter, vector<Media*> listMedia): Noticia(title, date, reporter){
        this->listMedia = listMedia;
    }

   // void addMedia(Media media){
       // listMedia.emplace_back(media);

    //}

    string getInfo(){
        string listInfo;
        for (int pos = 0; pos<3; pos++){
            listInfo = listInfo + listMedia[pos]->getInfo()+"\n\n";
        }
        return "Title: "+ title+"\nDate: "+date+"\nReporter: "+reporter+"\n\nMedia: \n"+listInfo+"\n";

    }

};

class NoticiaRadio: public Noticia {

private:
    string audioURL;
public:
    NoticiaRadio(string title, string date, string reporter, string audioURL): Noticia(title, date, reporter){
        this->audioURL = audioURL;
    }
    string getInfo(){
        return "Title: "+ title+"\nDate: "+date+"\nReporter: "+reporter+"\nAudio URL: "+this->audioURL+"\n";
    }

};


int main(){

    vector<Media*> media = {new Media(0,"Imagen de un avion","03/02/2021","Carlos Rodriguez"), new Media(1,"Video del piloto derribando un caza","04/01/2022",86),
    new Media(2,"LLamada del piloto con la base de control", 21, "Ejercito de Ucrania")};

    vector<Noticia*> noticias = {new NoticiaPaper("Vaticano pide paz en Ucrania","05/03/2022","Mario Torres","C:\notice\actual\vaticano.png"),
                                 new NoticiaDigital("Piloto ucraniano derriba 15 aviones rusos","15/02/2022","Pedro Flores Brenes", media),
                                 new NoticiaRadio("Nuevo caso de corrupcion en Munucipalidad de Alajuela","05/11/2019","Carmen Castro Obando","http://radiomonumental/casodecorrupcion")};

    for (int i = 0; i<3; i++){
        cout<<noticias[i]->getInfo();
        cout<<"\n==================================================\n\n";
    }

    return 0;
}
