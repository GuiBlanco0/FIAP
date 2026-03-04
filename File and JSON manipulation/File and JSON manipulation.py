open("teste.txt", "w").close()  # limpa o arquivo
with open("teste.txt", "a") as arquivo:
    for i in range(1, 10):
        arquivo.write(f"Linha {i}\n")
