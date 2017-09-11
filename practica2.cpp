#include <iostream>
#include <cstdlib>
#include <queue>
#include "arbin.h"
#include "abb.h"
#include "NoHaySiguienteMayor.h"

// Recorridos

template <typename T>
void inorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T>
void anchura(const Arbin<T>& a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
             ic = c.front();
             c.pop();
             cout << ic.observar() << " ";
             if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
             if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}


/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
//Ejercicio 1
template <typename T>
int numHojas(const Arbin<T>& a)
{
    if(!a.esVacio())
    {
        return numHojas(a, a.getRaiz());
    }
    else return 0;
}
template <typename T>
int numHojas(const Arbin<T>& b, const typename Arbin<T>::Iterador& a)
{
    if(b.subDer(a).arbolVacio() && b.subIzq(a).arbolVacio())
    {
        return 1;
    }
    else if(!b.subDer(a).arbolVacio() && b.subIzq(a).arbolVacio())
    {
        return numHojas(b, b.subDer(a));
    }
    else if(b.subDer(a).arbolVacio() && !b.subIzq(a).arbolVacio())
    {
        return numHojas(b, b.subIzq(a));
    }
    else if(!b.subDer(a).arbolVacio() && !b.subIzq(a).arbolVacio())
    {
        return (numHojas(b, b.subDer(a)) + numHojas(b, b.subIzq(a)));
    }
}

/****************************************************************************/
//Ejercicio 2
template <typename T>
Arbin<char> simetrico(const Arbin<T>& a)
{
    if(a.esVacio()) return a;
    else
    return simetrico(a, a.getRaiz());
}
template <typename T>
Arbin<char> simetrico(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if(a.subDer(r).arbolVacio() && a.subIzq(r).arbolVacio())
    {
        Arbin<char> *d = new Arbin<char>(r.observar(), Arbin<char>(), Arbin<char>());
        return (*d);
    }
    else if(!a.subDer(r).arbolVacio() && a.subIzq(r).arbolVacio())
    {
        Arbin<char> *d = new Arbin<char>(r.observar(), simetrico(a, a.subDer(r)),Arbin<char>() );
        return (*d);
    }
    else if(a.subDer(r).arbolVacio() && !a.subIzq(r).arbolVacio())
    {
        Arbin<char> *d = new Arbin<char>(r.observar(), Arbin<char>(),simetrico(a, a.subIzq(r)) );
        return (*d);
    }
    else if(!a.subDer(r).arbolVacio() && !a.subIzq(r).arbolVacio())
    {
        Arbin<char> *d = new Arbin<char>(r.observar(), simetrico(a, a.subDer(r)),simetrico(a, a.subIzq(r)) );
        return (*d);
    }
}

/****************************************************************************/
//Ejercicio 3
template<typename T>
void recorridoZigzag(const Arbin<T>& a, char sentido)
{
        recorridoZigzag(a, sentido, a.getRaiz());
}
template<typename T>
void recorridoZigzag(const Arbin<T>& a, char sentido, const typename Arbin<T>::Iterador& r)
{
    if(r.arbolVacio()!=true)
    {
        cout<< r.observar();
        if(sentido=='I')
        {
            recorridoZigzag(a,'D',a.subIzq(r));
        }
        else if(sentido=='D')
        {
            recorridoZigzag(a,'I',a.subDer(r));
        }

    }
}

/******************************************************************************/
//Ejercicio 4
template<typename T>
bool compensado(const Arbin<T>& a)
{
    return compensado(a, a.getRaiz());
}
template<typename T>
int contador(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if(r.arbolVacio()!=true)
    {
        return 1+contador(a,a.subDer(r))+contador(a, a.subIzq(r));
    }
    else
        return 0;
}
template<typename T>
bool compensado(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if(r.arbolVacio()!=true)
    {
        if(compensado(a,a.subDer(r))==true && compensado(a,a.subIzq(r))==true)
        {
            if((contador(a,a.subDer(r))-contador(a,a.subIzq(r))<-1)||(contador(a,a.subDer(r))-contador(a,a.subIzq(r)))>1)return false;
            else return true;
        }
        else return false;
    }
    return true;
}

/*****************************************************************************/
//Ejercicio 5
template<typename T>
void palabras(const Arbin<T>& a)
{
    //palabras(a, a.getRaiz());
    palabras(a, a.getRaiz()," ");
}
template<typename T>
/*void palabras(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    if (r.arbolVacio()!=true)
    {
        //cout << r.observar();
        if(!a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio())
        {
            int hojai = numHojas(a, a.subIzq(r));
           cout << r.observar();
            //hoja = numHojas(a, a.subIzq(r));
            for(int i=0; i<hojai; i++)
            {
                palabras(a, a.subIzq(r));
            }
            cout<<endl;
        }
       // cout << r.observar();
        if(!a.subDer(r).arbolVacio() && a.subIzq(r).arbolVacio())
        {
            int hojad = numHojas(a, a.subDer(r));
            cout << r.observar();
            //hoja = numHojas(a, a.subDer(r));
            for(int i=0; i<hojad; i++)
            {
                palabras(a, a.subDer(r));
            }
        }
        if(!a.subDer(r).arbolVacio() && !a.subIzq(r).arbolVacio())
        {
            cout<< r.observar();
            palabras(a, a.subIzq(r));
            cout<<endl<<r.observar();
            palabras(a, a.subDer(r));
            cout<<endl;
        }
        if(a.subDer(r).arbolVacio() && a.subIzq(r).arbolVacio())
        {
            cout << r.observar();
        }
        cout<<endl;
    }
}*/
void palabras(const Arbin<T>& a, const typename Arbin<T>::Iterador& r,string cadena)
{
    if (r.arbolVacio()!=true)
    {
        cadena = cadena + r.observar();
        palabras(a, a.subDer(r), cadena);
        palabras(a, a.subIzq(r), cadena);
        if(a.subDer(r).arbolVacio()==true && a.subIzq(r).arbolVacio()==true)
        {
            cout << cadena << endl;
        }
    }
}

