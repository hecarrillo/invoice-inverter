#include<bits/stdc++.h>
#include <fstream>

using namespace std;

/**
Función dedicada a invertir cada folio.

Inputs:
  invoice[string reference]: referencia del stringa invertir.

Outputs:
  1

O(n) donde n es invoice.length;
**/
int invertInvoice (string & invoice){
  int length = invoice.length();
  for(int i = 0; i < length / 2; i++){
    char temp = invoice[i];
    invoice[i] = invoice[length-1-i];
    invoice[length-1-i] = temp;
  }
  return 1;
}

/**
Función dedicada a leer el archivo dado e invertir cada folio.

Inputs:
  filename[string]: nombre del archivo a leer.
Outputs:
  invoices[vector<string>]: Vector con los folios invertidos.

O(nm) donde n es invoice.length y m es el número de folios existentes en el archivo.
**/
vector<string> fileToArrayAndInvert(string const & filename) {
  ifstream file;
  file.open(filename);
  if(!file) {
    cout << "Error opening file";
    exit(1);
  }

  vector<string> invoices;
  string invoice;

  while (file >> invoice) {
    invertInvoice(invoice);
    invoices.push_back(invoice);
  }

  return invoices;
}

/**
Función dedicada escribir cada item del vector de invoices en un archivo .txt
con nombre filename.

Inputs:
  filename[string]: nombre del archivo a leer.
Outputs:
  invoices[vector<string>]: Vector con los folios invertidos.

O(nm) donde n es invoice.length y m es el número de folios existentes en el archivo.
**/
int writeArrayToFile (vector<string> & invoices, string const filename) {
  ofstream file(filename);

  for (string &invoice : invoices){
    file << invoice << "\n";
  }

  file.close();

  return 1;
}

/**
  Inputs: filename[string] nombre del archivo para checar su extensión
  Output: boolean -> regresa verdadero si contiene la extensión de archivo .txt
**/
bool endsWithTxt(string const & filename) {
    if (4 > filename.size()) return false;
    return filename.compare(filename.size()-4, 3, ".txt") == 0;
}

/**
Función principal: Llama a nuestro lector de archivos (fstream), donde se
realiza la inversión de cada linea de folios que existe en el archivo especificado.
Checa a su vez si tiene la extension de archivo correspondiente

Inputs:
  filename[string]: Nombre del archivo a leer. Debe ser en formato .txt
  outputFilename[string]: Nombre del archivo a escribir al final del cómputo.

Outputs:
  Un archivo con nombre outputFilename con los folios invertidos, conservando el
  orden de los folios en el archivo de entrada.
**/

int main() {
  string filename, outputFilename;

  cout << "Escribir el nombre del archivo de entrada (Debe estar en el mismo folder): ";
  cin >> filename;
  if (!endsWithTxt(filename)) filename += ".txt";

  cout << "Escribir el nombre del archivo de salida: ";
  cin >> outputFilename;
  if (!endsWithTxt(outputFilename)) outputFilename += ".txt";

  vector<string> invertedInvoices =
    fileToArrayAndInvert(filename);
  writeArrayToFile(invertedInvoices, outputFilename);
}
