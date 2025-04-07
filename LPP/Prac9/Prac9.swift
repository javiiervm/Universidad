import Foundation

func prefijos(prefijo: String, palabras: [String]) -> [Bool] {
    if palabras.count == 0 {
        return []
    } else {
        var resultado: [Bool] = []
        let palabra = palabras.first ?? ""
        resultado.append(palabra.hasPrefix(prefijo))
        let nuevaLista: [String] = Array(palabras.dropFirst())
        return resultado + prefijos(prefijo: prefijo, palabras: nuevaLista)
    }
}

let array = ["anterior", "antígona", "antena"]
let prefijo = "ante"
print("\n******\n2a) Función prefijos(prefijo:palabras:)\n******")
print(prefijos(prefijo: prefijo, palabras: array))
// Imprime: [true, false, true]

func parejaMayorParImpar(numeros: [Int]) -> (Int, Int) {
    if numeros.count == 0 {
        return (0, 0)
    } else {
        let numero = numeros[0]
        if numero % 2 == 0 {
            let pareja: (Int, Int) = parejaMayorParImpar(numeros: Array(numeros.dropFirst()))
            if numero > pareja.1 {
                return (pareja.0, numero)
            } else {
                return pareja
            }
        } else {
            let pareja: (Int, Int) = parejaMayorParImpar(numeros: Array(numeros.dropFirst()))
            if numero > pareja.0 {
                return (numero, pareja.1)
            } else {
                return pareja
            }
        }
    }
}

let numeros = [10, 201, 12, 103, 204, 2]
print("\n******\n2b) Función parejaMayorParImpar(numeros:)\n******")
print(parejaMayorParImpar(numeros: numeros))
// Imprime: (201, 204)

func compruebaParejas(listaEnteros: [Int], fun: (Int) -> Int) -> [(Int, Int)] {
    if listaEnteros.count == 0 {
        return []
    } else {
        
    }
}

func cuadrado(x: Int) -> Int {
   return x * x
}
print(compruebaParejas([2, 4, 16, 5, 10, 100, 105], funcion: cuadrado))
// Imprime [(2,4), (4,16), (10,100)]



