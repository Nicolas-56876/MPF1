import random

def escoger_palabra():
    palabras = ['python', 'ingenieria', 'sistemas', 'laptop', 'autonomo', 'programacion']
    return random.choice(palabras)

def mostrar_progreso(palabra, letras_adivinadas):
    progreso = [letra if letra in letras_adivinadas else '_' for letra in palabra]
    return ' '.join(progreso)

def jugar_ahorcado():
    palabra = escoger_palabra()
    letras_adivinadas = []
    intentos_restantes = 6
    juego_terminado = False

    print("¡Bienvenido al juego del ahorcado!")

    while not juego_terminado:
        print(f"\nPalabra: {mostrar_progreso(palabra, letras_adivinadas)}")
        print(f"Te quedan {intentos_restantes} intentos.")
        
        intento = input("Adivina una letra: ").lower()

        if len(intento) != 1 or not intento.isalpha():
            print("Por favor, introduce solo una letra.")
            continue

        if intento in letras_adivinadas:
            print(f"Ya adivinaste la letra {intento}. Intenta otra.")
            continue

        letras_adivinadas.append(intento)

        if intento in palabra:
            print(f"¡Bien! La letra {intento} está en la palabra.")
        else:
            intentos_restantes -= 1
            print(f"Lo siento, la letra {intento} no está en la palabra.")
        
        if all(letra in letras_adivinadas for letra in palabra):
            print(f"¡Felicidades! Adivinaste la palabra: {palabra}")
            juego_terminado = True
        elif intentos_restantes == 0:
            print(f"¡Ahorcado! La palabra era: {palabra}")
            juego_terminado = True

jugar_ahorcado()
