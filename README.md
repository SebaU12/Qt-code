# **Proyecto Blockchain Informe**

## **Introducción**

Vivimos en un mundo que se rige por documentos, transacciones, y registros que deben permanecer vigentes y al alcance de las personas involucradas. Todo el sistema basado en leyes y documentos debe tener alguna forma de almacenar esta información y lo hacía antes teniendo los documentos de manera física.

Con el surgimiento de la tecnología podemos almacenar grandes cantidades de información en la nube, dándoles acceso directo de la información a las personas involucradas de manera rápida. Sin embargo, existe la posibilidad de un ciberataque que perjudique esta información tan valiosa.

Para darle mayor seguridad a la información, nace Blockchain. Actualmente, su rol más conocido es el de las transacciones de criptomonedas, donde se encarga de almacenar la información de las transacciones y las muestra de manera pública.

Los usos de blockchain son ilimitados ya que nos permite mostrar información al público evitando el riesgo de que esta misma sea alterada por medios externos como podría ser un ciberataque.

Para el curso *‘Algoritmos y Estructuras de Datos’* se implementó un Blockchain que permite realizar transacciones y almacenarlas de manera segura.

## **Descripción del proyecto**

Se creó un Blockchain que nos permite almacenar la información de transacciones monetarias entre individuos de manera segura mediante el uso de un hashing llamado SHA256. 

En palabras directas y fáciles de entender, la blockchain nos brinda un nivel de seguridad mediante el uso de un hash. Un hash es simplemente una forma de encriptar información, es decir, volverla irreconocible. La forma en que el blockchain utiliza el hash es simple, cada bloque perteneciente a la cadena de bloques tiene identificador, es decir un conjunto de números y letras.

Este identificador puede ser actualizado de múltiples formas, por ejemplo cuando se hace un cambio en el bloque. Además, cada bloque tiene el identificador del bloque previo. Algo muy inteligente que se hizo es que el identificador del bloque puede ser alterado por el identificador del bloque anterior, esto quiere decir que si alguien cambiase la información del bloque 3 por ejemplo, los bloques siguientes cambiarán su identificador ya que este es dependiente del identificador del bloque previo, efectivamente invalidando las siguientes operaciones.

**¿Cómo es posible que se invaliden las operaciones?**

Para que un bloque sea tomado como válido, el identificador del mismo debe pasar por ciertos requisitos específicos, como por ejemplo que los primeros 4 números de su identificador sean 0. Al momento que se actualiza el identificador por los cambios al bloque, la validación entra y verifica que este cumpla con los requisitos. Los requisitos nunca se completarán ya que para que estos se lleven a cabo deben pasar todos los bloques por el método de hashing, que permite validarlos de nuevo.

## **Explicación de estructura de datos del blockchain**

Se escogió un double list como estructura de datos principal para el blockchain. La clase Block es donde se almacena la información de la data, el hash del mismo y el hash previo, además de tener un método que verifica si este es válido.

La estructura blockchain está definida por una lista doblemente enlazada cuyo propósito es almacenar los bloques por llegada. Se escogió esta estructura por su uso limitado de memoria y por su poca complejidad de implementación. De esta manera, debido a que la lista tiene la búsqueda y modificación de bloques con una complejidad O(n). Realizar estas operaciones aumentará el tiempo de ejecución, evitando así, “hacks” en los bloques.

<br>

# **Proof of work**

**Para empezar, primero creamos 2 bloques.**

El primero con las siguientes características:
- Emisor: Emisor1
- Receptor: Receptor1
- Amount: 100 coins

El segundo con las siguientes características:
- Emisor: Emisor2
- Receptor: Receptor2
- Amount: 200 coins

Para validar imprimimos ambos bloques y vemos que son válidos:

- Block id: 1
- Nonce: 18794
- Sender: Emisor1
- Reciever: Receptor1
- Amount: 100.000000
- Time: Thu Dec  1 00:22:47 2022	
- **Hash Value: 00009B66AA739A5E2A0D955AF96522AC6D936A8BD9371D31EB76E974E0D03A89**
- **Prev Hash: 0000000000000000000000000000000000000000000000000000000000000000**
- **Valid block: true**
<br/>
<br/>

