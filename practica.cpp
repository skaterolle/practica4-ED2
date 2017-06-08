#include <iostream>
#include <cstdlib>
#include "grafo.h"
#include "conjunto.h"
#include <queue>
#include <sstream>
#include <map>


using namespace std;

//Ejercicio 1
template <typename T>
T verticeMaxCoste(const Grafo<T, float>& G)
{
    /*map<T,float>coste;
    T v;
    */
   if ( !G.esVacio())
    {
        int n = G.numVertices();
        map<T , float> Tarra;
        Conjunto< Vertice<T> > c = G.vertices();
        Conjunto<Arista<T, float> > ari = G.aristas();
        while(!c.esVacio())
        {
            Tarra[c.quitar().getObj()]=0;
        }
        while(!ari.esVacio())
        {
            Arista<T, float> d =ari.quitar();
            //T v = d.getOrigen();
            Tarra[d.getOrigen()] += d.getEtiqueta();
        }
        int maxi = 0;
        T v;
        for ( typename map<T,float>::iterator it = Tarra.begin(); it != Tarra.end(); it++)
        {
            if(it->second > maxi)
            {
                maxi = it->second;
                v = it->first;
            }
        }
        return v;
    }
}


//Ejercicio 2
template <typename T, typename U>
void inaccesibles(const Grafo<T, U>& G)
{
     if(!G.esVacio())
    {
        int n = G.numVertices();
        map<T , int> Tarra;
        Conjunto< Vertice<T> > adya;
        Conjunto< Vertice<T> > solu;
        Conjunto< Vertice<T> > c = G.vertices();
        Conjunto<Arista<T, float> > ari = G.aristas();
        while(!c.esVacio())
        {
            Tarra[c.quitar().getObj()]=0;
        }
        while(!ari.esVacio())
        {
            Arista<T, float> d =ari.quitar();
            //T v = d.getOrigen();
            adya = G.antecesores(d.getOrigen());
            Vertice<T> ayu(adya.quitar());
            if(adya.esVacio())
                solu = ayu.getObj();
        }
    }
}


// Ejercicio 3
template <typename T, typename U>
bool caminoEntreDos(const Grafo<T, U>& G, const T& vo, const T& vd)
{
    queue< T > abiertos;
    Conjunto< Vertice<T> > adya;
    typedef map<T , bool> Tarra;
    Tarra diccio;
    Conjunto< Vertice<T> > c = G.vertices();
    abiertos.push(vo);
    bool encontrado = false;
    while (!c.esVacio())
    {
        diccio[ c.quitar().getObj() ] = false;
    }
    while( !abiertos.empty() && !encontrado)
    {
        diccio[abiertos.front()] = true;
        adya = G.adyacentes(abiertos.front());
        abiertos.pop();
        while(!adya.esVacio())
        {
            Vertice<T> ayu(adya.quitar());
            if(diccio[ayu.getObj()] == false)
                abiertos.push(ayu.getObj());
        }
    }
    return diccio[vd];
}


//Ejercicio 4
template <typename T>
void caminosAcotados(const Grafo<T, float>& G, const T& u, float maxCoste)
{
//    void caminosAcotados(G, u, maxCoste, acarreo, camino);
}
//void caminosAcotados(const Grafo<T, float>& G, const T& u, float maxCoste, float acarreo, string camino)
//{

//}


//Ejercicio 5
template <typename T, typename U>
T outConectado(const Grafo<T, U>& G)
{
    if(!G.esVacio())
    {
        int n = G.numVertices();
        map<T , int> Tarra;
        Conjunto< Vertice<T> > c = G.vertices();
        Conjunto<Arista<T, float> > ari = G.aristas();
        while(!c.esVacio())
        {
            Tarra[c.quitar().getObj()]=0;
        }
        while(!ari.esVacio())
        {
            Arista<T, float> d =ari.quitar();
            //T v = d.getOrigen();
            Tarra[d.getOrigen()] = Tarra[d.getOrigen()] + 1;
            Tarra[d.getDestino()] = Tarra[d.getDestino()] - 1;
        }
        int cuenta = 0;
        for ( typename map<T,int>::iterator it = Tarra.begin(); it != Tarra.end(); it++)
        {
            if((it->second > 0) && (it->second > cuenta))
            {
                cuenta = it->second;
            }
        }
        for ( typename map<T,int>::iterator it = Tarra.begin(); it != Tarra.end(); it++)
        {
            if((it->second == cuenta))
            {
                return it->first;
            }
        }
    }
}