/******************************************************************************/
//Ejercicio 6
template<typename T>
int siguienteMayor(const Arbin<T>& a, int n)
{
    int sm=0;
    (siguienteMayor(a, a.getRaiz(), n, sm));
    if(sm == 0)
    {
        throw(NoHaySiguienteMayor());
    }
    else
    return sm;
}
template<typename T>
void siguienteMayor(const Arbin<T>& a, const typename Arbin<T>::Iterador& r, int n, int &sm)
{
    int raiz;
   if (!r.arbolVacio())
    {
        raiz=r.observar();
        if(raiz == n)
        {
            if(!a.subDer(r).arbolVacio())
            {
                sm = minimo(a,a.subDer(r));
            }
        }
        else
        {
            if(raiz < n)
            {
                siguienteMayor(a, a.subDer(r), n, sm);
            }
            else
            {
                sm = raiz;
                siguienteMayor(a, a.subIzq(r), n, sm);
            }
        }
    }
}
template<typename T>
int minimo(const Arbin<T>& a, const typename Arbin<T>::Iterador& r)
{
    int aux = 0;
    if(!a.subIzq(r).arbolVacio())
    {
       aux = minimo(a, a.subIzq(r));
    }
    else
    {
        aux = r.observar();
    }
    return aux;
}
/******************************************************************************/
//Ejercicio 7
template<typename T>
int posicionInorden(const Arbin<T>& a, int n)
{
    int sm = 1;
    posicionInorden(a, a.getRaiz(), n, sm);
    return sm;
}
template<typename T>
void posicionInorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r, int n, int& sm)
{
    if(!r.arbolVacio() && sm != 0)
    {
        int raiz=r.observar();
        if(raiz == n)
        {
            if(!a.subIzq(r).arbolVacio())
                sm = sm + contador(a, a.subIzq(r));
        }
        else if(raiz > n)
        {
            posicionInorden(a, a.subIzq(r), n, sm);
            //sm = sm + contador(a, a.subIzq(r));
        }
        else if(raiz < n)
        {
            posicionInorden(a, a.subDer(r), n, sm);
            if(sm != 0)
                sm = 1 + sm + contador(a, a.subIzq(r));
        }
    }
    else
        sm = 0;
}
/******************************************************************************/
//Ejercicio 8


/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[])
{
    Arbin<char> A('t', Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> B('t', Arbin<char>('n', Arbin<char>(),
                                        Arbin<char>('d', Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                                         Arbin<char>())),
                       Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t', Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()),
                       Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o', Arbin<char>('r', Arbin<char>(),
                                        Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('l', Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    Arbin<int> F(2, Arbin<int>(7, Arbin<int>(2, Arbin<int>(), Arbin<int>()),
                                  Arbin<int>(6, Arbin<int>(5, Arbin<int>(), Arbin<int>()),
                                                Arbin<int>(11, Arbin<int>(), Arbin<int>()))),
                    Arbin<int>(5, Arbin<int>(),
                                  Arbin<int>(9, Arbin<int>(),
                                                  Arbin<int>(4, Arbin<int>(), Arbin<int>()))));

    ABB<int> BB6, BB7;



    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;


    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;


    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;

    // PALABRAS DE UN ARBOL //
    cout << "PALABRAS DE E:\n";
    palabras(E);
    cout << "PALABRAS DE B:\n";
    palabras(B);
    cout << endl;
    if(siguienteMayor(F, 5)==1)
        cout<<"encontrado"<<endl;
        else
            cout<< "no" << endl;
            inorden(F, F.getRaiz());

    // SIGUIENTE MAYOR
    BB6.insertar(8); BB6.insertar(3); BB6.insertar(10); BB6.insertar(1); BB6.insertar(6);
    BB6.insertar(14); BB6.insertar(4); BB6.insertar(7); BB6.insertar(13);
    try
    {
        cout << endl << "Siguiente mayor en BB6 de 5: " << siguienteMayor(BB6, 5) << endl;
        cout << "Siguiente mayor en BB6 de 8: " << siguienteMayor(BB6, 8) << endl;
        cout << "Siguiente mayor en BB6 de 13: " << siguienteMayor(BB6, 13) << endl;
        cout << "Siguiente mayor en BB6 de 14: " << siguienteMayor(BB6, 14) << endl;
    }
    catch(const NoHaySiguienteMayor& e)
    {
        cout << e.Mensaje() << endl << endl;
    }

    // POSICION INORDEN //
    BB7.insertar(5); BB7.insertar(1); BB7.insertar(3); BB7.insertar(8); BB7.insertar(6);
    cout << "Posicion Inorden en BB7 de 3: ";
    cout << posicionInorden(BB7, 3);
    cout << endl << "Posicion Inorden en BB7 de 8: ";
    cout << posicionInorden(BB7, 8);
    cout << endl << "Posicion Inorden en BB7 de 7: ";
    cout << posicionInorden(BB7, 7);
    cout << endl << endl;
/*
    // SUMA CAMINO
    cout << "Hay un camino de suma 26 en F?:";
    cout << (haySumaCamino(F, 26) ? " SI" : " NO") << endl;
    cout << "Hay un camino de suma 9 en F?:";
    cout << (haySumaCamino(F, 9) ? " SI" : " NO") << endl;
*/

    system("PAUSE");
    return 0;
}
