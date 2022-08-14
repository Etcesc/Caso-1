#include <iostream>
using namespace std;
 
#define V 5 // Cantidad de vertices en el mapa
 
void solucion(int color[]);
   
bool isSafe(int v, bool mapa[V][V],
            int color[], int c)
{
    for(int i = 0; i < V; i++)
        if (mapa[v][i] && c == color[i])
            return false;
             
    return true;
}
 
/* Funcion recursiva para resolver el problema de m colores */
bool colorearUtil(bool mapa[V][V], int n, int color[], int v)
{   
    // si a todos los vertices se les asigna un color: true 
    if (v == V)
        return true;
 
    // considerar vertice v, intentar diferentes colores
    for(int c = 1; c <= n; c++)
    {
         
        // verificar asignacion de color
        if (isSafe(v, mapa, color, c))
        {
            color[v] = c;
 
            //asignar color al resto de vertices
            if (colorearUtil(
                mapa, n, color, v + 1) == true)
                return true;
 
            // si color no funciona, removerlo
            color[v] = 0;
        }
    }
 
    // si no se puede asignar color, false
    return false;
}
 
bool colorear(bool mapa[V][V], int n)
{
     
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;
 
    if (colorearUtil(mapa, n, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
 
    // Imprimir solucion
    solucion(color);
    return true;
}
 
/* funcion para imprimir la solucion */
void solucion(int color[])
{
    cout << "Solution Exists:"
         << " Following are the assigned colors"
         << "\n";
    for(int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
         
    cout << "\n";
}
 
int main()
{   
    bool mapa[V][V] = { { 1, 0, 0, 1, 0 },
                        { 0, 1, 1, 0, 1 },
                        { 0, 1, 0, 1, 0 },
                        { 1, 1, 0, 0, 1 }, 
                        { 0, 1, 1, 1, 1 }};
                          
    // Cantidad de colores
    int n = 4;
    colorear(mapa, n);
    return 0;
}