//Ejercicio 6
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U>& G, const T& v)
{
    if(!G.esVacio())
    {
        map<T , bool> Tarra;

        Conjunto< Vertice<T> > c = G.vertices();
        while(!c.esVacio())
        {
            Tarra[c.quitar().getObj()] = false;
        }
        recorrido_profundidad(G, v, Tarra);
    }

}
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U>& G, const T& v,  map<T,bool> &Tarra)
{
        cout<<v<<"--";
        Conjunto< Vertice<T> > adya;
        adya = G.adyacentes(v);
        Tarra[v]=true;
        while(!adya.esVacio())
        {
            T ayu(adya.quitar().getObj());
            if(!Tarra[ayu])
                recorrido_profundidad(G, ayu, Tarra);
        }

}

//********************************************************************//
int main()
{
    system("color 3F");
    Grafo<int, float> G(7);
    for (int i = 1; i <= 7; i++) G.insertarVertice(i);
    G.insertarArista(2, 1, 4);
    G.insertarArista(1, 3, 3);
    G.insertarArista(1, 4, 2);
    G.insertarArista(1, 6, 1);
    G.insertarArista(6, 4, 5);
    G.insertarArista(4, 7, 3);
    G.insertarArista(5, 1, 6);

    Grafo<string, float> H(7);
    H.insertarVertice("Huelva"); H.insertarVertice("Lepe"); H.insertarVertice("Niebla");
    H.insertarVertice("Mazagon"); H.insertarVertice("Almonte"); H.insertarVertice("Aljaraque");
    H.insertarVertice("Matalascañas");
    H.insertarArista("Lepe", "Huelva", 4);
    H.insertarArista("Huelva", "Niebla", 3);
    H.insertarArista("Huelva", "Mazagon", 2);
    H.insertarArista("Huelva", "Aljaraque", 1);
    H.insertarArista("Mazagon", "Almonte", 3);
    H.insertarArista("Mazagon", "Matalascañas", 4);
    H.insertarArista("Aljaraque", "Mazagon", 5);
    H.insertarArista("Almonte", "Huelva", 6);

    cout << " Vertice de maximo coste en G: " << verticeMaxCoste(G) << endl;
    cout << " Vertice de maximo coste en H: " << verticeMaxCoste(H) << endl;

    cout << endl << " Vertices inaccesibles en G: ";
    inaccesibles(G);

    cout << endl << " Camino entre Dos en H de Lepe a Almonte: ";
    cout << (caminoEntreDos(H, string("Lepe"), string("Almonte")) ? " SI " : " NO ") << endl;
    cout << endl << " Camino entre Dos en H de Aljaraque a Lepe: ";
    cout << (caminoEntreDos(H, string("Aljaraque"), string("Lepe")) ? " SI " : " NO ") << endl;
/*
    cout << endl << " Caminos acotados en G a coste 9 desde el vertice 2:" << endl;
    caminosAcotados(G, 2, 9);
*/

    cout << endl << endl << " Vertice outConectado en G: " << outConectado(G);
    cout << endl << " Vertice outConectado en H: " << outConectado(H) << endl;



    cout << endl << endl << " Recorrido en profundidad de H desde el vertice Huelva:  ";
    recorrido_profundidad(H, string("Huelva"));
    cout << endl << endl;


    system("PAUSE");
    return EXIT_SUCCESS;
}