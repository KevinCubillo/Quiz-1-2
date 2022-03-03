#include <iostream>
#include <bits/stdc++.h>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

/*
Instituto Tecnologico de Costa Rica
Analisis de Algoritmos

Prof. Rodrigo Nunez, Quiz #1 y #2
Estudiante: Kevin Josue Cubillo Chacon

*/

/*Class Media. This class is used to instantiate the different types of media that
  digital news can have, such as videos, images or audios
*/
class Media{
private:
    int tipo;
    string descripcion;
    string fecha;
    string autor;
    int duracion;

public:

    Media(int tipo=0, string descripcion="", string fecha ="", string autor =""){ // type 0 IMAGE
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->autor = autor ;
    }
    Media (int tipo = 1, string descripcion ="", string fecha ="", int duracion =0){ //type 1 VIDEO
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->fecha = fecha;
        this->duracion = duracion;

    }
    Media (int tipo = 2, string descripcion ="", int duracion =0, string autor =""){ //type 2 AUDIO
        this->tipo = tipo;
        this->descripcion = descripcion;
        this->duracion = duracion;
        this->autor = autor;

    }

    string getInfo(){ // Returns the information of the media depending on the type.

        string contenido;
        if (tipo == 0){ //image
           return "\nTipo: Imagen\n     _\n  n_|_|_,__    \n |===.-.===|    \n |  ((_))  |    \n '==='-'==='\n\nDescripcion: "+
           descripcion+"\nFecha: "+fecha+"\nFotografo: "+autor;

        }
        if (tipo == 1){ //video
            return "\nTipo: Video\n  _______________       \n |    .          |       \n |    :;..       |       \n |    :;;;;;.    |       \n |    ;;;:'      |       \n |    ;:'        |       \n |_______________|\n\nDescripcion: "
            +descripcion+"\nFecha: "+fecha+"\nDuracion: "+to_string(duracion)+" segundos";

        }
        if (tipo == 2){ //audio
           return "\nTipo: Audio\n      ;\n      ;;\n      ;';.\n      ;  ;;\n      ;   ;;\n      ;    ;;\n      ;    ;;\n      ;   ;'\n      ;  ' \n ,;;;,; \n ;;;;;;\n `;;;;'\n\nDescripcion: "+
           descripcion+"\nDuracion: "+to_string(duracion)+" segundos\nAutor: "+autor;
        }
        return "Noticia vacia";

    }
};

//Class Noticia.  This class is father of  NoticiaPaper, NoticiaDigital and NoticiaRadio
class Noticia {

protected:
    string Titulo;
    string date;
    string reporter;


public:

    Noticia(string Titulo, string date, string reporter){ //constructor
        this->Titulo = Titulo;
        this->date = date;
        this->reporter = reporter;
    }

   ~Noticia(){}

   virtual string getInfo() = 0; //abstract method

};


//Class NoticiaPaper. Inherited from Noticia
class NoticiaPaper: public Noticia {

private:
    string path;

public:

    NoticiaPaper(string Titulo, string date, string reporter, string path): Noticia(Titulo, date, reporter){ //constructor
        this->path = path;
    }

    ~NoticiaPaper(){}

    string getInfo(){
      return"Titulo: "+ Titulo+"\nFecha: "+date+"\nReportero: "+reporter+"\nRuta de la imagen: "+this->path+"\n";
    }

};

//Class NoticiaDigital. Inherited from Noticia
class NoticiaDigital: public Noticia {

private:

   vector<Media*> listMedia;

public:

    NoticiaDigital(string Titulo, string date, string reporter, vector<Media*> listMedia): Noticia(Titulo, date, reporter){
        this->listMedia = listMedia;
    }

    ~NoticiaDigital(){}

    string getInfo(){
        string listInfo;
        for (int pos = 0; pos<listMedia.size(); pos++){
            listInfo = listInfo + listMedia[pos]->getInfo()+"\n\n";
        }
        return "Titulo: "+ Titulo+"\nFecha: "+date+"\nReportero: "+reporter+"\n\nMedia: \n"+listInfo;

    }

};


//Class NoticiaRadio. Inherited from Noticia
class NoticiaRadio: public Noticia {

private:
    string audioURL;
public:
    NoticiaRadio(string Titulo, string date, string reporter, string audioURL): Noticia(Titulo, date, reporter){
        this->audioURL = audioURL;
    }

    ~NoticiaRadio(){}

    string getInfo(){
        return "Titulo: "+ Titulo+"\nFecha: "+date+"\nReportero: "+reporter+"\nAudio URL: "+this->audioURL+"\n";
    }

};


int main(){

    //Media vector. Containing an image, a video and an audio
    vector<Media*> media = {new Media(0,"Imagen de un avion","03/02/2021","Carlos Rodriguez"), new Media(1,"Video del piloto derribando un caza","04/01/2022",86),
    new Media(2,"LLamada del piloto con la base de control", 21, "Ejercito de Ucrania")};

    //Noticia vector. contsins 3 types of Noticia.
    vector<Noticia*> noticias = {new NoticiaPaper("Vaticano pide paz en Ucrania","05/03/2022","Mario Torres","D:/notice/actual/vaticano.png"),
                                 new NoticiaDigital("Piloto ucraniano derriba 15 aviones rusos","15/02/2022","Pedro Flores Brenes", media),
                                 new NoticiaRadio("Nuevo caso de corrupcion en Munucipalidad de Alajuela","05/11/2019","Carmen Castro Obando","http://radiomonumental/casodecorrupcion")};



    // We go through the vector and show the information of the 3 news by polymorphism
    for (int i = 0; i<3; i++){
        cout<<noticias[i]->getInfo();
        cout<<"\n==================================================\n\n";
    }

    return 0;
}
