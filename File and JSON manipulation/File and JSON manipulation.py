open("test.txt", "w").close() # Restoring file for educational purposes
with open("test.txt", "a") as file:
    while True:
        client = input("Qual o nome do cliente a ser cadastrado? ")
        if client == "0":
            break
        
        file.write(f"{client}\n")
