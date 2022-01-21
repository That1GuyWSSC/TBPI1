/*extern void readfromfileinsertme(ME array[]);
extern int insertme(ME array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia);
//extern int existeme(ME array[], int index, int ordem);
extern void printarray(ME array[], int i);
extern int menu();
extern void printartudome(ME array[]);
extern void readfromfileinsertmu(MU array[]);

*/


// new .h
extern int insertPedido(Pedido array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia);
extern void readfromfileinsertPedido(Pedido array[]);
extern void insertMobilidade(Mobilidade array[], int index, char *codigo, char *tipo, float custo, int autonomia);
extern void printarrayMobilidade(Mobilidade array[], int i);
extern void readfromfileinsertMobilidade(Mobilidade array[]);
extern int menu();
extern void printartudoPedido(Pedido array[]);