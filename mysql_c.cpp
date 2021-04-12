// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <mysql.h> 
#include <string>
using namespace std;
int q_estado;

void ingreso();
void consulta();
void actualizar();
void eliminar();
void ingresom();
void consultam();
void actualizarm();
void eliminarm();


int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);
    if (conectar) {
        int op;
        //cout << "Conexion Exitosa"<<endl;
        cout << "1. Ingresar Datos Productos" << endl;
        cout << "2. Consultar Datos Productos" << endl;
        cout << "3. Actualizar Datos Productos" << endl;
        cout << "4. Eliminar Datos Productos" << endl;
        cout << "5. Ingresar Datos Marcas" << endl;
        cout << "6. Consultar Datos Marcas" << endl;
        cout << "7. Actualizar Datos Marcas" << endl;
        cout << "8. Eliminar Datos Marcas" << endl;
        cout << "Seleccione su opción" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            void ingreso();
            break;
        case 2:
            system("cls");
            void consulta();
            break;
        case 3:
            system("cls");
            void actualizar();
            break;
        case 4:
            system("cls");
            void eliminar();
            break;
        case 5:
            system("cls");
            void ingresom();
            break;
        case 6:
            system("cls");
            void consultam();
            break;
        case 7:
            system("cls");
            void actualizarm();
            break;
        case 8:
            system("cls");
            void eliminarm();
            break;
        default:
            break;
        }

    }else {
    cout << "Error al conectar" << endl;
        }
    
        system("pause");
        return 0;
    }

void ingreso() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string producto, idmarca, Descripcion, precio_costo, precio_venta, existencia, fecha_ingreso = "now()";
    cout << "Ingrese Producto: ";
    getline(cin, producto);
    //system("pause");
    cout << "Ingrese IDmarca: ";
    cin >> idmarca;
    //system("pause");
    cout << "Ingrese Descripcion: ";
    getline(cin, Descripcion);
    //system("pause");
    cout << "Ingrese Precio_costo: ";
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingrese Precio_venta: ";
    cin >> precio_venta;
    //system("pause");
    cout << "Ingrese Existencias: ";
    cin >> existencia;
    //system("pause");

    string insert = "insert into productos(producto,idmarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "," + idmarca + "," + Descripcion + "," + precio_costo + "," + precio_venta + "," + existencia + "," + fecha_ingreso + "')"; //INSERT INTO `db_kardex`.`productos` (`producto`) VALUES('"+producto+"');
    const char* i = insert.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso Exitoso" << endl;
    }
    else {
        cout << "Error al ingresar" << endl;
    }

}

void consulta(){
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string consulta = "selelct * from productos";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "," << fila[1];
        }
    }
    else {
        cout << "Error al consultar" << endl;
    }


}

void actualizar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string num,productoaux, idmarcaaux, Descripcionaux, precio_costoaux, precio_ventaaux, existenciaaux, fecha_ingresoaux = "now()";
        cout << "Ingrese ID del producto que desea actualizar: ";
        cin >> num;
        system("cls");

        cout << "Ingrese Producto: ";
        getline(cin, productoaux);
        //system("pause");
        cout << "Ingrese IDmarca: ";
        cin >> idmarcaaux;
        //system("pause");
        cout << "Ingrese Descripcion: ";
        getline(cin, Descripcionaux);
        //system("pause");
        cout << "Ingrese Precio_costo: ";
        cin >> precio_costoaux;
        cin.ignore();
        cout << "Ingrese Precio_venta: ";
        cin >> precio_ventaaux;
        //system("pause");
        cout << "Ingrese Existencias: ";
        cin >> existenciaaux;
        //system("pause");

        string actualizar = "update productos set idproducto="+num+" (producto,idmarca,Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + productoaux + "," + idmarcaaux + "," + Descripcionaux + "," + precio_costoaux + "," + precio_ventaaux + "," + existenciaaux + "," + fecha_ingresoaux + "')";
        const char* c = actualizar.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            cout << "Actualizacion finalizada" << endl;
            }else {
            cout << "Error al actualizar" << endl;
        }


}
void eliminar() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string num;
    cout << "Ingrese ID del producto que desea eliminar: ";
    cin >> num;
    system("cls");

    string eliminar = "delete from productos where idproducto=" + num + "";
    const char* c = eliminar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Eliminacion finalizada" << endl;
    }
    else {
        cout << "Error al eliminar" << endl;
    }
}



void ingresom() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string marca;
    cout << "Ingrese Marca: ";
    getline(cin, marca);
    //system("pause");
   
    string insert = "insert into marcas(marca) values ('" + marca + "')"; 
    const char* i = insert.c_str();
    q_estado = mysql_query(conectar, i);
    if (!q_estado) {
        cout << "Ingreso Exitoso" << endl;
    }
    else {
        cout << "Error al ingresar" << endl;
    }

}

void consultam() {
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string consulta = "selelct * from marcas";
    const char* c = consulta.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        while (fila = mysql_fetch_row(resultado)) {
            cout << fila[0] << "," << fila[1];
        }
    }
    else {
        cout << "Error al consultar" << endl;
    }


}

void actualizarm() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);

    string num, marca;
    cout << "Ingrese ID de la marca que desea actualizar: ";
    cin >> num;
    system("cls");

    cout << "Ingrese Marca: ";
    getline(cin, marca);
    //system("pause");

    string actualizar = "update marcas set idmarca=" + num + " (marca) values ('" + marca + "')";
    const char* c = actualizar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Actualizacion finalizada" << endl;
    }
    else {
        cout << "Error al actualizar" << endl;
    }


}
void eliminarm() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "umg$2019", "db_kardex", 3306, NULL, 0);


    string num;
    cout << "Ingrese ID de la marca que desea eliminar: ";
    cin >> num;
    system("cls");

    string eliminar = "delete from marcas where idmarca=" + num + "";
    const char* c = eliminar.c_str();
    q_estado = mysql_query(conectar, c);
    if (!q_estado) {
        cout << "Eliminacion finalizada" << endl;
    }
    else {
        cout << "Error al eliminar" << endl;
    }
}
