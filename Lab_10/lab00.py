def funcaoFx(valorProd, per, valorPrest, juros):
    pote = (1 + juros)**per
    return valorProd*pote - valorPrest*((pote - 1)/juros)

def derivadaFx(valorProd, per, valorPrest, juros):
    pote1 = (1+juros)**per
    pote2 = (1+juros)**(per-1)
    aux = valorProd*per*pote2
    aux = aux - valorPrest*per*pote2/juros
    aux = aux + valorPrest*(pote1 - 1)/(juros*juros)
    return aux

def proxSuficiente(valorProd, per, valorPrest, juros):
    EPSILON = 0.000000001
    EPSILON = EPSILON/100
    valorFun = funcaoFx(valorProd, per, valorPrest, juros)
    if(valorFun <= EPSILON and valorFun >= -1 * EPSILON ):
        return True
    else:
        return False

def achaJuros(valorProd, per, valorPrest):
    contador = 0
    juros = 1.0
    while( not proxSuficiente(valorProd, per, valorPrest, juros) ):
        contador = contador + 1
        for i in range(0,1000):
            fx = funcaoFx(valorProd, per, valorPrest, juros)
            dfx = derivadaFx(valorProd, per, valorPrest, juros)
            juros = juros - fx/dfx
    print("O numero de iteracoes foi " + str(contador*1000))
    return juros

def achaValorPrest(valorProd, per, juros):
    pote = (1+juros)**per
    return pote * valorProd * juros/(pote - 1)

def achaValorAplicado(mont, per, juros):
    return mont * (1 + juros)**per

def achaValorInvestido(mont, per, juros, apli):
    pote = (1 + juros)**per
    return mont*pote + apli * (pote - 1)/juros

print(achaJuros(2600, 4, 750))
print(achaValorPrest(2600, 4, 0.0598))
print(achaValorPrest(2600, 4, achaJuros(2600, 4, 750)))
print(achaValorAplicado(2600, 4, 0.03))
print(achaValorInvestido(2600, 4, 0.03, 100))