- Block id: 2
- Nonce: 323459
- Sender: Emisor2
- Reciever: Receptor2
- Amount: 200.000000
- Time: Thu Dec  1 00:23:10 2022
- **Hash Value: 0000693600CD2A09F8D60F95C0C25772B7E0E262B54DAAD35DC972DABEA13C6A**
- **Prev Hash: 00009B66AA739A5E2A0D955AF96522AC6D936A8BD9371D31EB76E974E0D03A89**
- **Valid block: true**

<br>

## **Iniciaremos el proof of work:**

	HeiderCoin Main Menu
	1. Crear Bloque
	2. Imprimir Blockchain
	3. Proof Of Work Test
	4. Arreglar Blockchain
	5. Exportar Blockchain
	6. Salir
	Ingrese una opcion: 3
	Ingrese Bloque: 2
	Ingrese nombre para el nuevo receptor: ladron
	Desea arreglar el blockChain? (0 o 1): 0


Nos pide que insertemos el bloque que se va a modificar. 
Seleccionamos el bloque 2.
Cambiamos el receptor a otra persona. 
Si arreglamos el blockchain, el block será válido, de lo contrario las modificaciones harán que el block no sea válido.

- Block id: 1
- Nonce: 18794
- Sender: Emisor1
- Reciever: Receptor1
- Amount: 100.000000
- Time: Thu Dec  1 00:22:47 2022	
- **Hash Value: 00009B66AA739A5E2A0D955AF96522AC6D936A8BD9371D31EB76E974E0D03A89**
- **Prev Hash: 0000000000000000000000000000000000000000000000000000000000000000**
- **Valid block: true**

<br/>
<br/>

- Block id: 2
- Nonce: 323459
- Sender: Emisor2
- Reciever: Receptor2
- Amount: 200.000000
- Time: Thu Dec  1 00:23:10 2022
- **Hash Value: 0DD914585A5FD1FA0C637134A8A45F73ED03AC62D0DC6B0041CD1B60595BFCB0**
- **Prev Hash: 00009B66AA739A5E2A0D955AF96522AC6D936A8BD9371D31EB76E974E0D03A89**
- **Valid block: false**



### Por detrás, la función hace los siguiente:
Cuando nos pide el bloque, le pasamos el número del bloque que deseamos modificar, empezando por el número 1. Usa este valor en conjunto con un contador para encontrar el bloque dentro de la cadena. 
Una vez encontrado el bloque verifica dos flags dependiendo del usuario. Si se desea arreglar la cadena o no. En ambos casos se modifica el hash, sin embargo en la opción de arreglar la cadena, llama a la función mine() que calcula el hash que debería tener ese bloque para que sea válido.  

## **Conclusiones**

Se aprendió a diseñar e implementar un blockchain desde cero usando una double list y el SHA256 con la finalidad de aprender el funcionamiento y las capacidades de la misma. El proyecto nos da una visión muy amplia para el futuro y nos sirve para imaginarnos los usos futuros del blockchain.


![Blockchain gif](https://github.com/utec-aed-2022-1/proyecto-hora-de-salvar-el-curso/blob/main/image2.gif)

## Autores ✒️
| <a target="_blank">**Sebastian Lizarraga**</a> | <a target="_blank">**Fernando Guillen**</a> | <a target="_blank">**Dimael Rivas**</a> | <a target="_blank">**Sebastian Chu**</a> |
| :---: | :---:| :---:| :---:|
| ![Sebastian](https://avatars.githubusercontent.com/u/76079388?v=4) | ![Fernando](https://avatars.githubusercontent.com/u/66321787?v=3&s=150) | ![Dimael](https://avatars.githubusercontent.com/u/88595171?v=4&s=150) | ![Sebastian](https://avatars.githubusercontent.com/u/45053945?v=4)|
| <a href="https://github.com/SebaU12" target="_blank">`https://github.com/SebaU12`</a> | <a href="https://github.com/FernandoGuillenR" target="_blank">`https://github.com/FernandoGuillenR`</a> | <a href="https://github.com/artrivas" target="_blank">`https://github.com/artrivas`</a> |<a href="https://github.com/ChuSebastian" target="_blank">`https://github.com/ChuSebastian`</a> |


[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8602135&assignment_repo_type=AssignmentRepo)
