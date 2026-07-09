def ordenar(lista):
    a = lista.copy()
    n = len(a)
    for i in range(n):
        menor = i
        for j in range(i+1, n):
            if a[j] < a[menor]:
                menor = j
        a[i], a[menor] = a[menor], a[i]
    return a

def buscar(lista, valor):
    inicio = 0
    fin = len(lista) - 1
    while inicio <= fin:
        medio = (inicio + fin) // 2
        if lista[medio] == valor:
            return medio
        elif lista[medio] < valor:
            inicio = medio + 1
        else:
            fin = medio - 1
    return -1  # no encontrado

edades = [75, 35, 12, 15, 5, 14, 21]

edades_ordenadas = ordenar(edades)
print("Lista ordenada:", edades_ordenadas)

posicion = buscar(edades_ordenadas, 15)
print("La edad 15 está en la posición:", posicion)
edades = [75, 35, 12, 15, 5, 14, 21]

edades_ordenadas = ordenar(edades)
print("Lista ordenada:", edades_ordenadas)

posicion = buscar(edades_ordenadas, 15)
print("La edad 15 está en la posición:", posicion)