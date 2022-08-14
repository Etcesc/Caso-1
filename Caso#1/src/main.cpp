#include <iostream>
using namespace std;
 
#define Vertc 7 // cantidad de vertices en el mapa
 
void solucion(int color[]);
   
bool verif(int vertx, bool mapa[Vertc][Vertc],
            int color[], int vertCol)
{
    for(int cont = 0; cont < Vertc; cont++)
        if (mapa[vertx][cont] && vertCol == color[cont])
            return false;
             
    return true;
}
 
// funcion recursiva para resolver el problema de n colores
bool colorearUtil(bool mapa[Vertc][Vertc], int colorAmnt, int color[], int vertx)
{   
    // si a todos los vertices se les asigna un color: true 
    if (vertx == Vertc)
        return true;
 
    // considerar vertice vertx, intentar diferentes colores
    for(int vertCol = 1; vertCol <= colorAmnt; vertCol++)
    {
         
        // verificar asignacion de color
        if (verif(vertx, mapa, color, vertCol))
        {
            color[vertx] = vertCol;
 
            //asignar color al resto de vertices
            if (colorearUtil(mapa, colorAmnt, color, vertx + 1) == true)
                return true;
 
            // si color no funciona, removerlo
            color[vertx] = 0;
        }
    }
 
    // si no se puede asignar color, false
    return false;
}
 
bool colorear(bool mapa[Vertc][Vertc], int colorAmnt)
{
     
    int color[Vertc];
    for(int cont = 0; cont < Vertc; cont++)
        color[cont] = 0;
 
    if (colorearUtil(mapa, colorAmnt, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
 
    // imprimir solucion
    solucion(color);
    return true;
}
 
// funcion para imprimir la solucion 
void solucion(int color[])
{
    cout << "Solution exists:"
         << " The assigned colors for the solution are"
         << "\n";
    
    for(int cont = 0; cont < Vertc; cont++)
        cout << " " << color[cont] << " ";
         
    cout << "\n";
}
 
int main()
{   
    bool mapa[Vertc][Vertc] = { 
        { 1, 0, 0, 1, 0, 0, 1 },
        { 0, 1, 1, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 0, 1, 0, 0 }, 
        { 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1, 0, 1 }};
                          
    // cantidad de colores
    int colorAmnt = 4;
    colorear(mapa, colorAmnt);
    return 0;
}
